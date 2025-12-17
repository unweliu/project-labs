#include "lab6.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

namespace lab6 {
    template<>
    Variance<int>::Variance(int n) {
        size = n;
        data = new int[n];
    }

    template<>
    Variance<int>::~Variance() {
        delete[] data;
    }

    template<>
    void Variance<int>::setValue(int index, int value) {
        data[index] = value;
    }

    template<>
    int Variance<int>::mean() {
        int sum = 0;
        for (int i = 0; i < size; i++)
            sum += data[i];
        return sum / size;
    }

    template<>
    int Variance<int>::compute() {
        double m = mean();
        double s = 0;
        for (int i = 0; i < size; i++)
            s += (data[i] - m) * (data[i] - m);
        return s / (size - 1);
    }

    template<>
    Variance<double>::Variance(int n) {
        size = n;
        data = new double[n];
    }

    template<>
    Variance<double>::~Variance() {
        delete[] data;
    }

    template<>
    void Variance<double>::setValue(int index, double value) {
        data[index] = value;
    }

    template<>
    double Variance<double>::mean() {
        double sum = 0;
        for (int i = 0; i < size; i++)
            sum += data[i];
        return sum / size;
    }

    template<>
    double Variance<double>::compute() {
        double m = mean();
        double s = 0;
        for (int i = 0; i < size; i++)
            s += (data[i] - m) * (data[i] - m);
        return s / (size - 1);
    }

    void demo() {
        setlocale(LC_ALL, "Russian");

        while (true) {
            int choice;
            cout << "Меню:\n";
            cout << "1. Целые числа\n";
            cout << "2. Вещественные числа\n";
            cout << "3. Выход\n";
            cout << "Выбор: ";
            cin >> choice;

            if (choice == 3) {
                cout << "Выход.\n";
                break;
            }

            if (choice != 1 && choice != 2) {
                cout << "Неверный выбор.\n";
                continue;
            }

            int n;
            cout << "Введите n: ";
            cin >> n;

            if (choice == 1) {
                Variance<int> var(n);
                cout << "Введите " << n << " целых чисел:\n";
                for (int i = 0; i < n; i++) {
                    double x;
                    while (true) {
                        cin >> x;
                        if (!cin.fail() && x == (int)x) {
                            var.setValue(i, (int)x);
                            break;
                        }
                        cout << "Ошибка. Введите новое число.\n";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                }
                cout << "Дисперсия = " << var.compute() << "\n";
            }
            else {
                Variance<double> var(n);
                cout << "Введите " << n << " вещественных чисел:\n";
                for (int i = 0; i < n; i++) {
                    double x;
                    cin >> x;
                    var.setValue(i, x);
                }
                cout << "Дисперсия = " << var.compute() << "\n";
            }
        }
    }

}