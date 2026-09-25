/**
 * @file mergeArr.cpp
 * @brief Merges two sorted arrays into a single sorted array
 * 
 * This program demonstrates the merge operation used in merge sort.
 * It takes two sorted arrays and combines them into a single sorted array
 * while maintaining the sorted order.
 */

#include <iostream>

using namespace std;

/**
 * @brief Main function to merge two sorted arrays
 * 
 * Reads two sorted arrays from user input, merges them using the two-pointer
 * technique, and displays the merged sorted array.
 * 
 * @return 0 on successful execution (implicit)
 */
int main() {
  int arr1[50];     // First sorted array
  int arr2[50];     // Second sorted array
  int result[100];  // Merged result array

  int n1;  // Length of first array
  int n2;  // Length of second array
  
  // Read array lengths
  cout << "Enter length of array 1: ";
  cin >> n1;
  cout << "Enter length of array 2: ";
  cin >> n2;

  // Read elements of first sorted array
  cout << "Enter elements are array 1: ";
  for (int i = 0; i < n1; i++) {
    cin >> arr1[i];
  }
  
  // Read elements of second sorted array
  cout << "Enter elements of array 2: ";
  for (int i = 0; i < n2; i++) {
    cin >> arr2[i];
  }

  int i = 0, j = 0, k = 0;  // Indices for arr1, arr2, and result

  // Merge arrays by comparing elements from both arrays
  while (i < n1 && j < n2) {
    if (arr1[i] < arr2[j]) {
      result[k] = arr1[i];  // Take element from arr1
      k++;
      i++;
    }
    else {
      result[k] = arr2[j];  // Take element from arr2
      k++;
      j++;
    }
  }
  
  // Copy remaining elements from arr1 (if any)
  while (i < n1) {
    result[k] = arr1[i];
    i++;
    k++;
  }

  // Copy remaining elements from arr2 (if any)
  while (j < n2) {
    result[k] = arr2[j];
    k++;
    j++;
  }
  
  // Display merged array using pointer arithmetic
  int *ptrResult = &result[0];
  for (int x = 0; x < k; x++) {
    cout << *ptrResult << " ";
    ptrResult++;  // Move pointer to next element
  }
}
