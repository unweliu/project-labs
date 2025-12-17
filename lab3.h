#pragma once
#include <iostream>

namespace lab3 {

    class Sequence {
    private:
        int* arr;
        int size;

    public:
        Sequence(int n);
        ~Sequence();

        void inputManual();
        void inputAuto();
        void process();
        void output() const;
    };

    void demo();

}
