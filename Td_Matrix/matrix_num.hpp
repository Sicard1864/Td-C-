// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef MATRIX_NUM_HPP
#define MATRIX_NUM_HPP

#include "matrix_base.hpp"


// -- Class ------------------------------------------------------------------------------------- //

template <typename T>
class MatrixNum : public MatrixBase<T> 
{
    public:
        // constructors ------------ //
        using MatrixBase<T>::MatrixBase;

        // operators --------------- //
        MatrixNum<T> operator + (const MatrixNum<T>& other) const;
        MatrixNum<T> operator + (T scalar) const;
        MatrixNum<T> operator - (const MatrixNum<T>& other) const;
        MatrixNum<T> operator - (T scalar) const;
        MatrixNum<T> operator * (const MatrixNum<T>& other) const;
        MatrixNum<T> operator * (T scalar) const;
        MatrixNum<T> operator / (T scalar) const;

        // methodes --------------- //
        T getDeterminant() const;
        MatrixNum<T> getInverse() const;
        static MatrixNum<T> getIdentity(int size);

    private:
        // interne methodes ------- //
        T getCoFactor(const MatrixNum<T>& matrix, size_t row, size_t col) const;
        T calculateDet(const MatrixNum<T>& matrix) const;
        MatrixNum<T> getSubMatrix(const MatrixNum<T>& matrix, size_t row, size_t col) const;
};



// -- IMPLEMENTATION ---------------------------------------------------------------------------- //


// -- operators --------------------------------------------------------------------------------- //

template <typename T>
MatrixNum<T> MatrixNum<T>::operator + (const MatrixNum<T>& other) const {
    if (this->getRows() != other.getRows() || this->getCols() != other.getCols())
        throw std::logic_error("Les matrices ne sont pas de la même taille.");
    MatrixNum<T> result(this->getRows(), this->getCols());
    for (size_t i = 0; i < this->getRows(); ++i) {
        for (size_t j = 0; j < this->getCols(); ++j) {
            result.setElement(i, j, this->getElement(i, j) + other.getElement(i, j));
        }
    }
    return result;
}

template <typename T>
MatrixNum<T> MatrixNum<T>::operator + (T scalar) const {
    MatrixNum<T> result(this->getRows(), this->getCols());
    for (size_t i = 0; i < this->getRows(); ++i) {
        for (size_t j = 0; j < this->getCols(); ++j) {
            result.setElement(i, j, this->getElement(i, j) + scalar);
        }
    }
    return result;
}

template <typename T>
MatrixNum<T> MatrixNum<T>::operator - (const MatrixNum<T>& other) const {
    if (this->getRows() != other.getRows() || this->getCols() != other.getCols())
        throw std::logic_error("Les matrices ne sont pas de la même taille.");
    MatrixNum<T> result(this->getRows(), this->getCols());
    for (size_t i = 0; i < this->getRows(); ++i) {
        for (size_t j = 0; j < this->getCols(); ++j) {
            result.setElement(i, j, this->getElement(i, j) - other.getElement(i, j));
        }
    }
    return result;
}

template <typename T>
MatrixNum<T> MatrixNum<T>::operator - (T scalar) const {
    MatrixNum<T> result(this->getRows(), this->getCols());
    for (size_t i = 0; i < this->getRows(); ++i) {
        for (size_t j = 0; j < this->getCols(); ++j) {
            result.setElement(i, j, this->getElement(i, j) - scalar);
        }
    }
    return result;
}

template <typename T>
MatrixNum<T> MatrixNum<T>::operator * (const MatrixNum<T>& other) const {
    if (this->getCols() != other.getRows())
        throw std::logic_error("Les dimensions des matrices ne sont pas compatibles.");
    MatrixNum<T> result(this->getRows(), other.getCols());
    for (size_t i = 0; i < this->getRows(); ++i) {
        for (size_t j = 0; j < other.getCols(); ++j) {
            T sum = T();
            for (size_t k = 0; k < this->getCols(); ++k) {
                sum += this->getElement(i, k) * other.getElement(k, j);
            }
            result.setElement(i, j, sum);
        }
    }
    return result;
}

template <typename T>
MatrixNum<T> MatrixNum<T>::operator * (T scalar) const {
    MatrixNum<T> result(this->getRows(), this->getCols());
    for (size_t i = 0; i < this->getRows(); ++i) {
        for (size_t j = 0; j < this->getCols(); ++j) {
            result.setElement(i, j, this->getElement(i, j) * scalar);
        }
    }
    return result;
}

