#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Student{
  int rollNo;
  char name[100];
  float percentage;
  char grade;
  int marks[5];
};

Student records[100];

int studentCount = 0;

void addStudent() {
  if (studentCount <= 100) {
    cout << "Database is full! ";
  }

  cout << "Add New Student\n";
  cout << "Enter Roll no: ";
  cin >> records[studentCount].rollNo;

  cout << "Enter Student Name: ";
  cin >>  records[studentCount].name;
  
  float total = 0;
  for (int i = 0; i<5; i++) {
    cout << "Enter marks of subject " << i+1 << endl;
    cin >> records[studentCount].marks[i];

    total = total + records[studentCount].marks[i];
  }

  records[studentCount].percentage = (total/500)*100;

  if (records[studentCount].percentage >= 90.00) {
    records[studentCount].grade = 'A';
  }
  
  else if (records[studentCount].percentage >= 80.00 && records[studentCount].percentage < 90.00) {
    records[studentCount].grade = 'B';
  }

  else if (records[studentCount].percentage >= 70.00 && records[studentCount].percentage < 80.00) {
    records[studentCount].grade = 'C';
  }
  
  else {
    records[studentCount].grade = 'D';
  }

  studentCount++;

  cout << "Student Added Successfully!" << endl;
  

}

void searchRecords() {
  if (studentCount<=0) {
    cout << "No Records Found! " << endl;
  }
  
  int choice;
  cout << "1.Search Using Roll Number." << endl;
  cout << "2.Search Using Name." << endl;

  cin >> choice;
  
  bool found = false;

  if (choice == 1) {
    int searchRollNo;
    cout << "Enter Roll No to be searched: ";
    cin >> searchRollNo;

    for (int i = 0; i<studentCount; i++) {
      if (searchRollNo == records[i].rollNo) {
        cout << "Record found!" << endl;
        
        cout << "Roll No: " << searchRollNo << endl;
        cout << "Name: " << records[i].name;
        for (int j = 0; j < 5; j++) {
          cout << "Marks of Subject " << i+1 << ": " << records[i].marks[j] << endl;
        }
        cout << "Percentage: " << records[i].percentage;
        cout << "Grade: " << records[i].grade;
        found = true;
        break;
      }
    }
  }
  
  if (choice == 2) {
    char searchName[100];
    cout << "Enter Name to be searched: ";
    cin >> searchName;

    for (int i = 0; i<studentCount; i++) {
      if (strcmp(searchName,records[i].name) == 0) {
        cout << "Record found!" << endl;
        
        cout << "Roll No: " << searchName << endl;
        cout << "Name: " << records[i].name;
        for (int j = 0; j < 5; j++) {
          cout << "Marks of Subject " << j+1 << ": " << records[i].marks[j] << endl;
        }
        cout << "Percentage: " << records[i].percentage;
        cout << "Grade: " << records[i].grade;
        found = true;
        break;
      }
    }
  }

  if (!found) {
    cout << "Student not found in records " << endl;
  }
}

void modifyRecords() {
  if (studentCount <= 0) {
    cout << "No Records to modify.. " << endl;
  }

  int modifyRollno;
  
  cout << "Enter roll no of the student you want to modify: ";
  cin >> modifyRollno;

  bool found = false;

  for (int i = 0; i < studentCount; i++) {
    if (modifyRollno == records[i].rollNo) {
      cout << "Record Found! " << endl;
      cout << "Record found for " << records[i].name;
      found = true;

      cout << "-------------------------------------------" << endl;
      
      cout << "Enter new Roll no: ";
      cin >> records[i].rollNo;

      cout << "Enter new Student Name: ";
      cin >>  records[i].name;
  
      float total = 0;
      for (int j = 0; j<5; j++) {
        cout << "Enter new marks of subject " << j+1 << endl;
        cin >> records[i].marks[j];

        total = total + records[i].marks[j];
      }

      records[i].percentage = (total/500)*100;

      if (records[i].percentage >= 90.00) {
        records[i].grade = 'A';
      }
  
      else if (records[i].percentage >= 80.00 && records[i].percentage < 90.00) {
        records[i].grade = 'B';
      }

      else if (records[i].percentage >= 70.00 && records[i].percentage < 80.00) {
        records[i].grade = 'C';
      }
  
      else {
        records[i].grade = 'D';
    }

    }
  }
}

void displayAllRecords() {
  if (studentCount <= 0) {
    cout << "No Recond to show...";
  }

  for (int i = 0; i < studentCount; i++) {
    cout << "Roll No:" << records[i].rollNo << endl;
    cout << "Name: " << records[i].name << endl;
    for (int j = 0; j < 5; j++) {
      cout << "Marks of Subject " << j+1 << ": " << records[i].marks[j] << endl;
    }
    cout << "Percentage: " << records[i].percentage;
    cout << "Grade: " << records[i].grade;

    cout << "---------------------------------------------------" << endl;
  }
}

void saveToFile() {
  ofstream file("studentrecords.txt");

  file << studentCount << endl;

  for (int i = 0; i < studentCount; i++) {
    file << records[i].rollNo << endl;
    file << records[i].name << endl;
    for (int j = 0; j<5; j++) {
      file << records[i].marks[j] << endl;
    }
    file << records[i].percentage << endl;
    file << records[i].grade << endl;

    file << endl;
  }
  file.close();
}

void loadFromFile() {
  ifstream file("studentrecords.txt");

  file >> studentCount;

  for (int i = 0; i < studentCount; i++) {
    file >> records[i].rollNo;
    file >> records[i].name;
    for (int j = 0; j < 5; j++) {
      file >> records[i].marks[j];
    }
    file >> records[i].percentage;
    file >> records[i].grade;
  }
}

int main() {
  
  loadFromFile();

  int choice;

  do {
    cout << "--Welcome to Student Records--"<< endl;
    cout << "1.Add a Student" << endl;
    cout << "2.Display Records" << endl;
    cout << "3.Search Records" << endl;
    cout << "4.Modify Records" << endl;
    cout << "0.Exit" << endl;
    cout << "------------------------------"<<endl;
    cout << "Enter your choice: ";

    cin >> choice;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(10000,'\n');
      cout << "Invalid input. Enter a number from above selection!" << endl;
      continue;
    }

    switch(choice){
      case 1:
        addStudent();
        break;
      case 2:
        displayAllRecords();
        break;
      case 3:
        searchRecords();
        break;
      case 4:
        modifyRecords();
        break;
      case 0:
        saveToFile();
        break;
    }
  } while(choice!=0);

  return 0;
}

