#include <iostream>

using namespace std;

int main() {
  char str[100]; // Making a large character array to store user string
  cout << "Enter text: ";
  cin >> str;
  cout << "You entered " << str << endl;

  int count[26]; // Making a array to keep track of every alphabet index 0 means and 25 means z

  int i = 0;
  while (i < 26) {
    count[i++] = 0; // Assigning 0 to every element of count 
  }


  i = 0;
  while (str[i] != '\0') {
    char c = str[i]; // Getting character from user string one by one 
    
    if (c >= 'A' && c <= 'Z') {
      c = c + 32; // Making all the user input string small letters 
    }
    if (c >= 'a' && c <= 'z') {
      count[c - 'a'] = count[c - 'a'] + 1; // Making so that specific array index contain specific count for each letter, what c - 'a' does is (if c is i) ascii of i is 105 and ascii of a is 97 so what gets stored in the array is on index 8 the count of i is stored.
    }
    i++; // Increasing for while loop
  }

  i = 0;
  while (i < 26) {
    if (count[i] > 0) {
      cout << char('a' + i) << ": " << count[i] << endl; // What 'a' + i does is it gets the original character back as a is 97 and the character is stored on the number its from the char 'a'.
    }
    i++; // Increasing for while loop
  }
}
