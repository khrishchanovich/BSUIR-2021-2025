#include <iostream>
#include <string>
#include <windows.h>
#include <functional>
#include <regex>

using namespace std;

string Solve(long double a, long double b, long double c)
{
    const long double LD_4 = 4.0L;
    if (a == 0) {
        return "Уравнение не является квадратным";
    }
    long double D;
    __asm
    {
        FLD b
        FLD b
        FMUL
        FLD LD_4
        FLD a
        FLD c
        FMUL
        FMUL
        FSUB
        FSTP D
    }
    cout << "\nДискриминант: " << D << '\n';
    if (!isfinite(D)) {
        return "Дискриминант не является конечным числом";
    }
    if (D < 0.0L) {
        return "Нет вещественных корней";
    }
    if (D == 0.0L) {
        long double x;
        __asm
        {
            FLD b
            FCHS
            FLD a
            FLD a
            FADD
            FDIV
            FSTP x
        }
        return "x = " + to_string(x);
    }
    if (D > 0.0L) {
        long double x1, x2;
        __asm
        {
            FLD b
            FCHS
            FLD D
            FSQRT

            FSUB

            FLD a
            FLD a
            FADD
            FDIV

            FSTP x1
        }
        __asm
        {
            FLD b
            FCHS
            FLD D
            FSQRT

            FADD

            FLD a
            FLD a
            FADD
            FDIV

            FSTP x2
        }
        return "x1 = " + to_string(x1) + ", " +
            "x2 = " + to_string(x2);
    }
    return "Что-то пошло не так";
}

template<typename ReturnValue>
ReturnValue CorrectInput(const string& variable_name, const std::regex& pattern,
    std::function<ReturnValue(string& input)> converter) {

    string value;

    do {
        cout << "Введите " << variable_name << ":\t";
        cin >> value;
    } while (!regex_match(value, pattern));

    return converter(value);

}

int main() {

    SetConsoleCP(1251);

    SetConsoleOutputCP(1251);

    long double a = CorrectInput<long double>(std::string("коэффициент а"),
        std::regex("-?[0-9]+,?[0-9]*"),
        [](std::string& s) {return atof(s.c_str()); });

    long double b = CorrectInput<long double>(std::string("коэффициент b"),
        std::regex("-?[0-9]+,?[0-9]*"),
        [](std::string& s) {return atof(s.c_str()); });

    long double c = CorrectInput<long double>(std::string("коэффициент c"),
        std::regex("-?[0-9]+,?[0-9]*"),
        [](std::string& s) {return atof(s.c_str()); });

    cout << '\n';

    if (a != 1)
        cout << ((a == -1) ? '-' : a);

    cout << "x^2 " << ((b < 0) ? '-' : '+') << ' ' << abs(b) << "x "
        << ((c < 0) ? '-' : '+') << ' ' << abs(c) << " = 0\n";

    cout << '\n' << Solve(a, b, c) << '\n';

    return 0;
}
