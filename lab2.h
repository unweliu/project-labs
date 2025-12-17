#pragma once
#include <iostream>

namespace lab2 {

    class Matrix {
    private:
        int rows, cols;
        int** data;

    public:
        Matrix(int r, int c);
        ~Matrix();

        void input();
        void output() const;
        void swap();
    };

    void demo();

}
