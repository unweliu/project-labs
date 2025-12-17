#pragma once
#include <iostream>

namespace lab4 {
    class VECTOR {
    public:
        virtual ~VECTOR() {}

        VECTOR(int n, float value);
        VECTOR(int n);
        VECTOR();

        virtual VECTOR Add(const VECTOR& what) const;
        virtual VECTOR Cmul(float what) const;
        virtual float Norm() const;
        virtual void Normalize();
        virtual void Print() const;

    protected:
        int n;
        float A[200];
    };

    class VChild : public VECTOR {
    public:
        VChild(int n, float value);
        VChild(int n);
        VChild();

        VECTOR Add(const VECTOR& what) const override;
        VECTOR Cmul(float what) const override;
        float Norm() const override;
        void Normalize() override;
        void Print() const override;
    };

    void demo();

}


