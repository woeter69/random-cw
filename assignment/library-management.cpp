#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Book{
  int bookId;
  char title[50];
  char author[50];
  int totalQuantity;
  int issueCount;
};

Book library[100];

int book_count = 0;

void addBook() {
  int bookId;
  bool found = false;

  cout << "Enter book Id: ";
  cin >> bookId;
  

  for (int i = 0; i < book_count; i++) {
    if (library[i].bookId == bookId) {
      cout << "Book already exist!";
      found = true;
      break;
    }
  }
  
  if (!found) {
    library[book_count].bookId = bookId;

    cout << "Enter title of the book: ";

    cin.ignore();
    cin.getline(library[book_count].title, 50);

    cout << "Enter author of the book: ";
    cin.getline(library[book_count].author, 50);

    cout << "Enter total quantity of this book: ";
    cin >> library[book_count].totalQuantity;
  
    book_count++;
  }
}

void displayAllBooks() {
  cout << "Currently there are " << book_count << " unique books in the records" << endl;

  for (int i = 0; i < book_count; i++) {

    cout << "----------------------------------------------------------------" << endl;
    cout << "Book Id: " << library[i].bookId << endl;
    cout << "Book Title: " << library[i].title << endl;
    cout << "Author: " << library[i].author << endl;
    cout << "Current Quantity: " << (library[i].totalQuantity - library[i].issueCount) << endl;
  }
}

void findBook(int find_id, char find_title[50]) {
  bool found = false;
  for (int i = 0; i < book_count; i++) {
    if (find_id == library[i].bookId || (strcmp(find_title, library[i].title) == 0)) {
      cout << "Book found for BookId: " <<library[i].bookId << endl;
      cout << "Book Id: " << library[i].bookId << endl;
      cout << "Title: " << library[i].title << endl;
      cout << "Author: " << library[i].author << endl;
      cout << "Current Quantity: " << (library[i].totalQuantity - library[i].issueCount) << endl;
      found = true;

      break;
    }
  }
  if(!found) {
    cout << "Book not found for Book Id or Title: " << find_id << find_title;  
  }
}

void issueBook(int bookId) {
  for (int i = 0; i < book_count; i++) {
    if (library[i].bookId == bookId && (library[i].totalQuantity - library[i].issueCount > 0)) {
      library[i].issueCount++;
      cout << "Book issued!" << endl;
    }
  }
}

void returnBook(int bookId) {
  for (int i = 0; i < book_count; i++) {
    if (library[i].bookId == bookId) {
      library[i].issueCount--;
      cout << "Book issued!" << endl;
    }
  }
}

void addToFile() {
  fstream file;
  file.open("library.txt", ios::out);

  if (!file.is_open()) {
    cerr << "ERROR: Could not open library.txt for saving. Check permissions or file path." << endl;
    return;
  }
  for (int i = 0; i < book_count; i++) {
    file << library[i].bookId << " ";
    file << library[i].title << " ";
    file << library[i].author << " ";
    file << library[i].totalQuantity << " ";
    file << library[i].issueCount << endl;
  }
  file.close();
}

void getFromFile() {
  fstream file;
  file.open("library.txt", ios::in);

  if (!file.is_open()) {
    cerr << "ERROR: Could not open library.txt for saving. Check permissions or file path." << endl;
    return;
  }
  
  int stored_book_count = 0;
  
  Book stored_library[100];
while (stored_book_count < 100 && (file >> stored_library[stored_book_count].bookId         
                             >> stored_library[stored_book_count].title         
                             >> stored_library[stored_book_count].author        
                             >> stored_library[stored_book_count].totalQuantity 
                             >> stored_library[stored_book_count].issueCount)) { 
    
    stored_book_count++; 
}

  if (stored_book_count > 0) {
    for (int i = 0; i < stored_book_count; i++) {
      library[i] = stored_library[i];
    }
    book_count = stored_book_count;
    cout << "Loaded books!" << endl;
  }
  else {
    book_count = 0;
    cout << "Couldn't load library. starting a new one. " << endl;
  }
  file.close();
}

int main() {
  getFromFile();

  cout << "1. Display All Books" << endl;
  cout << "2. Add Book" << endl;
  cout << "3. Issue Book" << endl;
  cout << "4. Return Book" << endl;
  cout << "5.  Find a book" << endl;

  int choice;
  cout << "\nEnter your choice: ";
  cin >> choice;

  switch(choice) {
    case 1:
      displayAllBooks();
      break;
    case 2:
      addBook();
      addToFile();
      break;
    case 3:
      displayAllBooks();
      int issue_bookId;
      cout << "Enter bookId to issue the book: ";
      cin >> issue_bookId;
      issueBook(issue_bookId);
      addToFile();
      break;
    case 4:
      int return_bookId;
      cout << "Enter bookId to return the book: ";
      cin >> return_bookId;
      returnBook(return_bookId);
      addToFile();
      break;
    case 5:
      int find_bookId;
      char find_title[50];
      cout << "Enter bookId to find the book: ";
      cin >> find_bookId;
      cout << "Enter Title to find the book: ";
      cin.ignore();
      cin.getline(find_title,50);
      findBook(find_bookId, find_title);
      break;
    default:
      cout << "Invalid choice" << endl;
      break;
  }

}

