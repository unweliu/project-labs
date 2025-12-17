#include "lab1.h"
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

namespace lab1 {

    VECTOR::VECTOR(int n, float value) {
        this->n = n;
        for (int i = 0; i < n; i++)
            A[i] = value;
    }

    VECTOR::VECTOR(int n) {
        this->n = n;
    }

    VECTOR VECTOR::Add(const VECTOR& what) {
        VECTOR result(n);
        for (int i = 0; i < n; i++)
            result.A[i] = A[i] + what.A[i];
        return result;
    }

    VECTOR VECTOR::Cmul(float what) {
        VECTOR result(n);
        for (int i = 0; i < n; i++)
            result.A[i] = A[i] * what;
        return result;
    }

    float VECTOR::Norm() {
        float sum = 0;
        for (int i = 0; i < n; i++)
            sum += A[i] * A[i];
        return std::sqrt(sum);
    }

    void VECTOR::Normalize() {
        float norm = Norm();
        if (norm == 0) {
            cout << "Невозможно нормировать нулевой вектор!\n";
            return;
        }
        for (int i = 0; i < n; i++)
            A[i] /= norm;
    }

    void VECTOR::Print() {
        for (int i = 0; i < n; i++)
            cout << "a(" << i << ") = " << A[i] << "  ";
        cout << endl;
    }

    void demo() {
        setlocale(LC_ALL, "Russian");

        int n;
        float val1, val2, k;

        cout << "Размерность векторов: ";
        cin >> n;

        cout << "Значение для инициализации первого вектора: ";
        cin >> val1;

        cout << "Значение для инициализации второго вектора: ";
        cin >> val2;

        VECTOR v1(n, val1);
        VECTOR v2(n, val2);

        cout << "\nИсходные векторы:\n";
        cout << "v1: "; v1.Print();
        cout << "v2: "; v2.Print();

        VECTOR v_sum = v1.Add(v2);
        cout << "\nРезультат сложения:\n";
        v_sum.Print();

        cout << "\nДействительное число для умножения всех векторов: ";
        cin >> k;

        VECTOR v1_mul = v1.Cmul(k);
        VECTOR v2_mul = v2.Cmul(k);
        VECTOR v_sum_mul = v_sum.Cmul(k);

        cout << "\nРезультаты умножения на " << k << ":\n";
        cout << "v1 * " << k << ": "; v1_mul.Print();
        cout << "v2 * " << k << ": "; v2_mul.Print();
        cout << "(v1 + v2) * " << k << ": "; v_sum_mul.Print();

        cout << "\nНормирование всех векторов:\n";

        cout << "v1: ";
        v1.Normalize();
        v1.Print();

        cout << "v2: ";
        v2.Normalize();
        v2.Print();

        cout << "v1 + v2: ";
        v_sum.Normalize();
        v_sum.Print();
    }

}