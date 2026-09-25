/*
 * 
 * This program calculates the total price of fruits based on their price per kilogram
 * and the quantity purchased in kilograms. It's designed for fruit sellers who need to
 * quickly calculate the total cost for customers buying fruits by weight.
 * 
 */

#include <iostream>
using namespace std;

int main() {
    // Variables to store user input and calculation result
    int a, b;
    
    // Prompt user for price per kilogram
    cout << "Enter the price of the item per kg: " << endl;
    cin >> a;  // Store price per kg in variable 'a'
    
    // Prompt user for quantity in kilograms
    cout << "Enter the quantity of the item in kg: " << endl;
    cin >> b;  // Store quantity in kg in variable 'b'
    
    // Calculate total price: price per kg × quantity in kg
    int total = a * b;
    
    // Display the calculated total price
    cout << "The total price of the item is: " << total << endl;
    
    return 0;  // Indicate successful program completion
}