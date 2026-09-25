#include <iostream>

using namespace std;

int strLength(char *str){
    int len = 0;
    while(*str != '\0'){
        len++;
        str++;
    }
    return len;
}

int main() {
  char str[100] = "Heyyouwhoyou";
  
  int len = strLength(str);

  cout << len;
}
