#include <gtest/gtest.h>

#include "../src/quantity.h"
#include "../src/converter.h"

TEST(Quantity, Initialization) {

  puq::Quantity q;                        // default initialization
  EXPECT_EQ(q.to_string(), "1");
  
  q = puq::Quantity(1.23);                // magnitude
  EXPECT_EQ(q.to_string(), "1.23");

  q = puq::Quantity(1.2,{{"k","m",3}});   // magnitude and dimensions
  EXPECT_EQ(q.to_string(), "1.2*km3");
  
  puq::UnitValue uv(1.2,{{"k","m",3}});
  q = puq::Quantity(uv);                  // UnitValue
  EXPECT_EQ(q.to_string(), "1.2*km3");

  q = puq::Quantity("23.34*g/cm3");       // from a unit expression
  EXPECT_EQ(q.to_string(), "23.34*g*cm-3");
  
  q = puq::Quantity(1.23,"g/cm3");        // magnitude and a unit expression
  EXPECT_EQ(q.to_string(), "1.23*g*cm-3");

  q = puq::Quantity(1.23,"2*km3");        // magnitude and a unit expression with a number
  EXPECT_EQ(q.to_string(), "2.46*km3");
  
}

#ifdef MAGNITUDE_ERRORS

TEST(Quantity, InitializationErrors) {

  puq::Quantity q(1.23,0.01);             // magnitudes with errors
  EXPECT_EQ(q.to_string(), "1.230(10)");

  q = puq::Quantity(1.23,0.01,"km3");     // magnitude, errors and dimensions
  EXPECT_EQ(q.to_string(), "1.230(10)*km3");

  q = puq::Quantity(1.23,0.01,"2*km3");   // magnitude, errors and dimensions with a number
  EXPECT_EQ(q.to_string(), "2.460(20)*km3");

  q = puq::Quantity("3.40(10)*km3");      // unit expression
  EXPECT_EQ(q.to_string(), "3.40(10)*km3");
}

#endif

#ifdef MAGNITUDE_ARRAYS

TEST(Quantity, InitializationArrays) {

  puq::Quantity q("{2,3.4,5e6}*km/s");                 // unit expression
  EXPECT_EQ(q.to_string(), "{2, 3.4, ...}*km*s-1");

  q = puq::Quantity(puq::Array({2,3.4,5e6}),"km2");    // magnitudes and units
  EXPECT_EQ(q.to_string(), "{2, 3.4, ...}*km2");

}

#endif

TEST(Quantity, UnitConversion) {

  puq::Quantity q;

  q = puq::Quantity(6,"cm").convert("km");
  EXPECT_EQ(q.to_string(), "6e-05*km");
  
  q = puq::Quantity(1,"au").convert("km");
  EXPECT_EQ(q.to_string(), "1.49598e+08*km");

}

TEST(Quantity, ArithmeticsAdd) {

  puq::Quantity q1,q2,q3;

  q1 = puq::Quantity(6,"cm");   // same units
  q2 = puq::Quantity(3,"cm");
  q3 = q1 + q2;
  EXPECT_EQ(q3.to_string(), "9*cm");
  q1 += q2;
  EXPECT_EQ(q1.to_string(), "9*cm");

  q3 = puq::Quantity(3,"cm2");  // different units
  EXPECT_THROW(q1+q3,  puq::ConvDimExcept);
  
}

TEST(Quantity, ArithmeticsSubtract) {

  puq::Quantity q1,q2,q3;

  q1 = puq::Quantity(6,"cm");
  q2 = puq::Quantity(3,"cm");
  q3 = q1 - q2;
  EXPECT_EQ(q3.to_string(), "3*cm");
  q1 -= q2;
  EXPECT_EQ(q1.to_string(), "3*cm");

  q3 = puq::Quantity(3,"cm2");
  EXPECT_THROW(q1-q3,  puq::ConvDimExcept);
  
}

TEST(Quantity, ArithmeticsMultiply) {

  puq::Quantity q1,q2,q3;

  q1 = puq::Quantity(6,"cm3");
  q2 = puq::Quantity(3,"g2");
  q3 = q1 * q2;
  EXPECT_EQ(q3.to_string(), "18*cm3*g2");
  q1 *= q2;
  EXPECT_EQ(q1.to_string(), "18*cm3*g2");
}

TEST(Quantity, ArithmeticsDivide) {

  puq::Quantity q1,q2,q3;
  
  q1 = puq::Quantity(6,"cm3");
  q2 = puq::Quantity(3,"g2");
  q3 = q1 / q2;
  EXPECT_EQ(q3.to_string(), "2*cm3*g-2");
  q1 /= q2;
  EXPECT_EQ(q1.to_string(), "2*cm3*g-2");  

}

#ifdef UNIT_SYSTEM_CGS

TEST(Quantity, UnitSystemDirect) {

  puq::Quantity q1, q2;
  
  q1 = puq::Quantity(34,"statA",puq::UnitSystem::ESU);  // explicitely state the unit system
  q2 = q1.convert("Fr/ms");
  EXPECT_EQ(q2.to_string(), "0.034*Fr*ms-1");

  q2 = puq::Quantity(2,"A");
  EXPECT_THROW(q1+q2,  puq::UnitSystemExcept);
  
}

TEST(Quantity, UnitSystemEnvironment) {

  puq::UnitSystem us = puq::UnitSystem::ESU;            // set a default unit system environment

  puq::Quantity q1, q2;

  q1 = puq::Quantity(34,"statA");                     // ESU units are available by default
  q2 = q1.convert("Fr/ms");
  EXPECT_EQ(q2.to_string(), "0.034*Fr*ms-1");  

  us.close();                                         // switch to previous system

  EXPECT_THROW(puq::Quantity(2,"statA"), puq::AtomParsingExcept);  // ESU is no more available
  
  q1 = puq::Quantity(2,"A");
  EXPECT_EQ(q1.to_string(), "2*A");                   // SI is available
  
}

#endif
