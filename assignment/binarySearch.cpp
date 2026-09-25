/**
 * @file binarySearch.cpp
 * @brief Implements iterative binary search algorithm
 * 
 * This program performs binary search on a sorted array to find a target element.
 * Binary search is an efficient O(log n) search algorithm that works by repeatedly
 * dividing the search interval in half.
 */

#include <iostream>

using namespace std;

/**
 * @brief Performs iterative binary search on a sorted array
 * 
 * Searches for a target element in a sorted array using the binary search algorithm.
 * The function repeatedly divides the search space in half until the element is found
 * or the search space is exhausted.
 * 
 * @param arr Pointer to the sorted array to search in
 * @param find The target element to search for
 * @param n The number of elements in the array
 * @return The index of the element if found, -1 otherwise
 * 
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * 
 * @note The array must be sorted in ascending order
 * @note Array should not contain duplicates for predictable results
 */
int binary_search(int *arr, int find, int n) {
  int left = 0, right = n-1;  // Initialize search boundaries
  
  // Continue searching while the search space is valid
  while (left <= right) {
    long mid = (left + right)/2;  // Calculate middle index
    
    // Element found at middle position
    if (find == arr[mid]) {
      return mid;
    }
    // Target is in the right half
    else if (find > arr[mid]) {
      left = mid + 1;  // Move left boundary to right of mid
    }
    // Target is in the left half
    else {
      right = mid - 1;  // Move right boundary to left of mid
    }
  }
  return -1;  // Element not found in array
}

/**
 * @brief Main function to test binary search implementation
 * 
 * Reads a sorted array and a target element from user input,
 * performs binary search, and displays the result.
 * 
 * @return 0 on successful execution (implicit)
 */
int main() {
  int arr[100];  // Array to store up to 100 elements
  int n;         // Number of elements in the array
  int find;      // Element to search for

  // Read array size from user
  cout << "Enter number of elements: ";
  cin >> n;
  
  // Read sorted array elements from user
  cout << "Enter a sorted array with no duplicates: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // Read target element to search for
  cout << "Enter element to be found: ";
  cin >> find;

  // Perform binary search and display result
  int ans = binary_search(arr, find, n);
  if (ans < 0) {
    cout << "Element not found ";
  }
  else {
    cout << "Element " << find << " Found on " << ans << " index\n";
  }
}
