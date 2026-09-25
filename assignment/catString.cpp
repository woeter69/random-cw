/**
 * @file catString.cpp
 * @brief Implements string concatenation without using standard library functions
 * 
 * This program demonstrates manual string concatenation by appending one
 * character array to another using pointer arithmetic and loops.
 */

#include <iostream>

using namespace std;

/**
 * @brief Concatenates two strings manually
 * 
 * Appends string b to the end of string a. The function modifies string a
 * in-place by finding its null terminator and copying characters from b.
 * 
 * @param a The destination string (must have enough space for both strings)
 * @param b The source string to append
 * 
 * Time Complexity: O(n + m) where n is length of a and m is length of b
 * Space Complexity: O(1)
 * 
 * @note String a must have sufficient space to hold both strings
 * @note This function modifies the first parameter in-place
 */
void catString(char a[], char b[]) {
  int i;  // Index for string a
  int j;  // Index for string b
  
  // Find the end of string a (null terminator position)
  for (i=0; a[i] != '\0'; i++);

  // Copy characters from string b to the end of string a
  for (j=0; b[j] != '\0'; j++) {
    a[i] = b[j];
    i++;
  }
  
  // Add null terminator to the concatenated string
  a[i] = '\0';
}

/**
 * @brief Main function to test string concatenation
 * 
 * Reads two strings from user input, concatenates them using the catString
 * function, and displays the result.
 * 
 * @return 0 on successful execution (implicit)
 */
int main() {
  char a[100];  // First string (destination)
  char b[100];  // Second string (source)

  // Read first string from user
  cout << "Enter text: ";
  cin >> a;
  
  // Read second string from user
  cout << "Enter second text: ";
  cin >> b;
  cout << "You entered " << a << " and " << b << endl;
  
  // Concatenate strings and display result
  catString(a,b);
  cout << a;
}

