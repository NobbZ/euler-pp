#include <algorithm>
#include <iomanip>
#include <iostream>
#include <ostream>

#include "euler.hpp"

int main() {
  auto problems = euler::euler::registry();
  std::for_each(problems.cbegin(), problems.cend(), [](euler::euler *p) {
    std::cout << "Problem " << std::setfill(' ') << std::setw(3) << p->id()
              << ": " << std::setw(30) << std::quoted(p->caption()) << " "
              << std::setw(10) << p->run() << std::endl;

    std::cout << std::setw(54) << p->url() << std::endl;
  });
}
