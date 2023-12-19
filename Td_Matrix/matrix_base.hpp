// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef MATRIX_BASE_H
#define MATRIX_BASE_H
 
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;


// -- Class ------------------------------------------------------------------------------------- //

template <typename T>
class MatrixBase
{
    public:
    // constructors ------------ //
        MatrixBase(size_t, size_t);

    // accessors --------------- //
        void setElement(size_t, size_t, T);
        T getElement(size_t, size_t) const;
        size_t getRows() const;
        size_t getCols() const;

    // methods --------------- //
        string toString() const;
        void display() const;
        ostream& displayOn(ostream&) const;

    protected:
    // attributes -------------- //
        vector<vector<T>> data;
        size_t rows, cols;
};



// -- IMPLEMENTATION ---------------------------------------------------------------------------- //


// -- constructors ------------------------------------------------------------------------------ //

template <typename T>
MatrixBase<T>::MatrixBase(size_t _rows, size_t _cols) :
    data(_rows, vector<T>(_cols, T())),
    rows(_rows),
    cols(_cols)
{}


// -- accessors --------------------------------------------------------------------------------- //

template <typename T>
void MatrixBase<T>::setElement(size_t row, size_t col, T value) {
    if (row < rows && col < cols)
        data[row][col] = value;
}

template <typename T>
T MatrixBase<T>::getElement(size_t row, size_t col) const {
    if (row < rows && col < cols) {
        return data[row][col];
    } else {
        cout << "Invalid indices." << endl;
        return T();     // Retourne une valeur par défauts
    }
}

template <typename T>
size_t MatrixBase<T>::getRows() const {
    return rows;
}

template <typename T>
size_t MatrixBase<T>::getCols() const {
    return cols;
}


// -- methods ----------------------------------------------------------------------------------- //

template <typename T>
string MatrixBase<T>::toString() const {
    ostringstream oss;
    oss << fixed << setprecision(1);   // affiche une précision d'un chiffre après la virgule
    oss << "[";
    for (size_t i = 0; i < rows; ++i) {
        if (i > 0) {
            oss << endl << " ";
        }
        oss << "[";
        for (size_t j = 0; j < cols; ++j) {
            oss << setw(6) << data[i][j];   // largeur colonne : setw(x)
            if (j < cols - 1) {
                oss << ", ";
            }
        }
        oss << "]";
        if (i < rows - 1) {
            oss << ",";
        }
    }
    oss << "]";
    return oss.str();
}

template <typename T>
void MatrixBase<T>::display() const {
    cout << endl << endl << toString();
}

template <typename T>
ostream& MatrixBase<T>::displayOn(ostream& os) const {
    return os << endl << toString();
}


// -- END --------------------------------------------------------------------------------------- //

#endif