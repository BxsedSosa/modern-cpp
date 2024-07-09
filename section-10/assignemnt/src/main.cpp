#include <iostream>
#include <string>

using namespace std;

int main() {
  string user_input{};

  cout << "Please enter a odd length string: ";
  cin >> user_input;
  cout << endl;

  int string_length = user_input.size();

  for (int i = 0; i < user_input.size(); ++i) {
    string space(string_length, ' ');
    string substring = user_input.substr(0, i);
    cout << space;
    for (int j = 0; j <= i; ++j) {
      cout << user_input[j];
    }
    for (int k = substring.size(); k >= 0; --k) {
      cout << substring[k];
    }
    cout << endl;
    --string_length;
  }

  return 0;
}
