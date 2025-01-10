#include "math_operations.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Функция для умножения двух чисел, представленных строками
string multistr(const string& num1, const string& num2) {
    if (num1 == "0" and num2 == "0") return "0";

    int n = num1.size();
    int m = num2.size();
    int res_size = n + m;
    int result[res_size];

    // Инициализируем массив результата нулями
    for (int i = 0; i < res_size; ++i) {
        result[i] = 0;
    }

    // Проходим по каждой цифре числа num1 с конца к началу
    for (int i = n - 1; i >= 0; --i) {
        // Проходим по каждой цифре числа num2 с конца к началу
        for (int j = m - 1; j >= 0; --j) {
            // Умножаем текущие цифры num1 и num2
            int mul = (num1[i] - '0') * (num2[j] - '0');

            // Находим позиции в массиве результата для записи суммы
            int p1 = i + j;
            int sum = mul + result[p1 + 1];

            // Записываем результат умножения в массив результата
            result[p1 + 1] = sum % 10; // Текущая цифра
            result[p1] += sum / 10; // Перенос
        }
    }

    // Преобразуем массив результата в строку
    string res_str;
    int leadingZero = 1;
    for (int i = 0; i < res_size; ++i) {
        // Пропускаем ведущие нули
        if (leadingZero == 1 && result[i] == 0) continue;
        leadingZero = 0;
        res_str.push_back(result[i] + '0');
    }

    // Возвращаем результат в виде строки (или "0", если результат пустой)
    if (res_str.empty()) {
        return "0";
    } else {
        return res_str;
    }
}

// Функция для вычисления факториала числа, представленного строкой
string factorial(const string& num_str) {
    int num = stoi(num_str); // Преобразуем строку в целое число
    string result = "1";
    for (int i = 2; i <= num; ++i) {
        result = multistr(result, to_string(i));
    }
    return result;
}

bool truenumber(const string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    int number = stoi(str);
    return number > 10;
}

// Функция для реверсирования строки
void reverse(string& str) {
    int n = str.length();
    for (int i = 0; i < n / 2; ++i) {
        // Обмениваем символы местами
        char temp = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = temp;
    }
}

// Функция для сложения двух чисел, представленных строками
string sumstr(const string& num1, const string& num2) {
    string result = ""; // Результирующая строка для хранения суммы
    int ost = 0; // Переменная для переноса (остаток)
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    // Проходим по цифрам с конца к началу
    while (i >= 0 or j >= 0 or ost) {
        int sum = ost; // Начинаем с переноса (остатка)

        // Добавляем цифру из строки num1, если индекс в пределах строки
        if (i >= 0) {
            char digit = num1[i] - '0'; // Получаем цифру из строки num1
            sum += digit;
            i--; // Уменьшаем значение i
        }

        // Добавляем цифру из строки num2, если индекс в пределах строки
        if (j >= 0) {
            char digit = num2[j] - '0'; // Получаем цифру из строки num2
            sum += digit;
            j--; // Уменьшаем значение j
        }

        // Добавляем результат текущей суммы % 10 к результирующей строке
        result += to_string(sum % 10);

        // Обновляем перенос (остаток)
        ost = sum / 10;
    }

    // Реверсируем строку результата, так как цифры добавлялись в обратном порядке
    reverse(result);

    return result;
}


