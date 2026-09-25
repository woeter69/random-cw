#include <iostream>
using namespace std;

int pattern(int n) {
     for(int i = 1;i <=n; i++) {
       for(int j = 1;j<=n; j++) {
        int val = (((i + j -1) * (i+j-2))/2);
        if ((i+j) % 2 == 1){
            cout << (val+j) << " ";
        }
        else {
            cout << (val+i) << " ";
        }
       }
      cout << endl;
     }
     return 0;
}

int main() {
  pattern(4);
  return 0;
}