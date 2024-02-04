#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include "roman2arabiclib/lib.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "please provide a roman number to convert\n";
    return EXIT_FAILURE;
  }
  try {
    std::cout << Roman2Arabic::convert(argv[1]) << "\n";
  } catch (std::runtime_error& e) {
    std::cerr << e.what() << "\n";
    return EXIT_FAILURE;
  }
}
