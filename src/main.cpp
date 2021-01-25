#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

#include "problem1.hpp"
#include "problem2.hpp"

std::vector<euler::euler *> problems{
    new euler::problem1(),
    new euler::problem2(),
};

int main() {
  std::for_each(problems.cbegin(), problems.cend(), [](euler::euler *p) {
    std::cout << "Problem " << std::setfill(' ') << std::setw(3) << p->id()
              << ": " << std::setw(30) << std::quoted(p->caption()) << " "
              << std::setw(10) << p->run()
              << std::endl;
  });
}
