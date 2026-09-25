/**
 * @file binarySearchrec.cpp
 * @brief Implements recursive binary search algorithm
 * 
 * This program performs binary search on a sorted array using recursion.
 * Binary search is an efficient O(log n) search algorithm that works by
 * recursively dividing the search interval in half.
 */

#include <iostream>

using namespace std;

/**
 * @brief Performs recursive binary search on a sorted array
 * 
 * Searches for a target element in a sorted array using recursive binary search.
 * The function recursively divides the search space in half until the element
 * is found or the search space is exhausted.
 * 
 * @param arr Pointer to the sorted array to search in
 * @param left Left boundary index of the current search space
 * @param right Right boundary index of the current search space
 * @param find The target element to search for
 * @return The index of the element if found, -1 otherwise
 * 
 * Time Complexity: O(log n)
 * Space Complexity: O(log n) due to recursion stack
 * 
 * @note The array must be sorted in ascending order
 * @note Array should not contain duplicates for predictable results
 */
int binary_search(int *arr, int left, int right, int find) {
    // Base case: search space is exhausted, element not found
    if (left > right)
        return -1;

    int mid = (left + right)/2;  // Calculate middle index

    // Element found at middle position
    if (arr[mid] == find) {
      return mid;
    }
    // Target is in the right half, search right recursively
    else if (arr[mid] < find){
      return binary_search(arr, mid + 1, right, find);
    }
    // Target is in the left half, search left recursively
    else {
      return binary_search(arr, left, mid - 1, find);
    }
}

/**
 * @brief Main function to test recursive binary search implementation
 * 
 * Reads a sorted array and a target element from user input,
 * performs recursive binary search, and displays the result.
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
  
  // Initialize search boundaries and perform binary search
  int left = 0, right = n - 1;
  int ans = binary_search(arr, left, right, find);
  
  // Display search result
  if (ans < 0) {
    cout << "Element not found ";
  }
  else {
    cout << "Element " << find << " Found on " << ans << " index\n";
  }
}