template <typename T>
MatrixNum<T> MatrixNum<T>::operator / (T scalar) const {
    if (scalar == T(0))
        throw std::logic_error("La division par zéro n'est pas autorisée.");
    MatrixNum<T> result(this->getRows(), this->getCols());
    for (size_t i = 0; i < this->getRows(); ++i) {
        for (size_t j = 0; j < this->getCols(); ++j) {
            result.setElement(i, j, this->getElement(i, j) / scalar);
        }
    }
    return result;
}


// -- methods ----------------------------------------------------------------------------------- //

template <typename T>
T MatrixNum<T>::getDeterminant() const {
    if (this->getRows() != this->getCols()) {
        throw std::logic_error("La matrice doit être carrée pour calculer le déterminant.");
    }
    return calculateDet(*this);                             // Appel initial à la fonction récursive
}

template <typename T>                                      // Utilisation de la méthode de Cofacteur
MatrixNum<T> MatrixNum<T>::getInverse() const {
    if (this->getRows() != this->getCols()) {
        throw std::logic_error("La matrice doit être carrée pour avoir une inverse.");
    }
    T determinant = getDeterminant();
    if (determinant == T(0)) {
        throw std::logic_error("La matrice est singulière, elle n'a pas d'inverse.");
    }
    MatrixNum<T> inverse(this->getRows(), this->getCols());
    for (size_t i = 0; i < this->getRows(); ++i) {
        for (size_t j = 0; j < this->getCols(); ++j) {
            T cofactor = getCoFactor(*this, i, j);
            inverse.setElement(j, i, cofactor / determinant);
        }
    }
    return inverse;
}

// Fonction statique pour obtenir une matrice carrée identité
template <typename T>
MatrixNum<T> MatrixNum<T>::getIdentity(int size) {
    if (size <= 0) {
        throw std::logic_error("La taille de la matrice identité doit être un entier positif.");
    }
    MatrixNum<T> identityMatrix(size, size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            identityMatrix.setElement(i, j, (i == j) ? T(1) : T(0));
        }
    }
    return identityMatrix;
}


// -- internal methods -------------------------------------------------------------------------- //

template <typename T>
T MatrixNum<T>::getCoFactor(const MatrixNum<T>& matrix, size_t row, size_t col) const {
    if (matrix.getRows() != matrix.getCols()) {
        throw std::logic_error("La matrice doit être carrée pour obtenir un cofacteur.");
    }
    // Coefficient de Laplace : (-1)^(i+j) * determinant de la sous-matrice
    T sign = ((row + col) % 2 == 0) ? T(1) : T(-1);
    return sign * calculateDet(getSubMatrix(matrix, row, col));
}

// Fonction récursive pour calculer le déterminant
template <typename T>
T MatrixNum<T>::calculateDet(const MatrixNum<T>& matrix) const {
    size_t size = matrix.getRows();
    if (size == 1) {
        // Cas de base : matrice 1x1
        return matrix.getElement(0, 0);
    }
    T determinant = T();
    for (size_t i = 0; i < size; ++i) {
        // Coefficient de Laplace : (-1)^(i+j) * matrix[i][j] * determinant de la sous-matrice
        T sign = (i % 2 == 0) ? T(1) : T(-1);
        determinant += sign * matrix.getElement(0, i) * calculateDet(getSubMatrix(matrix, 0, i));
    }
    return determinant;
}

template <typename T>
MatrixNum<T> MatrixNum<T>::getSubMatrix(const MatrixNum<T>& matrix, size_t row, size_t col) const {
    size_t size = matrix.getRows();
    MatrixNum<T> subMatrix(size - 1, size - 1);
    for (size_t i = 0, subRow = 0; i < size; ++i) {
        if (i == row) {
            continue; // Ignorer la ligne à exclure
        }
        for (size_t j = 0, subCol = 0; j < size; ++j) {
            if (j == col) {
                continue; // Ignorer la colonne à exclure
            }
            subMatrix.setElement(subRow, subCol, matrix.getElement(i, j));
            ++subCol;
        }
        ++subRow;
    }
    return subMatrix;
}


// -- END --------------------------------------------------------------------------------------- //

#endif