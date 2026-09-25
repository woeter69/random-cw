#include <iostream>
using namespace std;

int main () {
  int n;
  cout << "Enter how many elements in Array ";
  cin >> n;
  int arr[n];
  cout << "Enter Numbers one by one" << endl; 
  
  for (int i = 1; i <=n; i++) {
    cin >> arr[i];
  }

  cout<< "Stored Marks are" << endl;
  
  for (int i = 1; i<=n; i++) {
    cout << arr[i] << endl;
  }

  return 0;
}

