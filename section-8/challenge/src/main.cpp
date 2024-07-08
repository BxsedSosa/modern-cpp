/* Create a program that accepts a input of pennies
 *
 * then organize it to output every curreny in USD you'd recieve back
 *
 * Dollar: 0
 * Quarter: 0
 * Dime: 0
 * Nickle: 0
 * Pennies: 0
 */
#include <iostream>

using namespace std;

int get_change(int pennies, int increment) {
  int total{pennies / increment};

  if (total <= 0) {
    return 0;
  }

  return total;
}

int get_remainder(int pennies, int increment) {
  int total{pennies % increment};

  if (total <= 0) {
    return 0;
  }

  return total;
}

int main() {
  const int dollar_value{100};
  const int quarter_value{25};
  const int dime_value{10};
  const int nickle_value{5};

  int input_pennies{};

  cout << "How many pennies do you have?: ";
  cin >> input_pennies;

  int dollars{}, quarters{}, dimes{}, nickles{}, pennies{};
  int remainder{};

  dollars = get_change(input_pennies, dollar_value);
  remainder = get_remainder(input_pennies, dollar_value);
  quarters = get_change(remainder, quarter_value);
  remainder = get_remainder(remainder, quarter_value);
  dimes = get_change(remainder, dime_value);
  remainder = get_remainder(remainder, dime_value);
  nickles = get_change(remainder, nickle_value);
  pennies = get_remainder(remainder, nickle_value);

  cout << "You have:\n";
  cout << "Dollars: " << dollars << endl;
  cout << "Quarters: " << quarters << endl;
  cout << "Dimes: " << dimes << endl;
  cout << "Nickles: " << nickles << endl;
  cout << "Pennies: " << pennies << endl;

  return 0;
}
