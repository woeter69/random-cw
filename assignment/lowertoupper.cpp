/**
 * @file uppertolower.cpp
 * @brief Converts lowercase letters to uppercase in a string
 * 
 * This program reads a string and converts all lowercase letters to uppercase
 * by manipulating ASCII values. The conversion is done by subtracting 32 from
 * the ASCII value of lowercase letters.
 */

#include <iostream>

using namespace std;

/**
 * @brief Main function to convert lowercase to uppercase
 * 
 * Reads a string from user input and converts all lowercase letters (a-z)
 * to uppercase (A-Z) by subtracting 32 from their ASCII values.
 * 
 * @return 0 on successful execution (implicit)
 */
int main() {
  char str[100];  // Buffer to store user input string

  // Read string from user
  cout << "Enter text: ";
  cin >> str;

  // Convert lowercase letters to uppercase
  for (int i = 0; str[i] != '\0'; i++) {
    // Check if character is lowercase (ASCII 97-122)
    if (str[i] >= 'a' && str[i] <= 'z' ) {
      // Convert to uppercase by subtracting 32 (ASCII difference)
      str[i] = str[i] - 32;
    }
  }

  // Display converted string
  cout << str;
}
