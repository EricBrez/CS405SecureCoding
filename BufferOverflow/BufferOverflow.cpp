// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>

int main()
{
  std::cout << "Buffer Overflow Example" << std::endl;

  // TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
  //  even though it is a constant and the compiler buffer overflow checks are on.
  //  You need to modify this method to prevent buffer overflow without changing the account_number
  //  variable, and its position in the declaration. It must always be directly before the variable used for input.
  //  You must notify the user if they entered too much data.

  const std::string account_number = "CharlieBrown42";
  char user_input[20];
  char tempVal[256]; //declare much larger character string variable.
  std::cout << "Enter a value: ";
  std::cin >> tempVal; // Take input into a temporary, much larger character string
  bool validInp = false;

  while (!validInp) {
	  if (strlen(tempVal) <= sizeof(user_input)) { //Check if the length of the temporary variable is smaller or equal to the size of the user_input buffer
		  strcpy_s(user_input, tempVal); // If yes, copy tempVal to user_input
		  validInp = true;
	  }
	  else {
		  std::cout << "Your input is too long, error occurred." << std::endl; //Print error message
		  std::cin.clear(); // Clear cin buffer
		  std::cin.ignore(100, '\n');
		  std::cout << "Please enter a value" << std::endl;
		  std::cin >> tempVal; //take new input

	  }
  }

  
  

  std::cout << "You entered: " << user_input << std::endl;
  std::cout << "Account Number = " << account_number << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
