#include <gtest/gtest.h>

#include "roman2arabiclib/lib.hpp"

TEST(basic, only_addition) {
  EXPECT_EQ(Roman2Arabic::convert("mdclxvi"), 1666);
}

TEST(basic, with_leading_subtraction) {
  EXPECT_EQ(Roman2Arabic::convert("iv"), 4);
}

TEST(basic, with_trailing_subtraction) {
  EXPECT_EQ(Roman2Arabic::convert("miv"), 1004);
}

TEST(basic, with_leading_and_trailing_subtraction) {
  EXPECT_EQ(Roman2Arabic::convert("cmliv"), 954);
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
    EXPECT_EQ(Roman2Arabic::convert(e.first), e.second);
  }
}
