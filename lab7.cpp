#include "lab7.h"

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ostream;

namespace lab7 {


    void Formatter::input() {
        cout << "Введите: f c3 i c2 c1\n";
        cin >> f >> c3 >> i >> c2 >> c1;
    }

    void Formatter::output(ostream& out) {
        out << c1 << endl;
        out << std::setw(5) << std::setfill('*')
            << std::hex << std::uppercase << i << std::dec << endl;

        out << c3 << endl;

        out << std::setw(5) << std::setfill('*')
            << std::fixed << std::setprecision(1) << f << endl;
        out << std::setw(5) << std::setfill('*')
            << std::fixed << std::setprecision(2) << f << endl;
        out << std::setw(5) << std::setfill('*')
            << std::fixed << std::setprecision(3) << f << endl;

        out << c2 << endl;
    }

    void demo() {
        setlocale(LC_ALL, "Russian");

        Formatter F;
        F.input();

        F.output(cout);

        ofstream file("output.txt");
        if (!file) {
            cout << "Ошибка открытия файла!\n";
            return;
        }

        F.output(file);
        file.close();

        cout << "Результат записан в output.txt\n";
    }

}