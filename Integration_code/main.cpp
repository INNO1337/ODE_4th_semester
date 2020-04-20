#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

double f(double x) { return sin(x*x); }

int main() {
    vector <double> Integral(4);
    double a = 0.0, b = 2000;
    double h = 0.00001;
    double n;
    n = (b - a) / h;

    for(int i = 0; i < n; i++) {
        Integral[0] += f(a + h * i) * h; //left
        Integral[1] += f((a + h/2) + h * i) * h; //middle
        if (i > 0) {
            Integral[2] += f(a + h * i) * h; //right
        }
        Integral[3] += (f(a + h * i) + f(a + h * (i + 1))) / 2 * h; //trapeeze
    }
    Integral[2] += f(a + h * n) * h;


    cout << "____________________\n";
    cout << "|Result is>>>>>>>-<" << "|" << "\n";
    cout << "|Left:::::" << Integral[0] << "<|" << "\n";
    cout << "|Middle:::" << Integral[1] << "<|" <<"\n";
    cout << "|Right::::" << Integral[2] << "<|" <<"\n";
    cout << "|Trapeze::" << Integral[3] << "<|" <<"\n";
    cout << "--------------------\n";
    return 0;
}
