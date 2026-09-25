#include <iostream>
#include <fstream>
using namespace std;

struct studentRecord {
    int rollNo;
    char name[50];
    int marks1, marks2, marks3, marks4, marks5;
};

int totalMarks(studentRecord s) {
    return s.marks1 + s.marks2 + s.marks3 + s.marks4 + s.marks5;
}

float avgMarks(studentRecord s) {
    return totalMarks(s) / 5.0;
}

void saveToFile(studentRecord s[], int n) {
    ofstream file("students.txt");
    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        file << s[i].rollNo << " "
             << s[i].name << " "
             << s[i].marks1 << " "
             << s[i].marks2 << " "
             << s[i].marks3 << " "
             << s[i].marks4 << " "
             << s[i].marks5 << "\n";
    }

    file.close();
    cout << "Data saved to students.txt\n";
}

void readFromFile() {
    ifstream file("students.txt");
    int highestMarks = 0;

    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    studentRecord s;
    while (file >> s.rollNo >> s.name >> s.marks1 >> s.marks2 >> s.marks3 >> s.marks4 >> s.marks5) {

        int total = totalMarks(s);
        float avg = avgMarks(s);

        cout << "\nRoll No: " << s.rollNo
             << "\nName: " << s.name
             << "\nMarks: " << s.marks1 << " " << s.marks2 << " "
             << s.marks3 << " " << s.marks4 << " " << s.marks5
             << "\nTotal: " << total
             << "\nAverage: " << avg << "\n";
        
        if (total > highestMarks) {
          highestMarks = total;
        }

    }

    cout << "\nHighest Marks: " << highestMarks << "\n";



    file.close();
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    studentRecord students[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter roll number: ";
        cin >> students[i].rollNo;

        cout << "Enter name: ";
        cin >> students[i].name;

        cout << "Enter marks for 5 subjects (0–100): ";
        cin >> students[i].marks1 >> students[i].marks2 >> students[i].marks3
            >> students[i].marks4 >> students[i].marks5;

        // Validation loop
        while (students[i].marks1 > 100 || students[i].marks2 > 100 ||
               students[i].marks3 > 100 || students[i].marks4 > 100 ||
               students[i].marks5 > 100 ||
               students[i].marks1 < 0 || students[i].marks2 < 0 ||
               students[i].marks3 < 0 || students[i].marks4 < 0 ||
               students[i].marks5 < 0) {
            cout << "Marks must be between 0 and 100. Re-enter all 5 marks: ";
            cin >> students[i].marks1 >> students[i].marks2 >> students[i].marks3
                >> students[i].marks4 >> students[i].marks5;
        }
    }

    saveToFile(students, n);
    readFromFile();
    return 0;
}
