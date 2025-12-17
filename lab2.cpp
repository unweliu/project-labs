#include "lab2.h"

using std::cout;
using std::cin;
using std::endl;

namespace lab2 {

    Matrix::Matrix(int r, int c) {
        rows = r;
        cols = c;
        data = new int* [rows];
        for (int i = 0; i < rows; i++)
            data[i] = new int[cols];
    }

    Matrix::~Matrix() {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
    }

    void Matrix::input() {
        cout << "Введите элементы матрицы (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> data[i][j];
    }

    void Matrix::output() const {
        cout << "Матрица:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << data[i][j] << "\t";
            cout << endl;
        }
    }

    void Matrix::swap() {
        int minVal = data[0][0];
        int maxVal = data[0][0];
        int minRow = 0, maxRow = 0;

        int* minAddr = &data[0][0];
        int* maxAddr = &data[0][0];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (data[i][j] < minVal) {
                    minVal = data[i][j];
                    minRow = i;
                    minAddr = &data[i][j];
                }
                if (data[i][j] > maxVal) {
                    maxVal = data[i][j];
                    maxRow = i;
                    maxAddr = &data[i][j];
                }
            }
        }

        cout << "\nМинимальный элемент: " << minVal
            << " (адрес: " << static_cast<void*>(minAddr) << ")\n";
        cout << "Максимальный элемент: " << maxVal
            << " (адрес: " << static_cast<void*>(maxAddr) << ")\n";

        if (minRow != maxRow) {
            for (int j = 0; j < cols; j++) {
                int temp = data[minRow][j];
                data[minRow][j] = data[maxRow][j];
                data[maxRow][j] = temp;
            }
        }

        cout << "\nПосле обмена строк с минимальным и максимальным элементами:\n";
        output();
    }

    void demo() {
        setlocale(LC_ALL, "Russian");

        int rows, cols;
        cout << "Введите количество строк и столбцов: ";
        cin >> rows >> cols;

        Matrix M(rows, cols);
        M.input();

        cout << "\nИсходная ";
        M.output();

        M.swap();
    }

}