#include <iostream>

int main() {
  const int large_room_price{35};
  const int small_room_price{25};
  const double sales_tax{.06};

  std::cout << "Number of large rooms:";
  int large_room_quanity{0};
  std::cin >> large_room_quanity;

  std::cout << "\nNumber of small rooms:";
  int small_room_quanity{0};
  std::cin >> small_room_quanity;

  std::cout << "\nPrice per small: $" << small_room_price << '\n';
  std::cout << "Price per large: $" << large_room_price << '\n';

  int cost{(large_room_price * large_room_quanity) +
           (small_room_price * small_room_quanity)};
  std::cout << "Cost: $" << cost << '\n';

  double tax_cost{sales_tax * cost};
  std::cout << "Tax: $" << tax_cost << '\n';
  std::cout << "==============================\n";

  double esitmated_total{cost + tax_cost};
  std::cout << "Total estimate: $" << esitmated_total << '\n';
  std::cout << "This estimate is valid for 30 days\n";

  return 0;
}
