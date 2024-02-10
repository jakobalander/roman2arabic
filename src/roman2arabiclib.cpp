#include <cctype>
#include <cstdint>
#include <format>
#include <stdexcept>
#include <string>
#include <vector>

#include "roman2arabiclib/lib.hpp"


ARPair::ARPair(const std::string roman, uint64_t arabic) : roman{roman}, arabic{arabic} {}

std::string RomanArabicTranslator::convertA2R(uint64_t arabic) {
  std::string roman{};
  for (const auto& pair : rel) {
    uint64_t number = arabic / pair.arabic;
    if (number) {
      for (uint64_t i = 0; i < number; i++) {
        roman += pair.roman;
      }
      arabic -= number * pair.arabic;
    }
  }
  return roman;
}

uint64_t RomanArabicTranslator::convertR2A(const std::string& roman) {
  const std::string lower = RomanArabicTranslator::toLowercase(roman);
  uint64_t arabic{0};
  uint64_t prev_val{RomanArabicTranslator::findArabic(lower.at(0))};
  for (const auto c : lower) {
    uint64_t val = findArabic(c);
    arabic += val;
    if (val > prev_val) {
      arabic -= 2 * prev_val;
    }
    prev_val = val;
  } 
  return arabic;
}

std::string RomanArabicTranslator::toLowercase(const std::string& s) {
  std::string lower;
  lower.reserve(s.length());
  for (const auto& c : s) {
    lower += tolower(c);
  }
  return lower;
}

uint64_t RomanArabicTranslator::findArabic(const char c) {
  const std::string roman{c};
    for (const auto& e : rel) {
      if (e.roman == roman) {
        return e.arabic;
      }
    }
    throw std::runtime_error(std::format("roman letter not found: {}", roman));
}

std::string RomanArabicTranslator::findRoman(const uint64_t arabic) {
    for (const auto& e : rel) {
      if (e.arabic == arabic) 
        return e.roman;
    }
    throw std::runtime_error(std::format("arabic number not found: {}", arabic));
  }

const std::vector<ARPair> RomanArabicTranslator::rel {
    ARPair{"m", 1000},
    ARPair{"cm", 900},
    ARPair{"d", 500},
    ARPair{"cd", 400},
    ARPair{"c", 100},
    ARPair{"xc", 90},
    ARPair{"l", 50},
    ARPair{"xl", 40},
    ARPair{"x", 10},
    ARPair{"ix", 9},
    ARPair{"v", 5},
    ARPair{"iv", 4},
    ARPair{"i", 1}
  };
