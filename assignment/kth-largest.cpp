#include <iostream>
using namespace std;

/**
 * @brief Finds the kth largest element in an array
 * 
 * This function iteratively finds the kth largest element by repeatedly
 * finding the largest element that is smaller than the previous largest.
 * 
 * Algorithm:
 * - Iterates k times to find progressively smaller largest elements
 * - In each iteration, finds the largest element smaller than the previous one
 * - Time Complexity: O(k*n) where n is array size and k is the position
 * - Space Complexity: O(1) - uses only constant extra space
 * 
 * @param arr[] The input array of integers
 * @param n The size of the array
 * @param k The position of the largest element to find (1-indexed)
 * @return The kth largest element in the array
 * 
 * @note This implementation assumes k is valid (1 <= k <= n)
 * @note Array elements should be initialized properly for correct results
 */
int kthLargest(int arr[], int n, int k) {
    int largest = 0;  // Stores the current largest element found
    int prevLargest;  // Stores the previous largest to find next smaller largest

    // Loop k times to find the kth largest element
    // Each iteration finds the next largest element smaller than the previous one
    for (int i = 0; i < k; i++) {
        prevLargest = largest;  // Save current largest as upper bound for next search
        largest = 0;  // Reset largest to find next smaller value
        
        // Loop through entire array to find largest element less than prevLargest
        for (int j = 0; j < n; j++) {
            // Check if current element is larger than our current largest
            // AND smaller than the previous largest (to get next in descending order)
            if (arr[j] > largest && arr[j] < prevLargest) {
                largest = arr[j];  // Update largest with this element
            }
        }
    }
    return largest;  // After k iterations, largest holds the kth largest element
}

/**
 * @brief Main function to test the kthLargest function
 * 
 * Reads an array and a value k from user input, then finds and displays
 * the kth largest element in the array.
 * 
 * @return 0 on successful execution
 */
int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    
    // Loop to read n elements from user input into the array
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int k;
    cout << "Enter Kth term";
    cin >> k;

    int ans = kthLargest(arr, n, k);  // Call function to find kth largest

    cout << "Kth Lagrest term is " << ans;

    return 0;
}
