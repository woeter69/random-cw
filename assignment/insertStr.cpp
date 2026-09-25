/**
 * @file insertStr.cpp
 * @brief Inserts one string into another at a specified position
 * 
 * This program demonstrates string insertion by manually copying characters
 * from the original string and the string to be inserted into a result string.
 */

#include <iostream>

using namespace std;

/**
 * @brief Main function to insert one string into another
 * 
 * Reads two strings and a position from user input, then inserts the second
 * string into the first at the specified position. The result is stored in
 * a new string.
 * 
 * @return 0 on successful execution, -1 if position is invalid
 */
int main() {
  char str[100];       // Original string
  char toInsert[100];  // String to insert
  char result[100];    // Result string after insertion

  int pos;  // Position where to insert the string

  // Read original string (no spaces allowed)
  cout << "Enter the original text: ";
  cin >> str;

  // Read string to insert (no spaces allowed)
  cout << "Enter the text to insert: ";
  cin >> toInsert;

  // Read insertion position
  cout << "Enter position: ";
  cin >> pos;
  
  // Calculate length of original string
  int lenStr = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    lenStr++;
  }

  // Calculate length of string to insert
  int lenInsert = 0;
  for (int i = 0; toInsert[i] != '\0'; i++, lenInsert++);

  // Validate insertion position
  if (pos < 0 || pos > lenStr) {
    cout << "Invalid Position\n";
    return -1;
  }

  int i = 0;  // Index for result string

  // Copy characters from original string up to insertion position
  for (int j = 0; j < pos; j++) {
    result[i] = str[j];
    i++;
  }

  // Copy characters from string to insert
  for (int j = 0; j < lenInsert; j++) {
    result[i] = toInsert[j];
    i++;
  }

  // Copy remaining characters from original string
  for (int j = pos; j < lenStr; j++) {
    result[i] = str[j];
    i++;
  }

  // Add null terminator to result string
  result[i] = '\0';

  // Display the result
  cout << "New String: " << result;

  return 0;
}


