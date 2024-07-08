// Section 9
// Challenge
/*
    This challenge is about using a collection (list) of integers and allowing
the user to select options from a menu to perform operations on the list.

    Your program should display a menu options to the user as follows:

    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:

The program should only accept valid choices from the user, both upper and
lowercase selections should be allowed. If an illegal choice is made, you should
display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in
the list. If the list is empty you should display "[] - the list is empty" If
the list is not empty then all the list element should be displayed inside
square brackets separated by a space. For example, [ 1 2 3 4 5 ]

If the user enters 'A' or 'a' then you should prompt the user for an integer to
add to the list which you will add to the list and then display it was added.
For example, if the user enters 5 You should display, "5 added". Duplicate list
entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the
elements in the list and display it. If the list is empty you should display,
"Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the
list. For example, if the list contains [2 4 5 1],  you should display, "The
smallest number is 1" If the list is empty you should display, "Unable to
determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest
number is 5" If the list is empty you should display, "Unable to determine the
largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program
should terminate.

Before you begin. Write out the steps you need to take and decide in what order
they should be done. Think about what loops you should use as well as what you
will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you
complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it
occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a
.clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!

*/
#include <iostream>
#include <vector>

using namespace std;

void display_message() {
  cout << "P - Print numbers\nA - Add a number\nM - Display mean of the "
          "numbers\nS - Display the smallest number\nL - Display the largest "
          "number\nQ - Quit\n\nEnter your choice: ";
}

char validate_input(char user_input, vector<char> options) {
  bool valid{false};

  while (!valid) {
    for (char option : options) {
      if (user_input == option) {
        valid = true;
        return user_input;
      }
    }

    cout << "Please enter a valid option!\n";
    display_message();
    cin >> user_input;
    cout << endl;
  }
  return ' ';
}

void display_vector(vector<int> vec) {
  cout << "[ ";
  for (int num : vec) {
    cout << num << " ";
  }
  cout << "]" << endl;
}

int get_vectors_mean(vector<int> numbers) {
  int sum{0}, mean{0};

  for (int num : numbers) {
    sum += num;
  }

  mean = sum / numbers.size();
  return mean;
}

int get_smallest_number(vector<int> numbers) {
  int curr_lowest{numbers[0]};

  for (int num : numbers) {
    if (num < curr_lowest) {
      curr_lowest = num;
    }
  }

  return curr_lowest;
}

int get_largest_number(vector<int> numbers) {
  int curr_highest{numbers[0]};

  for (int num : numbers) {
    if (num > curr_highest) {
      curr_highest = num;
    }
  }

  return curr_highest;
}

int main() {

  bool running{true};
  char user_input{};
  vector<int> numbers;
  vector<char> valid_inputs{'P', 'p', 'A', 'a', 'M', 'm',
                            'S', 's', 'L', 'l', 'Q', 'q'};

  while (running) {

    display_message();
    cin >> user_input;
    cout << endl;

    user_input = validate_input(user_input, valid_inputs);

    if (user_input == 'P' || user_input == 'p') {
      if (numbers.empty()) {
        cout << "\n[] - list is empty\n";
      } else {
        display_vector(numbers);
      }
    }
    if (user_input == 'A' || user_input == 'a') {
      int user_number{};
      cout << "\nPlease enter a number you'd like to add to the list: ";
      cin >> user_number;

      numbers.push_back(user_number);
      cout << "\nAdded " << user_number << " to the list\n";
    }
    if (user_input == 'M' || user_input == 'm') {
      if (numbers.empty()) {
        cout << "\nYou can't get the mean with a empty list\n";
      } else {
        int mean{get_vectors_mean(numbers)};
        cout << "\nThe mean is: " << mean << endl;
      }
    }
    if (user_input == 'S' || user_input == 's') {
      int smallest_num{0};
      if (numbers.empty()) {
        cout << "\nYou can't get lowest number with a empty list\n";
      } else {
        smallest_num = get_smallest_number(numbers);
        cout << "\nSmallest number: " << smallest_num << endl;
      }
    }
    if (user_input == 'L' || user_input == 'l') {
      int largest_num{0};
      if (numbers.empty()) {
        cout << "\nYou can't get largest number with a empty list\n";
      } else {
        largest_num = get_largest_number(numbers);
        cout << "\nSmallest number: " << largest_num << endl;
      }
    }
    if (user_input == 'Q' || user_input == 'q') {
      exit(1);
    }
  }
  return 0;
}
//
// P - Print numbers
// A - Add a number
// M - Display mean of the numbers
// S - Display the smallest number
// L - Display the largest number
// Q - Quit
//
// Enter your choice:
//
