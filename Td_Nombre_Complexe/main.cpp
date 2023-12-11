// ---------------------------------------------------------------------------------------------- //
//  Arthur SICARD - 2A IR Alt
//
//      g++ -std=c++17 -Wall -Wextra -Werror *.cpp -o prog && ./prog
//
//
// -- Macro ------------------------------------------------------------------------------------- //

#include <iostream>
#include <string>
#include <cmath>
#include "complex.h"
using namespace std;


// -- Main -------------------------------------------------------------------------------------- //

int main() {

    Complex2D z1(1, 2);
    Complex2D z2(0, -1);
    z1.print();
    z2.printOn(std::cout);
    cout << endl;

    z2.setR(1.5);
    cout << endl << "z1 = " << z1.toString();
    cout << endl << "z2 = " << z2.toString();
    cout << endl;

    cout << endl << "|z1| = " << z1.getModulus();
    cout << endl << "arg(z1) = " << z1.getArguments();
    cout << endl << "¯z1¯ = " << z1.getBar().toString();
    cout << endl << "1/z1 = " << z1.getInverse().toString();
    z1.Translate(z2);
    cout << endl << "z1 translate z2 = " << z1.toString();
    z1.Homothety(10);
    cout << endl << "z1 homothety 2 = " << z1.toString();
    double pi = M_PI;
    z1.Rotate(pi/2);
    cout << endl << "z1 rotate pi/2 = " << z1.toString();
    cout << endl;

    z1.setZ(1, 2);
    Complex2D z3 = z1 + z2;
    cout << endl << "z3 = z1 + z2 = " << z3.toString();
    Complex2D z4 = z1 - z2;
    cout << endl << "z4 = z1 - z2 = " << z4.toString();
    Complex2D z5 = z1 * z2;
    cout << endl << "z5 = z1 * z2 = " << z5.toString();
    Complex2D z6 = z1 / z2;
    cout << endl << "z6 = z1 / z2 = " << z6.toString();
    cout << endl;
    z6 = z5;
    cout << endl << "z6 = z5 = " << z6.toString();
    cout << endl;

    if(z1 < z2)
        cout << endl << z1.toString() << " < " << z2.toString();
    else
        cout << endl << z1.toString() << " >= " << z2.toString();

    Complex2D *zA = new Complex2D[3];
    delete[] zA;
    Complex2D *zB = new Complex2D(z1);
    delete zB;
    

    cout << endl << endl;
    return 0;
}