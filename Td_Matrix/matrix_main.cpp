// ---------------------------------------------------------------------------------------------- //
//  Arthur SICARD - 2A IR Alt
//
//      g++ -std=c++17 -Wall -Wextra -Werror *.cpp -o prog && ./prog
//
//
// -- Macro ------------------------------------------------------------------------------------- //

#include <iostream>

#include "matrix_base.hpp"
#include "matrix_num.hpp"

using namespace std;


// -- Main -------------------------------------------------------------------------------------- //

int main()
{
    MatrixNum<double> M(3,3);
    M.setElement(0,0,1.2);
    M.setElement(0,1,2);
    M.setElement(0,2,3);
    M.setElement(1,0,4);
    M.setElement(1,1,5);
    M.setElement(1,2,6);
    M.setElement(2,0,7);
    M.setElement(2,1,8);
    M.setElement(2,2,9);

    MatrixNum<double> N(3,3);
    N.setElement(0,0,1.2);
    N.setElement(0,1,2);
    N.setElement(0,2,3);
    N.setElement(1,0,4);
    N.setElement(1,1,5);
    N.setElement(1,2,6);
    N.setElement(2,0,7);
    N.setElement(2,1,8);
    N.setElement(2,2,9);

    (M+N).display();

    cout << endl << endl << "det de M : " << M.getDeterminant();

    M.display();
    (M.getInverse()).display();
    //((M*M).getInverse()).display();

    MatrixNum<double>::getIdentity(5).display();


    cout << endl << endl;
    return 0;
}