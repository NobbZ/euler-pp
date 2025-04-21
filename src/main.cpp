#include <algorithm>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <vector>

#include "problem1.hpp"
#include "problem2.hpp"
#include "problem3.hpp"
#include "problem4.hpp"
#include "problem5.hpp"
#include "problem6.hpp"

std::vector<euler::euler *> problems{
  new euler::problem1(),
  new euler::problem2(),
  new euler::problem3(),
  new euler::problem4(),
  new euler::problem5(),
  new euler::problem6(),
};

int main() {
  std::for_each(problems.cbegin(), problems.cend(), [](euler::euler *p) {
    std::cout << "Problem " << std::setfill(' ') << std::setw(3) << p->id()
              << ": " << std::setw(30) << std::quoted(p->caption()) << " "
              << std::setw(10) << p->run()
              << std::endl;

    std::cout << std::setw(54) << p->url() << std::endl;
  });
}
