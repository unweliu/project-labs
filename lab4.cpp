#include "lab4.h"
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

namespace lab4 {
    VECTOR::VECTOR(int n, float value) {
        this->n = n;
        for (int i = 0; i < n; i++)
            A[i] = value;
    }

    VECTOR::VECTOR(int n) {
        this->n = n;
    }

    VECTOR::VECTOR() {
        n = 0;
    }

    VECTOR VECTOR::Add(const VECTOR& what) const {
        VECTOR result(n);
        for (int i = 0; i < n; i++)
            result.A[i] = A[i] + what.A[i];
        return result;
    }

    VECTOR VECTOR::Cmul(float what) const {
        VECTOR result(n);
        for (int i = 0; i < n; i++)
            result.A[i] = A[i] * what;
        return result;
    }

    float VECTOR::Norm() const {
        float sum = 0;
        for (int i = 0; i < n; i++)
            sum += A[i] * A[i];
        return std::sqrt(sum);
    }

    void VECTOR::Normalize() {
        float norm = Norm();
        if (norm == 0) {
            cout << "Невозможно нормировать.\n";
            return;
        }
        for (int i = 0; i < n; i++)
            A[i] /= norm;
    }

    void VECTOR::Print() const {
        for (int i = 0; i < n; i++)
            cout << A[i] << " ";
        cout << endl;
    }

    VChild::VChild(int n, float value) : VECTOR(n, value) {}
    VChild::VChild(int n) : VECTOR(n) {}
    VChild::VChild() : VECTOR() {}

    VECTOR VChild::Add(const VECTOR& what) const {
        cout << "Выполнено сложение (Child)\n";
        return VECTOR::Add(what);
    }

    VECTOR VChild::Cmul(float what) const {
        cout << "Выполнено умножение (Child)\n";
        return VECTOR::Cmul(what);
    }

    float VChild::Norm() const {
        cout << "Вычислена норма (Child)\n";
        return VECTOR::Norm();
    }

    void VChild::Normalize() {
        cout << "Выполнено нормирование (Child)\n";
        VECTOR::Normalize();
    }

    void VChild::Print() const {
        cout << "Вектор (Child): ";
        VECTOR::Print();
    }

    void demo() {
        setlocale(LC_ALL, "Russian");

        int n;
        float val1, val2, k;

        cout << "Размерность векторов: ";
        cin >> n;

        cout << "Значение для первого вектора: ";
        cin >> val1;

        cout << "Значение для второго вектора: ";
        cin >> val2;

        VChild v1(n, val1);
        VChild v2(n, val2);

        cout << "\nИсходные векторы:\n";
        v1.Print();
        v2.Print();

        VECTOR v_sum = v1.Add(v2);
        cout << "\nСумма: ";
        v_sum.Print();

        cout << "\nЧисло для умножения: ";
        cin >> k;

        VECTOR v1_mul = v1.Cmul(k);
        VECTOR v2_mul = v2.Cmul(k);

        cout << "\nРезультаты умножения:\n";
        v1_mul.Print();
        v2_mul.Print();

        cout << "\nНормирование:\n";
        v1.Normalize(); v1.Print();
        v2.Normalize(); v2.Print();
    }

}