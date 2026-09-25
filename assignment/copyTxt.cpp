/**
 * @file copyTxt.cpp
 * @brief Copies content from one text file to another
 * 
 * This program reads text from 'copy.txt' and writes it to 'paste.txt'
 * character by character. It demonstrates basic file I/O operations in C++.
 */

#include <iostream>
#include <fstream>

using namespace std;

/**
 * @brief Main function to copy file contents
 * 
 * Opens two files: copy.txt for reading and paste.txt for writing.
 * Reads words from the source file and writes them character by character
 * to the destination file.
 * 
 * @return 0 on successful execution (implicit)
 */
int main() {
  // Open source file for reading
  fstream copyfile("copy.txt", ios::in);
  // Open destination file for writing
  fstream pastefile("paste.txt", ios::out);

  char text[250];    // Buffer to store each word read from file
  char result[250];  // Unused variable

  int i = 0;  // Index for character iteration

  // Read first word from source file
  copyfile >> text;
  
  // Continue reading until end of file
  while (copyfile) {
    i = 0;
    // Write each character of the word to destination file
    while (text[i] != '\0') {
      pastefile << text[i];
      i++;
    }

    // Read next word from source file
    copyfile >> text;
  }

  // Close both files
  copyfile.close();
  pastefile.close();

  cout << "Copied successfully";

  return 0;
}
