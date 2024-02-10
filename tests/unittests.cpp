#include <gtest/gtest.h>

#include "roman2arabiclib/lib.hpp"

TEST(basic_roman_to_arabic, only_addition) {
  EXPECT_EQ(RomanArabicTranslator::convertR2A("mdclxvi"), 1666);
}

TEST(basic_roman_to_arabic, with_leading_subtraction) {
  EXPECT_EQ(RomanArabicTranslator::convertR2A("iv"), 4);
}

TEST(basic_roman_to_arabic, with_trailing_subtraction) {
  EXPECT_EQ(RomanArabicTranslator::convertR2A("miv"), 1004);
}

TEST(basic_roman_to_arabic, with_leading_and_trailing_subtraction) {
  EXPECT_EQ(RomanArabicTranslator::convertR2A("cmliv"), 954);
}

TEST(basic_roman_to_arabic, handle_capital_letters) {
  EXPECT_EQ(RomanArabicTranslator::convertR2A("MDCLXVI"), 1666);
}

TEST(basic_arabic_to_roman, only_addition) {
  EXPECT_EQ(RomanArabicTranslator::convertA2R(1666), "mdclxvi");
}

TEST(basic_arabic_to_roman, with_leading_subtraction) {
  EXPECT_EQ(RomanArabicTranslator::convertA2R(4), "iv");
}

TEST(basic_arabic_to_roman, with_trailing_subtraction) {
  EXPECT_EQ(RomanArabicTranslator::convertA2R(1004), "miv");
}

TEST(basic_arabic_to_roman, with_leading_and_trailing_subtraction) {
  EXPECT_EQ(RomanArabicTranslator::convertA2R(954), "cmliv");
}

TEST(random_values, from_wikipedia) {
  // various random numbers from wikipedia
  const std::map<std::string, uint64_t> oracle {
    {"xxxix", 39},
    {"ccxlvi", 246},
    {"dcclxxxix", 789},
    {"mmcdxxi", 2421},
    {"clx", 160},
    {"ccvii", 207},
    {"mix", 1009},
    {"mlxvi", 1066},
    {"mdcclxxvi", 1776},
    {"mcmxviii", 1918},
    {"mcmxliv", 1944},
    {"mmxxiv", 2024},
    {"mmmcmxcix", 3999}
  };

  for (auto e : oracle) {
    EXPECT_EQ(RomanArabicTranslator::convertR2A(e.first), e.second);
    EXPECT_EQ(RomanArabicTranslator::convertA2R(e.second), e.first);
  }
}
