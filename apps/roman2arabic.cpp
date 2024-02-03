#include <cstdlib>
#include <iostream>

#include "roman2arabiclib/lib.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "please provide a roman number to convert\n";
    return EXIT_FAILURE;
  }
  std::cout << Roman2Arabic::convert(argv[1]) << "\n";
}
