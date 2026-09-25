/**
 * @file gcd.cpp
 * @brief Calculates the Greatest Common Divisor (GCD) using iterative approach
 * 
 */

#include <iostream>

using namespace std;

/**
 * @brief Main function to calculate GCD of two numbers
 * 
 * @return 0 on successful execution (implicit)
 */
int main() {
  int a,b;  // Two numbers to find GCD of
  
  // Read first number from user
  cout << "Enter first number: ";
  cin >> a;

  // Read second number from user
  cout << "Enter second number: ";
  cin >> b;

  // Euclidean algorithm
  while(b !=0) {
    int r = a%b;

    a = b;  // Replace a with b
    b = r;  // Replace b with remainder
  }

  // Display the GCD
  cout << "Greatest common divisor: " << a;
}
