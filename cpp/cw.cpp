#include<iostream>
using namespace std;

void swap(int &a,int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int main() {
    int x = 6;
    int y = 7;
    swap(x,y);
    cout << x << endl << y;
}



