/*
 * This program takes a number and prints its table using iterations (while loop).
 * 
 * It prompts the user to enter a number and then calculates and displays the multiplication table for that number from 1 to 10.
 * 
 * I/O:
 * Input: A single integer number.
 * Output: The multiplication table for the input number from 1 to 10.
 * 
 * I/O example:
 * Input: 4
 * Output:
 * 4 x 1 = 4
* 4 x 2 = 8
* 4 x 3 = 12
* 4 x 4 = 16
* 4 x 5 = 20
* 4 x 6 = 24
* 4 x 7 = 28
* 4 x 8 = 32
* 4 x 9 = 36
* 4 x 10 = 40
*/
#include <iostream>
using namespace std;

int main() {
    // Program to print multiplication table of a number using while loop
    int a;
    cout << "Enter a number to print its table: ";
    cin >> a;
    
    int b = 1;
    // Using while loop to iterate from 1 to 10
    while(b <= 10) {
        cout << a << " x " << b << " = " << a * b << endl;
        b++;
    }  
    // End of the program
    return 0;
}