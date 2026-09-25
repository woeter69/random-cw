#include<iostream>
using namespace std;

int factorial_for(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result = result * i;
    }
    return result;
}

int factorial_while(int n) {
    int result = 1;
    int i = 1;
    while (i <= n) {
        result *= i;
        i++;
    }
    return result;
}

int factorial_do_while(int n) {
    int result = 1;
    int i = 1;
    do {
        result *= i;
        i++;
    } while (i <= n);
    return result;
}

int factorial_recursive(int n) {
    if (n <= 1) {
        return 1;
    }
    else {
        return n * factorial_recursive(n - 1);
    }
}
int main() {
    int n;
    cout << "Enter a number to calculate its factorial: ";
    cin >> n; 
    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
        return 1;
    }
    else {
        cout << "Factorial using for loop: " << factorial_for(n) << endl;
        cout << "Factorial using while loop: " << factorial_while(n) << endl;
        cout << "Factorial using do-while loop: " << factorial_do_while(n) << endl;
        cout << "Factorial using recursion: " << factorial_recursive(n) << endl;
    }
    return 0;      
}