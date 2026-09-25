#include <iostream>
using namespace std;

int main() {
    cout << "=== BASIC LOOPS IN C++ ===" << endl << endl;
    
    // 1. FOR LOOP
    cout << "1. FOR LOOP:" << endl;
    cout << "Counting from 1 to 5:" << endl;
    for(int i = 1; i <= 5; i++) {
    for(int i = 1; i <= 5; i++) {
        cout << "   " << i << endl;
    }
    
    // 2. WHILE LOOP
    cout << "\n2. WHILE LOOP:" << endl;
        cout << "   " << i << endl;
    }
    
    // 2. WHILE LOOP
    cout << "\n2. WHILE LOOP:" << endl;
    cout << "Countdown from 5:" << endl;
    int count = 3;
    while(count > 0) {
        cout << "   " << count << endl;
        count--;
    }
    cout << "   Blast off!" << endl;
    
    // 3. DO-WHILE LOOP
    cout << "\n3. DO-WHILE LOOP:" << endl;
    cout << "Printing numbers 1 to 3:" << endl;
    int num = 1;
    do {
        cout << "   " << num << endl;
        num++;
    } while(num <= 3);
    
    cout << "\n=== END ===" << endl;
    return 0;
}


