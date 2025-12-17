#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>

namespace lab7 {

    class Formatter {
    private:
        float f;
        char c3, c2, c1;
        int i;

    public:
        void input();
        void output(std::ostream& out);
    };

    void demo();

}
