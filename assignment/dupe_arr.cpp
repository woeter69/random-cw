#include <iostream>

using namespace std;

/**
 * Main function to remove duplicate elements from an array
 * 
 * This program reads an array from user input, removes all duplicate elements
 * while preserving the order of first occurrence, and prints the resulting array.
 * 
 * Algorithm:
 * - Uses a nested loop approach to check if each element already exists in the result array
 * - Time Complexity: O(n²) where n is the size of the input array
 * - Space Complexity: O(n) for storing the new array without duplicates
 * 
 * 0 on successful execution
 */
int main() {
  int n;
  cout << "Enter the size of array "; // User input array
  cin >> n;
  int arr[n];
  cout << "Enter elements one by one ";
  
  // Loop through array to read n elements from user input
  for(int i = 0; i < n; i++) {
    cin >> arr[i]; 
    cout << " ";
  }

  int new_arr[n];  // Array to store unique elements
  int count = 0;   // Tracks number of unique elements found so far
  bool flag = false;  // Flag to check if current element is a duplicate

  // Outer loop: iterate through each element in the original array
  for(int i = 0; i < n; i++) { 
    
    flag = false;  // Reset flag for each new element
    
    // Inner loop: check if arr[i] already exists in new_arr
    for(int j = 0; j < count; j++) {
      
      // If current element matches an element already in new_arr, it's a duplicate
      if(new_arr[j] == arr[i]) {
        flag = true;  // Mark as duplicate
        break;  // Exit inner loop early since we found a match
      }
    }
  
    // If flag is false, element is not a duplicate
    if(!flag) {
      new_arr[count] = arr[i];  // Add unique element to new_arr
      count++;  // Increment count of unique elements
    }
  }
  
  // Loop through new_arr and print all unique elements
  for (int i = 0; i < count; i++) {
    cout << new_arr[i] << " ";
  }
}


