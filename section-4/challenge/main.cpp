#include <iostream>

int main() {
  int fav_number;

  std::cout << "Whats your favorite number?: ";
  std::cin >> fav_number;

  std::cout << "Amazing!! That's my favorite number too!" << '\n';
  std::cout << "No really!!, " << fav_number << " is my favorite number.\n";

  return 0;
}
