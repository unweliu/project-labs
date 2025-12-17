#pragma once

namespace lab6 {

    template <typename T>
    class Variance {
    private:
        T* data;
        int size;

    public:
        Variance(int n);
        ~Variance();

        void setValue(int index, T value);
        T mean();
        T compute();
    };

    void demo();

}
