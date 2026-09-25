/**
 * @file gcdrec.cpp
 * @brief Calculates the Greatest Common Divisor (GCD) using recursive approach
 * 
 * This program implements the Euclidean algorithm recursively to find the GCD
 * of two numbers. This is a correct implementation using the modulo operator.
 */

#include <iostream>

using namespace std;

/**
 * @brief Recursively calculates the GCD of two numbers
 * 
 * Implements the Euclidean algorithm using recursion. The algorithm is based
 * on the principle that GCD(a, b) = GCD(b, a mod b).
 * 
 * @param a First integer
 * @param b Second integer
 * @return The greatest common divisor of a and b
 * 
 * Time Complexity: O(log(min(a, b)))
 * Space Complexity: O(log(min(a, b))) due to recursion stack
 */
int gcd(int a, int b) {
  // Base case: when b is 0, GCD is a
  if (b == 0) {
    return a;
  }
  // Recursive case: GCD(a, b) = GCD(b, a mod b)
  return gcd(b, a%b);
}

/**
 * @brief Main function to test GCD calculation
 * 
 * Reads two integers from user input, calculates their GCD using the
 * recursive gcd function, and displays the result.
 * 
 * @return 0 on successful execution (implicit)
 */
int main() {
  int a,b;  // Two numbers to find GCD of

  // Read first number from user
  cout << "Enter first element: "; cin >> a;

  // Read second number from user
  cout << "Enter second element: "; cin >> b;
  
  // Calculate and display GCD
  int ans = gcd(a,b);
  cout << ans << endl;
}
