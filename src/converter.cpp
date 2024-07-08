#include <iostream>
#include <set>

#include "converter.h"

namespace puq {
  
MAGNITUDE_TYPE Converter::_convert_linear(const MAGNITUDE_TYPE& m1, const MAGNITUDE_TYPE& m2) {
  return (m1*dimensions1.numerical)/(m2*dimensions2.numerical);    
}

#ifdef UNITS_LOGARITHMIC

inline MAGNITUDE_TYPE _convert_B_B(const MAGNITUDE_TYPE& value, const MAGNITUDE_TYPE& exp=0) {
  return value + exp;
}
inline MAGNITUDE_TYPE _convert_B_Np(const MAGNITUDE_TYPE& value) {
  return (MAGNITUDE_TYPE)1.151277918 * value;
}
inline MAGNITUDE_TYPE _convert_Np_B(const MAGNITUDE_TYPE& value) {
  return value / (MAGNITUDE_TYPE)1.151277918;
}
inline MAGNITUDE_TYPE _convert_Ratio_B(const MAGNITUDE_TYPE& value, const MAGNITUDE_TYPE& exp) {
  return exp * nostd::log10(value);
}       
inline MAGNITUDE_TYPE _convert_B_Ratio(const MAGNITUDE_TYPE& value, const MAGNITUDE_TYPE& exp) {
  return nostd::pow((MAGNITUDE_TYPE)10, value / exp);
}
inline MAGNITUDE_TYPE _convert_Ratio_Np(const MAGNITUDE_TYPE& value, const MAGNITUDE_TYPE& exp) {
  return exp * nostd::log(value);
}       
inline MAGNITUDE_TYPE _convert_Np_Ratio(const MAGNITUDE_TYPE& value, const MAGNITUDE_TYPE& exp) {
  return nostd::exp(value / exp);
}
MAGNITUDE_TYPE Converter::_convert_logarithmic(MAGNITUDE_TYPE m) {
  const std::string s1 = baseunits1[0].unit;
  const std::string s2 = baseunits2[0].unit;
  const MAGNITUDE_TYPE n1 = dimensions1.numerical;
  const MAGNITUDE_TYPE n2 = dimensions2.numerical;
  if (s1=="Np") {          // Nepers -> Bel or Ratio
    if (s2=="B")        return _convert_Np_B(m * n1) / n2;
    else if (s2=="AR")  return _convert_Np_Ratio(m * n1, 1) / n2;
    else if (s2=="PR")  return _convert_Np_Ratio(m * n1, 0.5) / n2;
  } else if (s2=="Np") {   // Bel or Ratio -> Nepers 
    if (s1=="B")        return _convert_B_Np(m * n1) / n2;
    else if (s1=="AR")  return _convert_Ratio_Np(m * n1, 1) / n2;
    else if (s1=="PR")  return _convert_Ratio_Np(m * n1, 0.5) / n2;
  } else {
    struct pair {
      std::string first;
      std::string second;
      MAGNITUDE_PRECISION exp;
      MAGNITUDE_PRECISION conv;
    };
    const std::vector<pair> pairs_B_B = {
      {"BW","Bm",3}, {"BW","BmW",3}, {"Bm","BmW",0}, {"BV","BuV",12}, 
    };
    for (auto pair: pairs_B_B) {
      if (s1==pair.first && s2==pair.second) {         // BelX -> BelY
	return _convert_B_B(m * n1, pair.exp) / n2;
      } else if (s1==pair.second && s2==pair.first) {  // BelY -> BelX
	return _convert_B_B(m * n1, -pair.exp) / n2;
      }
    }
    const std::vector<pair> pairs_B_Ratio = {
      {"B","PR",1,1}, {"Bm","W",1,1},    {"BmW","W",1,1},    {"BW","W",1,1e-3}, {"BSIL","W",1,1e9}, {"BSWL","W",1,1e9},
      {"B","AR",2,1}, {"BV","V",2,1e-3}, {"BuV","V",2,1e3},  {"BA","A",2,1},    {"BuA","A",2,1e6},  {"BOhm","Ohm",2,1e-3}, {"BSPL","Pa",2,50}, 
    };
    for (auto pair: pairs_B_Ratio) {
      if (s1==pair.first && s1==s2) {                   // Bel -> Bel
	return _convert_B_B(m * n1) / n2;
      } else if (s1==pair.first && s2==pair.second) {   // Bel -> Ratio
	return _convert_B_Ratio(m * n1, pair.exp) / (n2 * pair.conv);
      } else if (s1==pair.second && s2==pair.first) {   // Ratio -> Bel
	return _convert_Ratio_B(m * n1 * pair.conv, pair.exp) / n2;
      }
    }
  }
  throw NoConvExcept(s1, s2);
}

#endif // UNITS_LOGARITHMIC

#ifdef UNITS_TEMPERATURES

MAGNITUDE_TYPE Converter::_convert_temperature(MAGNITUDE_TYPE m) {
  std::string s1 = baseunits1[0].unit;
  std::string s2 = baseunits2[0].unit;
  MAGNITUDE_TYPE const9div5 = 9./5.;
  MAGNITUDE_TYPE const5div9 = 5./9.;
  if (s1==s2) {
    return m;
  } else {
    m = m * dimensions1.numerical;
  }
  if (s1=="K" && s2=="Cel") {
    m = m-(MAGNITUDE_TYPE)273.15;
  } else if (s1=="K" && s2=="degF") {
    m = (m-(MAGNITUDE_TYPE)273.15)*const9div5+(MAGNITUDE_TYPE)32;
  } else if (s1=="degR" && s2=="degF") {
    m = m*const9div5-(MAGNITUDE_TYPE)459.67;
  } else if (s1=="degR" && s2=="Cel") {
    m = (m*const9div5-(MAGNITUDE_TYPE)491.67)*const5div9;
  } else if (s1=="Cel" && s2=="K") {
    m = m+(MAGNITUDE_TYPE)273.15;
  } else if (s1=="Cel" && s2=="degF") {
    m = (m*const9div5)+(MAGNITUDE_TYPE)32;
  } else if (s1=="Cel" && s2=="degR") {
    m = ((m*const9div5)+(MAGNITUDE_TYPE)491.67)*const5div9;
  } else if (s1=="degF" && s2=="K") {
    m = ((m-(MAGNITUDE_TYPE)32)*const5div9)+(MAGNITUDE_TYPE)273.15;
  } else if (s1=="degF" && s2=="Cel") {
    m = (m-(MAGNITUDE_TYPE)32)*const5div9;
  } else if (s1=="degF" && s2=="degR") {
    m = (m+(MAGNITUDE_TYPE)459.67)*const5div9;
  } else {
    throw NoConvExcept(s1, s2);
  }
  return m / dimensions2.numerical;
}

#endif // UNITS_TEMPERATURES

Converter::Converter(const BaseUnits& bu1, const BaseUnits& bu2): baseunits1(bu1), baseunits2(bu2) {
  dimensions1 = bu1.dimensions();
  dimensions2 = bu2.dimensions();
  if (dimensions1!=dimensions2)
    throw ConvDimExcept(dimensions1, dimensions2);
};

MAGNITUDE_TYPE Converter::convert(const MAGNITUDE_TYPE& m1, const MAGNITUDE_TYPE& m2) {
  //std::cout << baseunits1.to_string() << " " << baseunits2.to_string() << std::endl;
  //std::cout << std::bitset<8>((int)dimensions1.utype) << std::endl;
  //std::cout << std::bitset<8>((int)dimensions2.utype) << std::endl;
#ifdef UNITS_LOGARITHMIC
  if (((dimensions1.utype | dimensions2.utype) & Utype::LOG)==Utype::LOG) {
    if ((baseunits1.size()==1 || baseunits1.size()==2) &&
	(baseunits2.size()==1 || baseunits2.size()==2) &&
	m2==(MAGNITUDE_TYPE)1) {
      return _convert_logarithmic(m1);
    }  
  } else
#endif
#ifdef UNITS_TEMPERATURES
  if (((dimensions1.utype | dimensions2.utype) & Utype::TMP)==Utype::TMP) {
    if ((baseunits1.size()==1 || baseunits1.size()==2) &&
	(baseunits2.size()==1 || baseunits2.size()==2) &&
	m2==(MAGNITUDE_TYPE)1) {
      return _convert_temperature(m1);
    }  
  } else
#endif
  if (((dimensions1.utype & dimensions2.utype) & Utype::LIN)==Utype::LIN) {
    return _convert_linear(m1, m2);
  }
  throw NoConvExcept(baseunits1.to_string(), baseunits2.to_string());
};

}
