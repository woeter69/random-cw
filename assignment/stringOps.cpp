/**
 * @file stringOps.cpp
 * @brief Menu-driven program for various string operations
 * 
 * This program combines multiple string manipulation utilities into a single
 * menu-driven interface. It includes operations for displaying memory addresses,
 * concatenation, comparison, length calculation, case conversion, reversal,
 * and string insertion.
 */

#include <iostream>

using namespace std;

/**
 * @brief Displays memory addresses of each character in a string
 * 
 * Shows the memory address of each character in the provided string,
 * demonstrating how characters are stored contiguously in memory.
 * 
 * @param str The string whose character addresses will be displayed
 */
void showAddr(char str[]) {
  for(int i = 0; str[i] != '\0'; i++) {
    cout << (void*)&str[i] << endl;
  }
}

/**
 * @brief Concatenates two strings manually
 * 
 * Appends string b to the end of string a. The function modifies string a
 * in-place by finding its null terminator and copying characters from b.
 * 
 * @param a The destination string (must have enough space for both strings)
 * @param b The source string to append
 */
void catString(char a[], char b[]) {
  int i;
  int j;
  for (i=0; a[i] != '\0'; i++);

  for (j=0; b[j] != '\0'; j++) {
    a[i] = b[j];
    i++;
  }
  a[i] = '\0';
}

/**
 * @brief Compares two strings lexicographically
 * 
 * Compares two strings character by character and returns the comparison result.
 * 
 * @param a First string to compare
 * @param b Second string to compare
 * @return 0 if equal, 1 if a > b, -1 if a < b
 */
int compareStr(char a[], char b[]) {
  int result = 0;

  for (int i = 0; a[i] != '\0' || b[i] != '\0'; i++) {
    if (a[i] != b[i]) {
      result = (a[i] > b[i]) ? 1 : -1;
      break;
    }
  }
  return result;
}

/**
 * @brief Calculates the length of a string
 * 
 * Traverses the string using pointer arithmetic, counting characters until
 * the null terminator is reached.
 * 
 * @param str Pointer to the null-terminated string
 * @return The length of the string (number of characters before null terminator)
 */
int lenString(char *str) {
  int count = 0;
  for (int i = 0; *str != '\0'; i++) {
    count++;
    str++;
  }
  return count;
}

/**
 * @brief Converts lowercase letters to uppercase in a string
 * 
 * Modifies the string in-place by converting all lowercase letters (a-z)
 * to uppercase (A-Z) by subtracting 32 from their ASCII values.
 * 
 * @param str The string to convert
 */
void uppertolower(char str[]) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'a' && str[i] <= 'z' ) {
      str[i] = str[i] - 32;
    }
  }
}

/**
 * @brief Reverses a string
 * 
 * Creates a reversed copy of the input string by copying characters
 * from the end to the beginning.
 * 
 * @param str The original string to reverse
 * @param revStr The output string to store the reversed result
 */
void reverseStr(char str[], char revStr[]) {
  int n = 0;
  
  for (int i = 0; str[i] != '\0'; i++) {
    n++;
  }
  int len = n;
  for (int j = 0; j < len; j++) {
    n--;
    revStr[j] = str[n];
  }

  revStr[len] = '\0';
}

/**
 * @brief Inserts one string into another at a specified position
 * 
 * Creates a new string by inserting toInsert into str at the given position.
 * 
 * @param str The original string
 * @param toInsert The string to insert
 * @param result The output string containing the result
 * @param pos The position where to insert the string
 * @return 0 on success, -1 if position is invalid
 */
int insertStr(char str[], char toInsert[], char result[], int pos) {
  int lenStr = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    lenStr++;
  }

  int lenInsert = 0;
  for (int i = 0; toInsert[i] != '\0'; i++, lenInsert++);

  if (pos < 0 || pos > lenStr) {
    return -1;
  }

  int i = 0;

  for (int j = 0; j < pos; j++) {
    result[i] = str[j];
    i++;
  }

  for (int j = 0; j < lenInsert; j++) {
    result[i] = toInsert[j];
    i++;
  }

  for (int j = pos; j < lenStr; j++) {
    result[i] = str[j];
    i++;
  }

  result[i] = '\0';
  return 0;
}

/**
 * @brief Main function providing menu-driven interface for string operations
 * 
 * Displays a menu of string operations and executes the user's choice.
 * Operations include: show addresses, concatenate, compare, length,
 * uppercase conversion, reverse, and insert.
 * 
 * @return 0 on successful execution
 */
int main() {
  int choice;
  char str[100];
  char str2[100];
  char result[200];

  cout << "\n===== String Operations Menu =====\n";
  cout << "1. Show Memory Addresses\n";
  cout << "2. Concatenate Strings\n";
  cout << "3. Compare Strings\n";
  cout << "4. String Length\n";
  cout << "5. Convert to Uppercase\n";
  cout << "6. Reverse String\n";
  cout << "7. Insert String\n";
  cout << "8. Exit\n";
  cout << "==================================\n";
  cout << "Enter your choice: ";
  cin >> choice;

  switch(choice) {
    case 1: {
      cout << "Enter text: ";
      cin >> str;
      cout << "Memory addresses:\n";
      showAddr(str);
      break;
    }
    
    case 2: {
      cout << "Enter text: ";
      cin >> str;
      cout << "Enter second text: ";
      cin >> str2;
      cout << "You entered " << str << " and " << str2 << endl;
      catString(str, str2);
      cout << str;
      break;
    }
    
    case 3: {
      cout << "Enter first text: ";
      cin >> str;
      cout << "Enter second text: ";
      cin >> str2;
      int res = compareStr(str, str2);
      if (res == 0) {
        cout << "Equal";
      }
      else if (res > 0) {
        cout << str2 << "<" << str;
      }
      else {
        cout << str2 << ">" << str;
      }
      break;
    }
    
    case 4: {
      cout << "Enter text: ";
      cin >> str;
      cout << lenString(&str[0]);
      break;
    }
    
    case 5: {
      cout << "Enter text: ";
      cin >> str;
      uppertolower(str);
      cout << str;
      break;
    }
    
    case 6: {
      cout << "Enter text: ";
      cin >> str;
      reverseStr(str, result);
      cout << result;
      break;
    }
    
    case 7: {
      int pos;
      cout << "Enter the original text: ";
      cin >> str;
      cout << "Enter the text to insert: ";
      cin >> str2;
      cout << "Enter position: ";
      cin >> pos;
      
      if (insertStr(str, str2, result, pos) == -1) {
        cout << "Invalid Position\n";
      }
      else {
        cout << "New String: " << result;
      }
      break;
    }
    
    case 8: {
      cout << "Exiting program.\n";
      break;
    }
    
    default: {
      cout << "Invalid choice!\n";
      break;
    }
  }

  return 0;
}
