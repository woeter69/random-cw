#include <iostream>

using namespace std;

class Employee {
  public:
    string Name;
    string Company;
    int Age;

    void Hello() {
      cout << "Name: " << Name << endl;
      cout << "Company: " << Company << endl;
      cout << "Age: " << Age << endl;
    }
};

int main() {
  Employee John;
  John.Name = "John";
  John.Company = "Google";
  John.Age = 33;

  John.Hello();
}
