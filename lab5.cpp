#include "lab5.h"
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

namespace lab5 {

    VECTOR::VECTOR() {
        n = 0;
    }

    VECTOR::VECTOR(int n) {
        this->n = n;
        for (int i = 0; i < n; i++)
            A[i] = 0;
    }

    VECTOR::VECTOR(int n, float value) {
        this->n = n;
        for (int i = 0; i < n; i++)
            A[i] = value;
    }

    VECTOR::VECTOR(const VECTOR& other) {
        n = other.n;
        for (int i = 0; i < n; i++)
            A[i] = other.A[i];
    }

    void VECTOR::Init(float value) {
        cout << "Инициализация всех компонентов числом.\n";
        for (int i = 0; i < n; i++)
            A[i] = value;
    }

    void VECTOR::Init(const VECTOR& other) {
        cout << "Инициализация копированием другого вектора.\n";
        n = other.n;
        for (int i = 0; i < n; i++)
            A[i] = other.A[i];
    }

    VECTOR VECTOR::operator+(const VECTOR& other) const {
        cout << "Перегруженный оператор сложения вызван\n";
        VECTOR result(n);
        for (int i = 0; i < n; i++)
            result.A[i] = A[i] + other.A[i];
        return result;
    }

    VECTOR VECTOR::operator*(float k) const {
        cout << "Перегруженный оператор умножения вызван\n";
        VECTOR result(n);
        for (int i = 0; i < n; i++)
            result.A[i] = A[i] * k;
        return result;
    }

    VECTOR& VECTOR::operator=(const VECTOR& other) {
        cout << "Перегруженный оператор присваивания вызван\n";
        if (this == &other)
            return *this;
        n = other.n;
        for (int i = 0; i < n; i++)
            A[i] = other.A[i];
        return *this;
    }

    float VECTOR::Norm() const {
        float s = 0;
        for (int i = 0; i < n; i++)
            s += A[i] * A[i];
        return std::sqrt(s);
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

        VECTOR v1(n);
        VECTOR v2(n);

        v1.Init(val1);
        v2.Init(val2);

        cout << "\nИсходные векторы:\n";
        v1.Print();
        v2.Print();

        VECTOR v_sum = v1 + v2;
        cout << "\nСумма: ";
        v_sum.Print();

        cout << "\nЧисло для умножения: ";
        cin >> k;

        VECTOR v1_mul = v1 * k;
        VECTOR v2_mul = v2 * k;

        cout << "\nРезультаты умножения:\n";
        v1_mul.Print();
        v2_mul.Print();

        cout << "\nНормирование:\n";
        v1.Normalize(); v1.Print();
        v2.Normalize(); v2.Print();
    }

}