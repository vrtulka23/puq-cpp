#include <gtest/gtest.h>

#include "../src/value/value.h"
#include "../src/converter.h"

TEST(UnitValue, Initialization) {

  puq::UnitValue value;
  
  value = {3.34e3,{{"k","m",-1}}};           // list initialization
  EXPECT_EQ(value.to_string(), "3340*km-1");

  value = puq::UnitValue(3.34e3,"km-1");          // assigning UnitValue
  EXPECT_EQ(value.to_string(), "3340*km-1");
		    
  puq::BaseUnits bu("km-1/s2");
  value = puq::UnitValue(3, bu);                  // from BaseUnits
  EXPECT_EQ(value.to_string(), "3*km-1*s-2");

  value = puq::UnitValue("3*km/s");               // from a string
  EXPECT_EQ(value.to_string(), "3*km*s-1");

  puq::Dimensions dim(23,{1,2,3,4,0,0,0,0});
  value = puq::UnitValue(2, dim);
  EXPECT_EQ(value.to_string(), "46*m*g2*s3*K4");
 
}

#ifdef EXPONENT_FRACTIONS

TEST(UnitValue, InitializationFractions) {
  
  puq::UnitValue value1 = {3.34e3,{{"k","m",-1,2}}};
  EXPECT_EQ(value1.to_string(), "3340*km-1:2");

  puq::UnitValue value2(3.34e3,"km-1:2");
  EXPECT_EQ(value2.to_string(), "3340*km-1:2");

  puq::BaseUnits bu("km-1:2/s2");
  puq::UnitValue value3(3, bu);
  EXPECT_EQ(value3.to_string(), "3*km-1:2*s-2");
  
}

#endif

#ifdef MAGNITUDE_ERRORS

TEST(UnitValue, InitializationErrors) {

  puq::UnitValue v = puq::UnitValue({1.23,0.01},"km3");  // magnitude, errors and dimensions
  EXPECT_EQ(v.to_string(), "1.230(10)*km3");

  v = puq::UnitValue({1.23,0.01},"2*km3");          // magnitude, errors and dimensions with a number
  EXPECT_EQ(v.to_string(), "2.460(20)*km3");

  v = puq::UnitValue("3.40(10)*km3");               // unit expression
  EXPECT_EQ(v.to_string(), "3.40(10)*km3");
}

#endif

TEST(UnitValue, UnitConversion) {

  puq::UnitValue v1, v2, v3;

  v1 = puq::UnitValue("9*cm2");
  v2 = puq::UnitValue("3*m2");
  v3 = v1.convert(v2);          // conversion using UnitValue
  EXPECT_EQ(v3.to_string(), "0.0003*m2");

  puq::BaseUnits bu("m2");
  v1 = puq::UnitValue("4*cm2");
  v2 = v1.convert(bu);          // conversion using BaseUnits
  EXPECT_EQ(v2.to_string(), "0.0004*m2");  

  v1 = puq::UnitValue("4*cm2");
  v2 = v1.convert("2*m2");      // conversion using an expression
  EXPECT_EQ(v2.to_string(), "0.0002*m2");  

}

TEST(UnitValue, ArithmeticsAdd) {

  puq::UnitValue q1,q2,q3;

  q1 = puq::UnitValue(6,"cm");       // same units
  q2 = puq::UnitValue(3,"cm");
  q3 = q1 + q2;
  EXPECT_EQ(q3.to_string(), "9*cm");
  q1 += q2;
  EXPECT_EQ(q1.to_string(), "9*cm");

  q1 = puq::UnitValue(6,"cm2/s2");   // same dimensions
  q2 = puq::UnitValue(3,"m2/s2");
  q3 = q1 + q2;
  EXPECT_EQ(q3.to_string(), "30006*cm2*s-2");
  q1 += q2;
  EXPECT_EQ(q1.to_string(), "30006*cm2*s-2");  
  
  q3 = puq::UnitValue(3,"cm2");      // different units
  EXPECT_THROW(q1+q3,  puq::ConvDimExcept);
  
}

TEST(UnitValue, ArithmeticsSubtract) {

  puq::UnitValue q1,q2,q3;

  q1 = puq::UnitValue(6,"cm");       // same units
  q2 = puq::UnitValue(3,"cm");
  q3 = q1 - q2;
  EXPECT_EQ(q3.to_string(), "3*cm");
  q1 -= q2;
  EXPECT_EQ(q1.to_string(), "3*cm");

  q1 = puq::UnitValue(6,"m2/s2");    // same dimensions
  q2 = puq::UnitValue(3,"cm2/s2");
  q3 = q1 - q2;
  EXPECT_EQ(q3.to_string(), "5.9997*m2*s-2");
  q1 -= q2;
  EXPECT_EQ(q1.to_string(), "5.9997*m2*s-2");
  
  q3 = puq::UnitValue(3,"cm2");      // different units
  EXPECT_THROW(q1-q3,  puq::ConvDimExcept);
  
}

TEST(UnitValue, ArithmeticsMultiply) {

  puq::UnitValue q1,q2,q3;

  q1 = puq::UnitValue(6,"cm3");
  q2 = puq::UnitValue(3,"g2");
  q3 = q1 * q2;
  EXPECT_EQ(q3.to_string(), "18*cm3*g2");
  q1 *= q2;
  EXPECT_EQ(q1.to_string(), "18*cm3*g2");
  
}

TEST(UnitValue, ArithmeticsDivide) {

  puq::UnitValue q1,q2,q3;
  
  q1 = puq::UnitValue(6,"cm3");
  q2 = puq::UnitValue(3,"g2");
  q3 = q1 / q2;
  EXPECT_EQ(q3.to_string(), "2*cm3*g-2");
  q1 /= q2;
  EXPECT_EQ(q1.to_string(), "2*cm3*g-2");  

}

#ifdef UNITS_LOGARITHMIC

TEST(UnitValue, ArithmeticsLog) {

  puq::UnitValue q1,q2,q3;

  // addition of same units
  q1 = puq::UnitValue(1,"dB");     
  q2 = puq::UnitValue(2,"dB");
  q3 = q1 + q2;
  EXPECT_EQ(q3.to_string(), "4.53902*dB");
  q1 += q2;
  EXPECT_EQ(q1.to_string(), "4.53902*dB");

  // addition with different symbols, conversion
  q1 = puq::UnitValue(20,"dBm");     
  q2 = puq::UnitValue(23,"dBmW");
  q3 = q1 + q2;
  EXPECT_EQ(q3.to_string(), "24.7643*dBm");
  q1 += q2;
  EXPECT_EQ(q1.to_string(), "24.7643*dBm");
  
  // addition of different units throws an error
  q1 = puq::UnitValue(20,"dBW");     
  q2 = puq::UnitValue(23,"dBA");
  EXPECT_THROW(q1+q2,  puq::ConvDimExcept);
  
  // subtraction
  q1 = puq::UnitValue(87,"dBA");     
  q2 = puq::UnitValue(83,"dBA");
  q3 = q1 - q2;
  EXPECT_EQ(q3.to_string(), "84.7952*dBA");
  q1 -= q2;
  EXPECT_EQ(q1.to_string(), "84.7952*dBA");
  
}

#endif
