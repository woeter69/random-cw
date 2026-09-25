#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i == 20) {
            cout << "Loop terminated at 20" << endl;
            break;
        }
        cout << i << " ";
    }
}