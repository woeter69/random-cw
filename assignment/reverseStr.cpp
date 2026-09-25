/**
 * @file reverseStr.cpp
 * @brief Reverses a string without using standard library functions
 * 
 * This program reads a string from user input and creates a reversed copy
 * by copying characters from the end to the beginning.
 */

#include <iostream>

using namespace std;

/**
 * @brief Main function to reverse a string
 * 
 * Reads a string from user input, calculates its length, and creates a
 * reversed copy by iterating backwards through the original string.
 * 
 * @return 0 on successful execution (implicit)
 */
int main() {
  char str[100];     // Original string
  char revStr[100];  // Reversed string
  int n = 0;         // Length counter
  
  // Read string from user
  cout << "Enter text: ";
  cin >> str;
  
  // Calculate length of string
  for (int i = 0; str[i] != '\0'; i++) {
    n++;
  }
  
  int len = n;  // Store length for later use
  
  // Copy characters from end to beginning
  for (int j = 0; j < len; j++) {
    n--;  // Decrement to get index from end
    revStr[j] = str[n];  // Copy character to reversed position
  }

  // Add null terminator to reversed string
  revStr[len] = '\0';

  // Display reversed string
  cout << revStr;
}
