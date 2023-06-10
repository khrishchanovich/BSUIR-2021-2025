#include <iostream>
#include <iomanip>
#include <windows.h>
#include <math.h>
#include <string>
#include <regex>
#include <functional>

using namespace std;

void Solve(long double a, long double b, long double h, long double eps)
{
    cout << '\n';

    cout << setprecision(3) << scientific << showpos <<
        "                                    eps = " << eps << "        " << '\n';
    cout << " ---------------------------------------------------------- " << '\n';
    cout << " |     x      |    S(x)    |    Y(x)    | abs(S - Y) | n  | " << '\n';
    cout << " |------------|------------|------------|------------|----| " << '\n';

    for (long double x = a; x < b + h / 2; x += h) {

        int n = 0;

        long double Y, S, f, p, intp, fracp, trash;

        //Y = pow(exp, x*cos(PI/4)) * cos(x*sin(PI/4));
        __asm
        {
            FLD x
            FCOS
            FLDL2E
            FMUL
            FSTP p
        }
        __asm
        {
            FLD p
            FLD1
            FSCALE
            FSTP intp
            FSTP trash
        }
        __asm
        {
            FLD1
            FLD p
            FPREM
            F2XM1
            FADD
            FSTP fracp
        }
        //Y = pow(exp, x*cos(PI/4)) * cos(x*sin(PI/4));
        __asm
        {
            FLD intp
            FLD fracp
            FMUL

            FLD x
            FSIN
            FCOS
            FMUL
            FSTP Y
        }
        //S = 1.0, f = 1.0;
        __asm
        {
            FLD1
            FSTP S

            FLD1
            FSTP f
        }
        while (abs(S - Y) > eps) {
            n++;
            //f *= n;
            __asm
            {
                FLD f
                FILD n
                FMUL
                FSTP f
            }
            //S += cos(kPI/4) / f! * pow(x, 12);
            __asm
            {
                FLD S
                FILD n
                FLD x
                FMUL
                FCOS
                FLD f
                FDIV
                FADD
                FSTP S
            }

        }
        cout << setprecision(3) << scientific << showpos <<
            " | " << x << " | " << S << " | " << Y << " | " << abs(S - Y) << " | " <<
            noshowpos << right << setw(2) << n << " | \n";
    }
    cout << " ---------------------------------------------------------- \n";
}

template<typename ReturnValue>
ReturnValue CorrectInput(const string& variable_name, const std::regex& pattern,
    std::function<ReturnValue(string& input)> converter) {

    string value;

    do {
        cout << "¬ведите " << variable_name << ":\t";
        cin >> value;
    } while (!regex_match(value, pattern));

    return converter(value);

}

int main() {

    SetConsoleCP(1251);

    SetConsoleOutputCP(1251);


    float a = CorrectInput<float>(std::string("нижнюю границу (а)"),
        std::regex("-?[0-9]+,?[0-9]*"),
        [](std::string& s) {return atof(s.c_str()); });

    float b = CorrectInput<float>(std::string("верхнюю ганицу (b)"),
        std::regex("-?[0-9]+,?[0-9]*"),
        [](std::string& s) {return atof(s.c_str()); });

    float h = CorrectInput<float>(std::string("шаг (h)"),
        std::regex("-?[0-9]+,?[0-9]*"),
        [](std::string& s) {return atof(s.c_str()); });

    float eps = CorrectInput<long double>(std::string("погрешность (eps)"),
        std::regex("-?[0-9]+\.?[0-9]*"),
        [](std::string& s) {return atof(s.c_str()); });

    Solve(a, b, h, eps);

    return 0;
}
