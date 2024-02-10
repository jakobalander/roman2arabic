#pragma once

#include <string>


class ARPair {
public:
  ARPair() = delete;
  ARPair(const std::string roman, uint64_t arabic);
  const std::string roman;
  const uint64_t arabic;
};


class RomanArabicTranslator{
public:
  static uint64_t convertR2A(const std::string& roman);
  static std::string convertA2R(uint64_t arabic);
private:
  static std::string toLowercase(const std::string&);
  static uint64_t findArabic(const char roman);
  static std::string findRoman(const uint64_t arabic); 
  static const std::vector<ARPair> rel;
};


