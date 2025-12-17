#include <iostream>
#include "lab1.h"
#include "lab2.h"
#include "lab3.h"
#include "lab4.h"
#include "lab5.h"
#include "lab6.h"
#include "lab7.h"

using namespace std;

int main() {

    while (true) {
        setlocale(LC_ALL, "Russian");
        int choice;
        cout << "\nВыберите лабораторную работу:\n";
        cout << "1. Лабораторная работа №1\n";
        cout << "2. Лабораторная работа №2\n";
        cout << "3. Лабораторная работа №3\n";
        cout << "4. Лабораторная работа №4\n";
        cout << "5. Лабораторная работа №5\n";
        cout << "6. Лабораторная работа №6\n";
        cout << "7. Лабораторная работа №7\n";
        cout << "0. Выход\n";
        cout << "\nВаш выбор: ";
        cin >> choice;
        cout << "\n";

        if (choice == 0) {
            cout << "Выход из программы.\n";
            break;
        }

        switch (choice) {
        case 1: lab1::demo(); break;
        case 2: lab2::demo(); break;
        case 3: lab3::demo(); break;
        case 4: lab4::demo(); break;
        case 5: lab5::demo(); break;
        case 6: lab6::demo(); break;
        case 7: lab7::demo(); break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}