#include <iostream>
#include <cmath>
using namespace std;

/**
 * Calculates the sum of series: 1/1^1 + 1/2^2 + 1/3^3 + ... + 1/n^n
 * 
 * This function computes the sum of fractions where each term is 1 divided
 * by i raised to the power of i, for i from 1 to n.
 * 
 * Formula: Σ(1/i^i) for i = 1 to n
 * 
 * n The number of terms in the series (upper limit)
 * The sum of the series as a double precision floating point number
 * 
 */
double fractionSum(int n) {
    double result = 0;

    for (int i = 1; i <= n; i++) {
        double term = 1.0 / pow(i, i);
        result += (i % 2 ? term : -term);
    }

    return result;
}

/**
 * Calculates the sum of series: 1/1! + 1/2! + 1/3! + ... + 1/n!
 * 
 * This function computes the sum of fractions where each term is 1 divided
 * by the factorial of i, for i from 1 to n. This series converges to e-1
 * as n approaches infinity.
 * 
 * Formula: Σ(1/i!) for i = 1 to n
 * 
 * n The number of terms in the series (upper limit)
 * The sum of the series as a double precision floating point number
 * 
 */
double factorialSum(int n) {
  double result = 0;  // Accumulator for the sum
  int factorial = 1;
  // Loop from 1 to n to calculate each term in the series
  // Each iteration computes factorial incrementally and adds 1/factorial to result
  for (int i = 1; i <= n; i++) {
    factorial = factorial * i;  
    result += 1.0 / factorial;  // Add 1/(i!) to the running sum
  }
  return result;  // Return the total sum
}



/**
 * Main function to calculate and display two mathematical series sums
 * 
 * Reads a limit n from user and calculates:
 * 1. Sum of 1/i^i series (exponent series)
 * 2. Sum of 1/i! series (factorial series)
 * 
 * 0 on successful execution
 * 
 */
int main() {
  int n;
  cout << "Enter limit: ";
  cin >> n;

  double sumexp = fractionSum(n);
  double sumfact = factorialSum(n);
  cout << "Sum of fractions(exponent): " << sumexp << endl;
  cout << "Sum of fractions(factorial): " << sumfact << endl;

  return 0;
}
