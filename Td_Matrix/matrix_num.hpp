// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef MATRIX_NUM_HPP
#define MATRIX_NUM_HPP

#include "matrix_base.hpp"


// -- Class ------------------------------------------------------------------------------------- //

template <typename T>
class MatrixNum : public MatrixBase<T> 
{
    using MatrixBase<T>::MatrixBase;

    public:
    // operators --------------- //  
        /*
            Déclaration Global (ne pas déclarer dans la classe, juste l'implémenter hors d'elle)
        MatrixNum<T> operator + (const MatrixNum<T>& first, const MatrixNum<T>& second) const;
        MatrixNum<T> operator - (const MatrixNum<T>& first, const MatrixNum<T>& second) const;
        MatrixNum<T> operator * (const MatrixNum<T>& first, const MatrixNum<T>& second) const;
        MatrixNum<T> operator / (const MatrixNum<T>& first, const MatrixNum<T>& second) const;
        MatrixNum<T> operator * (const MatrixNum<T>& matrix, T scalar) const;
        MatrixNum<T> operator / (const MatrixNum<T>& matrix, T scalar) const;
        
            Déclaration Local
        MatrixNum<T> operator + (const MatrixNum<T>& other) const;
        MatrixNum<T> operator - (const MatrixNum<T>& other) const;
        MatrixNum<T> operator * (const MatrixNum<T>& other) const;
        MatrixNum<T> operator / (const MatrixNum<T>& other) const;
        MatrixNum<T> operator * (T scalar) const;
        MatrixNum<T> operator / (T scalar) const;*/
        
        //friend MatrixNum<T> operator + (const MatrixNum<T>& first, const MatrixNum<T>& second);
        friend MatrixNum<T> operator + (const MatrixNum<T>& first, const MatrixNum<T>& second) {
            if (first.rows != second.rows || first.cols != second.cols)
                throw std::logic_error("Les matrices ne sont pas de la même taille.");
            MatrixNum<T> result(first.rows, first.cols);
            for (size_t i = 0; i < first.rows; ++i) {
                for (size_t j = 0; j < first.cols; ++j) {
                    result.setElement(i, j, first.data[i][j] + second.data[i][j]);
                }
            }
            return result;
        }

        friend MatrixNum<T> operator - (const MatrixNum<T>& first, const MatrixNum<T>& second) {
            if (first.rows != second.rows || first.cols != second.cols)
                throw std::logic_error("Les matrices ne sont pas de la même taille.");
            MatrixNum<T> result(first.rows, first.cols);
            for (size_t i = 0; i < first.rows; ++i) {
                for (size_t j = 0; j < first.cols; ++j) {
                    result.setElement(i, j, first.data[i][j] - second.data[i][j]);
                }
            }
            return result;
        }

        friend MatrixNum<T> operator * (const MatrixNum<T>& first, const MatrixNum<T>& second) {
            if (first.rows != second.cols) {
                throw std::logic_error("Les dimensions des matrices ne sont pas compatibles.");
            }
            MatrixNum<T> result(first.rows, second.cols);
            for (size_t i = 0; i < first.rows; ++i) {
                for (size_t j = 0; j < second.cols; ++j) {
                    T sum = T();
                    for (size_t k = 0; k < first.cols; ++k) {
                        sum += first.data[i][k] * second.data[k][j];
                    }
                    result.setElement(i, j, sum);
                }
            }
            return result;
        }

        friend MatrixNum<T> operator / (const MatrixNum<T>& first, const MatrixNum<T>& second) {
            if (first.rows != second.cols || first.cols != second.rows) {
                throw std::logic_error("Les dimensions des matrices ne sont pas compatibles.");
            }
            MatrixNum<T> result(first.rows, first.cols);
            for (size_t i = 0; i < first.rows; ++i) {
                for (size_t j = 0; j < first.cols; ++j) {
                    if (second.data[i][j] == T(0)) {
                        throw std::logic_error("La division par zéro n'est pas autorisée.");
                    }
                    result.setElement(i, j, first.data[i][j] / second.data[i][j]);
                }
            }
            return result;
        }

        friend MatrixNum<T> operator * (const MatrixNum<T>& matrix, T scalar) {
            MatrixNum<T> result(matrix.rows, matrix.cols);
            for (size_t i = 0; i < matrix.rows; ++i) {
                for (size_t j = 0; j < matrix.cols; ++j) {
                    result.setElement(i, j, matrix.data[i][j] * scalar);
                }
            }
            return result;
        }

