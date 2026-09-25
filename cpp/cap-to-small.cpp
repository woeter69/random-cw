#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    char arr1[n], arr2[n]; // first array: input, second array: lowercase

    cout << "Enter characters:\n";
    for (int i = 0; i <= n; i++) {
        cin >> arr1[i];

        // convert uppercase to lowercase and store in second array
        if (arr1[i] >= 'A' && arr1[i] <= 'Z') {
            arr2[i] = arr1[i] + 32;
        } else {
            arr2[i] = arr1[i]; // keep as is
        }
    }

    cout << "Lowercase array: ";
    for (int i = 0; i <= n; i++) {
        cout << arr2[i];
    }
    cout << endl;

    return 0;
}
