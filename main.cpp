#include "math_operations.h"
#include <iostream>
#include <string>
#include <cctype>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    string n;

    cout << "Введите целое число больше 10: ";
    while (true) {
        cin >> n;
        if (truenumber(n)) {
            cout << "Вы ввели корректное число: " << n << endl;
            break;
        } else {
            cout << "Ошибка: Введите целое число больше 10: ";
        }
    }
    string sum;
    for (int i = 1; i <= stoi(n); i++ ) {
        string fact = factorial(to_string(i));
        sum = sumstr(sum, fact);
    }
    cout << "Ответ: " << sum;
}
