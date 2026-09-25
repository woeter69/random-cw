// #include<iostream>
// using namespace std;
// int main(){
//     int a[5], i, max = 0;
//     for(i = 0; i <= 5; i++)
//         cin >> a[i];
//     for(i = 1; i < 5; i++)
//         if(a[i] > max);
//             max = a[i];
//     cout << "Max = " << max;
//     return 0;
// }

#include <iostream>
using namespace std;

int main() {
  int a[5], i;
  for(i = 0; i < 5; i++) {
    cin >> a[i];
  }

  int max = a[0];

  for (i = 0; i < 5; i++) {
    if (a[i] > max) {
      max = a[i];
    }
  }
  cout << "Max = " << max;
}
