/**
 * @file lenString.cpp
 * @brief Calculates the length of a string without using standard library functions
 * 
 * This program demonstrates manual string length calculation using pointer
 * arithmetic to traverse the string until the null terminator is found.
 */

#include <iostream>

using namespace std;

/**
 * @brief Calculates the length of a string
 * 
 * Traverses the string using pointer arithmetic, counting characters until
 * the null terminator is reached.
 * 
 * @param str Pointer to the null-terminated string
 * @return The length of the string (number of characters before null terminator)
 * 
 * Time Complexity: O(n) where n is the length of the string
 * Space Complexity: O(1)
 */
int lenString(char *str) {
  int count = 0;  // Counter for string length
  
  // Traverse string until null terminator
  for (int i = 0; *str != '\0'; i++) {
    count++;  // Increment count for each character
    str++;    // Move pointer to next character
  }
  return count;
}

/**
 * @brief Main function to test string length calculation
 * 
 * Reads a string from user input and displays its length using the
 * lenString function.
 * 
 * @return 0 on successful execution (implicit)
 */
int main() {
  char str [100];  // Buffer to store user input string

  // Read string from user
  cout << "Enter text: ";
  cin >> str;

  // Calculate and display string length
  cout << lenString(&str[0]);
}
