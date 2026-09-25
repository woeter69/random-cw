#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter rows: ";
    cin >> rows;
    cout << "Enter cols: ";
    cin >> cols;

    int arr[rows][cols], brr[rows][cols], crr[rows][cols];

    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> arr[i][j];

    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> brr[i][j];

    cout << "Sum of matrices:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            crr[i][j] = arr[i][j] + brr[i][j];
            cout << crr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
