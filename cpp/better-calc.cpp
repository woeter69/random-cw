#include<iostream>
using namespace std;

void add(int a,int b) {
  cout << "Addition is = " << a+b << endl;
}

void sub(int a,int b) {
  cout << "Subtraction is = " << a-b << endl;
}

void mul(int a,int b) {
  cout << "Multiplication is = " << a*b << endl;
}

void divi(int a,int b) {
  cout << "Division is = " << a/b << endl;
}

void remi(int a,int b) {
  cout << "Remainder is = " << a%b << endl;
}

int main() {
  int a;
  int b;
  cout << "Enter first number ";
  cin >> a;
  cout << "Enter second number ";
  cin >> b;
  add(a,b);
  sub(a,b);
  mul(a,b);
  divi(a,b);
  remi(a,b);
}