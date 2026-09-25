#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Enter a number to print its table: ";
    cin >> a;

    int b = 1;
    do {
        cout << a << " x " << b << " = " << a * b << endl;
        b++;
    } while (b <= 10);

    return 0;
}
