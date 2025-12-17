#pragma once
#include <iostream>

namespace lab5 {

    class VECTOR {
    public:
        VECTOR();
        VECTOR(int n);
        VECTOR(int n, float value);
        VECTOR(const VECTOR& other);

        void Init(float value);
        void Init(const VECTOR& other);

        VECTOR operator+(const VECTOR& other) const;
        VECTOR operator*(float k) const;
        VECTOR& operator=(const VECTOR& other);

        float Norm() const;
        void Normalize();
        void Print() const;

    private:
        int n;
        float A[200];
    };

    void demo();

}
