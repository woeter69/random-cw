#include <iostream>
using namespace std;
int main (){

  int a = 5;
  int b = 10;

  int *p = &a;
  int *q = &b;
  cout << *p << endl;
  cout << *q;
}

