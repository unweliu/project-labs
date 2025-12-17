#include "lab3.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

namespace lab3 {

    Sequence::Sequence(int n) {
        size = n;
        arr = new int[size];
    }

    Sequence::~Sequence() {
        delete[] arr;
    }

    void Sequence::inputManual() {
        cout << "Введите " << size << " целых чисел:\n";
        for (int i = 0; i < size; i++) {
            cout << i + 1 << " элемент: ";
            cin >> arr[i];
        }
    }

    void Sequence::inputAuto() {
        srand(static_cast<unsigned>(time(0)));
        for (int i = 0; i < size; i++) {
            arr[i] = -20 + rand() % 51;
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void Sequence::process() {
        bool hasLessThan10 = false;
        for (int i = 0; i < size; i++) {
            if (arr[i] < 10) {
                hasLessThan10 = true;
                break;
            }
        }

        if (hasLessThan10) {
            for (int i = 0; i < size; i++) {
                if (arr[i] < 0) arr[i] *= arr[i];
            }
        }
        else {
            for (int i = 0; i < size; i++) arr[i] *= 2;
        }
    }

    void Sequence::output() const {
        cout << "Результат:\n";
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }

    void demo() {
        setlocale(LC_ALL, "Russian");

        int N;
        cout << "Введите количество элементов N: ";
        cin >> N;

        if (N <= 0) {
            cout << "Ошибка.\n";
            return;
        }

        Sequence seq(N);

        int choice;
        cout << "\nСпособ ввода:\n1. Вручную\n2. Автоматически\nВаш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: seq.inputManual(); break;
        case 2: seq.inputAuto(); break;
        default:
            cout << "Неверный выбор.\n";
            return;
        }

        seq.process();
        seq.output();
    }

}