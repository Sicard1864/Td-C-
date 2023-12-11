// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef MATRIX_BASE_H
#define MATRIX_BASE_H


// -- Macro ------------------------------------------------------------------------------------- //

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;


// -- Class ------------------------------------------------------------------------------------- //

template <typename T>
class MatrixBase
{
private:
    vector<vector<T>> data;
    size_t rows, cols;

public:
    // constructors
    MatrixBase(size_t rows, size_t cols) :
            data(rows, vector<T>(cols, T())), rows(rows), cols(cols) {}

    // accessors
    void setElement(size_t row, size_t col, T value) {
        if (row < rows && col < cols)
            data[row][col] = value;
    }

    T getElement(size_t row, size_t col) const {
        if (row < rows && col < cols) {
            return data[row][col];
        } else {
            cout << "Invalid indices." << endl;
            return T(); // Retourne une valeur par défauts
        }
    }

    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    string toString() const {
        ostringstream oss;
        oss << fixed << setprecision(1); // affiche une précision d'un chiffre après la virgule
        oss << "[";
        for (size_t i = 0; i < rows; ++i) {
            if (i > 0) {
                oss << endl << " ";
            }
            oss << "[";
            for (size_t j = 0; j < cols; ++j) {
                oss << setw(6) << data[i][j]; // largeur colonne : setw(x)
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

    void display() const { cout << endl << endl << toString(); }
    ostream& displayOn (ostream& os) const { return os << endl << toString(); }
};

#endif