        friend MatrixNum<T> operator / (const MatrixNum<T>& matrix, T scalar) {
            MatrixNum<T> result(matrix.rows, matrix.cols);
            for (size_t i = 0; i < matrix.rows; ++i) {
                for (size_t j = 0; j < matrix.cols; ++j) {
                    result.setElement(i, j, matrix.data[i][j] / scalar);
                }
            }
            return result;
        }

    // methodes --------------- //
        T getDeterminant() const;
        MatrixNum<T> getInverse() const;
        static MatrixNum<T> getIdentity(int size);
        MatrixNum<T> getSubMatrix(const MatrixNum<T>& matrix, size_t row, size_t col) const;

    private:
    // interne methodes ------- //
        T getCoFactor(const MatrixNum<T>& matrix, size_t row, size_t col) const;
        T calculateDet(const MatrixNum<T>& matrix) const;
};



// -- IMPLEMENTATION ---------------------------------------------------------------------------- //


// -- operators --------------------------------------------------------------------------------- //

/*  methode d'implémentation local

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
MatrixNum<T> MatrixNum<T>::operator * (const MatrixNum<T>& other) const {
    if (this->getRows() != other.getCols()) {
        throw std::logic_error("Les dimensions des matrices ne sont pas compatibles.");
    }
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
MatrixNum<T> MatrixNum<T>::operator / (const MatrixNum<T>& other) const {
    if (this->getRows() != other.getCols() || this->getCols() != other.getRows()) {
        throw std::logic_error("Les dimensions des matrices ne sont pas compatibles.");
    }
    MatrixNum<T> result(this->getRows(), this->getCols());
    for (size_t i = 0; i < this->getRows(); ++i) {
        for (size_t j = 0; j < this->getCols(); ++j) {
            if (other.getElement(i, j) == T(0)) {
                throw std::logic_error("La division par zéro n'est pas autorisée.");
            }
            result.setElement(i, j, this->getElement(i, j) / other.getElement(i, j));
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
    if (scalar == T(0)) {
        throw std::logic_error("La division par zéro n'est pas autorisée.");
    }
    MatrixNum<T> result(this->getRows(), this->getCols());
    for (size_t i = 0; i < this->getRows(); ++i) {
        for (size_t j = 0; j < this->getCols(); ++j) {
            result.setElement(i, j, this->getElement(i, j) / scalar);
        }
    }
    return result;
}
*/

/*Ne marche pas car méthode friend d'une classe générique donc on doit mettre le code dans la classe
l'implementation en friend d'un opérateur global

template <typename T>
MatrixNum<T> operator + (const MatrixNum<T>& first, const MatrixNum<T>& second) {
    if (first.rows != second.rows || first.cols != second.cols)
        throw std::logic_error("Les matrices ne sont pas de la même taille.");
    MatrixNum<T> result(first.rows, first.cols);
    for (size_t i = 0; i < first.rows; ++i) {
        for (size_t j = 0; j < first.cols; ++j) {
            result.setElement(i, j, first.data[i][j] - second.data[i][j]);
        }
    }
    return result;
}*/


// -- methods ----------------------------------------------------------------------------------- //

template <typename T>
T MatrixNum<T>::getDeterminant() const {
    if (this->getRows() != this->getCols()) {
        throw std::logic_error("La matrice doit être carrée pour calculer le déterminant.");
    }
    return calculateDet(*this);     // Appel initial à la fonction récursive
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

template <typename T>                  // Fonction statique pour obtenir une matrice carrée identité
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

template <typename T>
MatrixNum<T> MatrixNum<T>::getSubMatrix(const MatrixNum<T>& matrix, size_t row, size_t col) const {
    size_t size = matrix.getRows();
    MatrixNum<T> subMatrix(size - 1, size - 1);
    for (size_t i = 0, subRow = 0; i < size; ++i) {
        if (i == row) {
            continue;   // Ignorer la ligne à exclure
        }
        for (size_t j = 0, subCol = 0; j < size; ++j) {
            if (j == col) {
                continue;   // Ignorer la colonne à exclure
            }
            subMatrix.setElement(subRow, subCol, matrix.getElement(i, j));
            ++subCol;
        }
        ++subRow;
    }
    return subMatrix;
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

template <typename T>                             // Fonction récursive pour calculer le déterminant
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


// -- END --------------------------------------------------------------------------------------- //

#endif