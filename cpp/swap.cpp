#include <iostream>
using namespace std;

int swap(int *a,int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
  return 0;
}

int main() {
  int a;
  int b;
  cout << "Enter First Number to swap";
  cin >> a;
  cout << "Enter Second Number to swap";
  cin >> b;
  swap(&a,&b);
  cout << "After swapping: a = " << a << ", b = " << b << endl;
  return 0;
}

