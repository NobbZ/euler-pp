#include <algorithm>
#include <iomanip>
#include <iostream>

#include "euler.hpp"

void run_and_pretty(euler::euler *p);

int main(int argc, char *argv[]) {
  auto problems = euler::euler::registry();
  std::vector<euler::euler *> problems_to_run;

  if (argc > 1) {
    for (int i{1}; i < argc; i++) {
      try {
        int16_t problem_id = static_cast<int16_t>(std::stoi(argv[i]));

        problems_to_run.push_back(euler::euler::get_problem(problem_id));
      } catch (const std::invalid_argument &) {
        std::cerr << "Invalid argument: " << argv[1] << ", must be a number\n";
      };
    }
  } else {
    problems_to_run = problems;
  }
  std::for_each(problems_to_run.cbegin(), problems_to_run.cend(),
                [](euler::euler *p) { run_and_pretty(p); });
}

void run_and_pretty(euler::euler *p) {
  static constexpr std::string label{"Problem "};
  static constexpr std::string colon{": "};

  constexpr u_int8_t label_len{label.length()};
  constexpr u_int8_t colon_len{colon.length()};
  constexpr u_int8_t id_len{3};
  constexpr u_int8_t caption_len{29};
  constexpr u_int8_t result_len{12};

  constexpr u_int8_t total_len{label_len + id_len + colon_len + caption_len +
                               result_len};

  std::cout << label << std::setfill(' ') << std::setw(id_len) << p->id()
            << colon << std::setw(caption_len) << std::quoted(p->caption())
            << " " << std::setw(result_len) << p->run() << std::endl;

  std::cout << std::setw(total_len + 1) << p->url() << std::endl;
}
