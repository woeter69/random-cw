/**
 * @file showAddr.cpp
 * @brief Displays memory addresses of each character in a string
 * 
 * This program demonstrates pointer arithmetic and memory layout by displaying
 * the memory address of each character in a user-provided string.
 */

#include <iostream>

using namespace std;

/**
 * @brief Main function to display character addresses
 * 
 * Reads a string from user input and displays the memory address of each
 * character. This demonstrates how characters are stored contiguously in memory.
 * 
 * @return 0 on successful execution (implicit)
 */
int main() {
  char str[100];  // Buffer to store user input string
  
  // Read string from user
  cout << "Enter text: ";
  cin >> str;

  // Display memory address of each character
  for(int i = 0; str[i] != '\0'; i++) {
    // Cast to void* to display address in hexadecimal format
    cout << (void*)&str[i] << endl;
  }
}
