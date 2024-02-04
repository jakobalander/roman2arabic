#include <cstdint>
#include <format>
#include <map>
#include <stdexcept>
#include <string>

#include "roman2arabiclib/lib.hpp"


uint64_t Roman2Arabic::convert(const std::string roman) {
  uint64_t arabic{0};
  uint64_t prev_val{Roman2Arabic::valueOf(roman.at(0))};
  for (const auto c : roman) {
    uint64_t val = Roman2Arabic::valueOf(c);
    arabic += val;
    if (val > prev_val) {
      arabic -= 2 * prev_val;
    }
    prev_val = val;
  } 
  return arabic;
}

uint64_t Roman2Arabic::valueOf(const char c) {
  const std::map<char, uint32_t> values {
    {'i', 1},
    {'v', 5},
    {'x', 10},
    {'l', 50},
    {'c', 100},
    {'d', 500},
    {'m', 1000}
  };
  try {
    return values.at(c);
  } catch (std::out_of_range& e) {
    throw std::runtime_error(std::format("unknown character: {}", c));
  }
}
