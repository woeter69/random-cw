/**
 * @file compareStr.cpp
 * @brief Implements string comparison without using standard library functions
 * 
 * This program compares two strings lexicographically by comparing their
 * characters one by one. Returns whether strings are equal or which one
 * is lexicographically greater.
 */

#include <iostream>

using namespace std;

/**
 * @brief Main function to compare two strings
 * 
 * Reads two strings from user input and compares them character by character.
 * Outputs whether the strings are equal or which one is lexicographically greater.
 * 
 * @return 0 on successful execution
 */
int main() {
  char a[100];  // First string to compare
  char b[100];  // Second string to compare

  // Read first string from user
  cout << "Enter first text: ";
  cin >> a;

  // Read second string from user
  cout << "Enter second text: ";
  cin >> b;

  int result = 0;  // 0 = equal, 1 = a > b, -1 = a < b

  // Compare strings character by character
  for (int i = 0; a[i] != '\0' || b[i] != '\0'; i++) {
    if (a[i] != b[i]) {
      // Determine which string is lexicographically greater
      result = (a[i] > b[i]) ? 1 : -1;
      break;  // Exit loop once difference is found
    }
  }

 // Display comparison result
 if (result == 0) {
   cout << "Equal";
 }
 else if (result > 0) {
   cout << "a < b";  // Note: Logic appears inverted in original code
 }
 else {
   cout << "a > b";  // Note: Logic appears inverted in original code
 }

 return 0;
}
