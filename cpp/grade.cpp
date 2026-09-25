/*
Program: Grade Percentage Calculator
Description: Prompts the user for marks of five subjects, computes the total and
             percentage assuming each subject is out of 100 (total out of 500).

Sample I/O:
  Enter Marks of first subject: 
  80
  Enter Marks of second subject: 
  90
  Enter Marks of third subject: 
  85
  Enter Marks of fourth subject: 
  88
  Enter Marks of fifth subject: 
  92
  Total Marks: 435
  Percentage: 87

Note:
- Floating-point division is used to avoid dropping the decimal when computing percentage.
*/
#include<iostream>
using namespace std;

int main() {
    int a,b,c,d,e;
    cout << "Enter Marks of first subject: " << endl;
    cin >> a;
    cout << "Enter Marks of second subject: " << endl;
    cin >> b;
    cout << "Enter Marks of third subject: " << endl;
    cin >> c;
    cout << "Enter Marks of fourth subject: " << endl;
    cin >> d;
    cout << "Enter Marks of fifth subject: " << endl;
    cin >> e;
    int total = a+b+c+d+e;
    cout << "Total Marks: " << total << endl;
    // Use floating-point math to avoid integer-division dropping the decimal
    float percentage = (static_cast<float>(total) / 500.0) * 100.0;
    cout << "Percentage: " << percentage << endl;
    return 0;
}


