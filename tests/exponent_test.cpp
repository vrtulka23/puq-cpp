#include <gtest/gtest.h>
#include "../src/puq.h"

TEST(Exponent, Initialization) {
  
  Exponent e = {1,2};
  EXPECT_EQ(e.to_string(), "1:2");  // only denominator

  e = Exponent(2,1);
  EXPECT_EQ(e.to_string(), "2");    // only numerator
  
  e = Exponent(2,-1);
  EXPECT_EQ(e.to_string(), "-2");   // negative denominator
  
  e = Exponent(-2,1);
  EXPECT_EQ(e.to_string(), "-2");   // negative numerator

  e = Exponent(-2,-1);
  EXPECT_EQ(e.to_string(), "2");    // both negative

  e = Exponent();
  EXPECT_EQ(e.to_string(), "");     // unit exponent

  e = Exponent(0);
  EXPECT_EQ(e.to_string(), "0");    // zero exponent
  
  e = Exponent(0,3);
  EXPECT_EQ(e.to_string(), "0");    // zero exponent

  e = Exponent(30,60);
  EXPECT_EQ(e.to_string(), "1:2");  // reduced form

  e = Exponent(2*3*5,3*5);
  EXPECT_EQ(e.to_string(), "2");    // reduced form
  
}

TEST(Exponent, Arithmetics) {

  Exponent a(2,3);
  Exponent b(1,6);

  a += b;
  EXPECT_EQ(a.to_string(), "5:6");

  a -= b;
  EXPECT_EQ(a.to_string(), "2:3");
}