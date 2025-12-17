#pragma once
#include <iostream>

namespace lab1 {

    class VECTOR {
    public:
        VECTOR(int n, float value);
        VECTOR(int n);

        VECTOR Add(const VECTOR& what);
        VECTOR Cmul(float what);
        float Norm();
        void Normalize();
        void Print();

    private:
        int n;
        float A[200];
    };

    void demo();

}
