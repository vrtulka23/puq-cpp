#ifndef PUQ_QUANTITY_H
#define PUQ_QUANTITY_H

#include "settings.h"
#include "value/value.h"
#include "solver/solver.h"

namespace puq {
  
  class Quantity {
    void preprocess(std::string& s);
  public:
    SystemDataType* stype;
    UnitValue value;
    Quantity(SystemDataType& st=*UnitSystem::Data): stype(&st) {};
    Quantity(std::string s, SystemDataType& st=*UnitSystem::Data);
    Quantity(const UnitValue& v, SystemDataType& st=*UnitSystem::Data);
    Quantity(const MAGNITUDE_TYPE& m, SystemDataType& st=*UnitSystem::Data);
    Quantity(const MAGNITUDE_TYPE& m, const BaseUnitsList& bu, SystemDataType& st=*UnitSystem::Data);
    Quantity(const MAGNITUDE_TYPE& m, std::string s, SystemDataType& st=*UnitSystem::Data);
#ifdef MAGNITUDE_ERRORS
    Quantity(const MAGNITUDE_PRECISION& m, SystemDataType& st=*UnitSystem::Data);
    Quantity(const MAGNITUDE_PRECISION& m, const BaseUnitsList& bu, SystemDataType& st=*UnitSystem::Data);
    Quantity(const MAGNITUDE_PRECISION& m, std::string s, SystemDataType& st=*UnitSystem::Data);
    Quantity(const MAGNITUDE_PRECISION& m, const MAGNITUDE_PRECISION& e, SystemDataType& st=*UnitSystem::Data);
    Quantity(const MAGNITUDE_PRECISION& m, const MAGNITUDE_PRECISION& e, const BaseUnitsList& bu, SystemDataType& st=*UnitSystem::Data);
    Quantity(const MAGNITUDE_PRECISION& m, const MAGNITUDE_PRECISION& e, std::string s, SystemDataType& st=*UnitSystem::Data);
#endif
    std::string to_string(int precision=std::cout.precision());
    friend Quantity operator+(Quantity& q1, Quantity& q2);
    friend Quantity operator-(Quantity& q1, Quantity& q2);
    friend Quantity operator*(Quantity& q1, Quantity& q2);
    friend Quantity operator/(Quantity& q1, Quantity& q2);
    void operator+=(Quantity& q);
    void operator-=(Quantity& q);
    void operator*=(Quantity& q);
    void operator/=(Quantity& q);
    Quantity convert(const Quantity& q) const;
    Quantity convert(const std::string& s) const;
    Quantity convert(const std::string& s, SystemDataType& st, const std::string& q = "") const;
    Quantity convert(const UnitValue& uv) const;
    Quantity convert(const UnitValue& uv, SystemDataType& st, const std::string& q = "") const;
  };
  
  class UnitSystemExcept: public std::exception {
  private:
    std::string message;
  public:
    UnitSystemExcept(std::string m) : message(m) {}
    UnitSystemExcept(const Quantity* q1, const Quantity* q2) {
      std::stringstream ss;
      ss << "Incompatible unit systems: ";
      ss << q1->stype;
      ss << " != ";
      ss << q2->stype;
      ss << std::endl;
      message = ss.str();
    }
    const char * what () const noexcept override {
      return message.c_str();
    }
  };
  
  
}

#endif // PUQ_QUANTITY_H
