#include <algorithm>
#include <iostream>
#include <ranges>
#include <utility>
#include <vector>


int main() {
  std::vector<int> rows_{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  int const MAX = 6;
  int const WINDOW_SZ = 2;
  // clang-format off
  const auto it = std::ranges::find_if(
        rows_
            | std::ranges::views::take(MAX)
            | std::ranges::views::reverse
            | std::ranges::views::slide(WINDOW_SZ),
        [&](const auto rng) {
            return std::ranges::all_of(
                rng, [&](const auto row) { return row == 4 || row == 3; });
        });
  // clang-format on
  std::cout << (*it).back() << '\n';
}
