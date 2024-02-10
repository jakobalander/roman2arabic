#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include "roman2arabiclib/lib.hpp"

bool isNumeric(std::string s) {
  const char test{s.at(0)};
  if (test >= '0' && test <= '9')
    return true;
  return false;
}

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "please provide a roman or arabic number to convert\n";
    return EXIT_FAILURE;
  }
  try {
    if (isNumeric(argv[1])) {
      uint64_t number = std::stoi(argv[1]);
      std::cout << RomanArabicTranslator::convertA2R(number) << "\n";
    } else {
      std::cout << RomanArabicTranslator::convertR2A(argv[1]) << "\n";
    }
  } catch (std::runtime_error& e) {
    std::cerr << e.what() << "\n";
    return EXIT_FAILURE;
  }
}
