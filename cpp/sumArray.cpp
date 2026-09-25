#include <iostream>

using namespace std;

int main() {
  int a,b,c,d,e;

  cout << "Enter numbers one by one separated for spaces: ";

  cin >> a >> b >> c >> d >> e;
  
  cout << "Sum of 5 numbers: " << a + b + c + d + e;

}

int sumArray(int arr[], int size) {
  int sum = 0; 
  for (int i = 0; i < size; i++) {
    sum = sum + arr[i];
  }
  return sum;
}

// Array decay to pointer when passed to a function it. int *arr and int arr[] are the same things.  
