// calculater project in c++ 
#include <iostream>
using namespace std;

int main() {
  int num1, num2;
  char operation;

  cout << "Enter first number: ";
  cin >> num1;

  cout << "Enter second number: ";
  cin >> num2;

  cout << "Enter operation (+, -, *, /): ";
  cin >> operation;

  switch (operation) {
    case '+':
      cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
      break;
    case '-':
      cout << num1 << " - " << num2 <<"=" << num1 - num2 << endl;
    break;
    case '*':
      cout << num1 << " * " << num2 <<"=" << num1 * num2 << endl;
    break;
    default :
      cout << num1 << " / " << num2 <<"=" << num1 / num2 << endl;
    break;
  }
   return 0;
}
