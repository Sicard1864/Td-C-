// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef MATRIX_NUMERICAL_HPP
#define MATRIX_NUMERICAL_HPP
#include "matrix_base.hpp"


// -- Class ------------------------------------------------------------------------------------- //

template <typename NumericType>
class MatrixNumerical : public MatrixBase<NumericType> 
{
    public:
        // constructors
        using MatrixBase<NumericType>::MatrixBase;

        // operators --------------- //
        MatrixNumerical<NumericType> operator+(const MatrixNumerical<NumericType>& other) const {
            if (this->getRows() != other.getRows() || this->getCols() != other.getCols())
                throw std::logic_error("Les matrices ne sont pas de la même taille.");
            MatrixNumerical<NumericType> result(this->getRows(), this->getCols());
            for (size_t i = 0; i < this->getRows(); ++i) {
                for (size_t j = 0; j < this->getCols(); ++j) {
                    result.setElement(i, j, this->getElement(i, j) + other.getElement(i, j));
                }
            }
            return result;
        }

        MatrixNumerical<NumericType> operator+(NumericType scalar) const {
            MatrixNumerical<NumericType> result(this->getRows(), this->getCols());
            for (size_t i = 0; i < this->getRows(); ++i) {
                for (size_t j = 0; j < this->getCols(); ++j) {
                    result.setElement(i, j, this->getElement(i, j) + scalar);
                }
            }
            return result;
        }

        MatrixNumerical<NumericType> operator-(const MatrixNumerical<NumericType>& other) const {
            if (this->getRows() != other.getRows() || this->getCols() != other.getCols())
                throw std::logic_error("Les matrices ne sont pas de la même taille.");
            MatrixNumerical<NumericType> result(this->getRows(), this->getCols());
            for (size_t i = 0; i < this->getRows(); ++i) {
                for (size_t j = 0; j < this->getCols(); ++j) {
                    result.setElement(i, j, this->getElement(i, j) - other.getElement(i, j));
                }
            }
            return result;
        }

        MatrixNumerical<NumericType> operator-(NumericType scalar) const {
            MatrixNumerical<NumericType> result(this->getRows(), this->getCols());
            for (size_t i = 0; i < this->getRows(); ++i) {
                for (size_t j = 0; j < this->getCols(); ++j) {
                    result.setElement(i, j, this->getElement(i, j) - scalar);
                }
            }
            return result;
        }

        MatrixNumerical<NumericType> operator*(const MatrixNumerical<NumericType>& other) const {
            if (this->getCols() != other.getRows())
                throw std::logic_error("Les dimensions des matrices ne sont pas compatibles.");
            MatrixNumerical<NumericType> result(this->getRows(), other.getCols());
            for (size_t i = 0; i < this->getRows(); ++i) {
                for (size_t j = 0; j < other.getCols(); ++j) {
                    NumericType sum = NumericType();
                    for (size_t k = 0; k < this->getCols(); ++k) {
                        sum += this->getElement(i, k) * other.getElement(k, j);
                    }
                    result.setElement(i, j, sum);
                }
            }
            return result;
        }

        MatrixNumerical<NumericType> operator*(NumericType scalar) const {
            MatrixNumerical<NumericType> result(this->getRows(), this->getCols());
            for (size_t i = 0; i < this->getRows(); ++i) {
                for (size_t j = 0; j < this->getCols(); ++j) {
                    result.setElement(i, j, this->getElement(i, j) * scalar);
                }
            }
            return result;
        }

        MatrixNumerical<NumericType> operator/(NumericType scalar) const {
            if (scalar == NumericType(0))
                throw std::logic_error("La division par zéro n'est pas autorisée.");
            MatrixNumerical<NumericType> result(this->getRows(), this->getCols());
            for (size_t i = 0; i < this->getRows(); ++i) {
                for (size_t j = 0; j < this->getCols(); ++j) {
                    result.setElement(i, j, this->getElement(i, j) / scalar);
                }
            }
            return result;
        }

        // methodes --------------- //
                NumericType getDeterminant() const {
            if (this->getRows() != this->getCols()) {
                throw std::logic_error("La matrice doit être carrée pour calculer le déterminant.");
            }

            // Appel initial à la fonction récursive
            return calculateDeterminant(*this);
        }

        // Fonction pour obtenir la matrice inverse en utilisant la méthode de cofacteur
        MatrixNumerical<NumericType> getInverse() const {
            if (this->getRows() != this->getCols()) {
                throw std::logic_error("La matrice doit être carrée pour avoir une inverse.");
            }
            NumericType determinant = getDeterminant();
            if (determinant == NumericType(0)) {
                throw std::logic_error("La matrice est singulière, elle n'a pas d'inverse.");
            }
            MatrixNumerical<NumericType> inverse(this->getRows(), this->getCols());
            for (size_t i = 0; i < this->getRows(); ++i) {
                for (size_t j = 0; j < this->getCols(); ++j) {
                    NumericType cofactor = getCoFactor(*this, i, j);
                    inverse.setElement(j, i, cofactor / determinant);
                }
            }
            return inverse;
        }

        // Fonction statique pour obtenir une matrice carrée identité
        static MatrixNumerical<NumericType> getIdentity(int size) {
            if (size <= 0) {
                throw std::logic_error("La taille de la matrice identité doit être un entier positif.");
            }
            MatrixNumerical<NumericType> identityMatrix(size, size);
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    identityMatrix.setElement(i, j, (i == j) ? NumericType(1) : NumericType(0));
                }
            }
            return identityMatrix;
        }

    private:
        // Fonction pour obtenir le cofacteur de l'élément (i, j)
        NumericType getCoFactor(const MatrixNumerical<NumericType>& matrix, size_t row, size_t col) const {
            if (matrix.getRows() != matrix.getCols()) {
                throw std::logic_error("La matrice doit être carrée pour obtenir un cofacteur.");
            }
            // Coefficient de Laplace : (-1)^(i+j) * determinant de la sous-matrice
            NumericType sign = ((row + col) % 2 == 0) ? NumericType(1) : NumericType(-1);
            return sign * calculateDeterminant(getSubMatrix(matrix, row, col));
        }

        // Fonction récursive pour calculer le déterminant
        NumericType calculateDeterminant(const MatrixNumerical<NumericType>& matrix) const {
            size_t size = matrix.getRows();
            if (size == 1) {
                // Cas de base : matrice 1x1
                return matrix.getElement(0, 0);
            }
            NumericType determinant = NumericType();
            for (size_t i = 0; i < size; ++i) {
                // Coefficient de Laplace : (-1)^(i+j) * matrix[i][j] * determinant de la sous-matrice
                NumericType sign = (i % 2 == 0) ? NumericType(1) : NumericType(-1);
                determinant += sign * matrix.getElement(0, i) * calculateDeterminant(getSubMatrix(matrix, 0, i));
            }
            return determinant;
        }

        // Fonction pour obtenir la sous-matrice en enlevant la ligne row et la colonne col
        MatrixNumerical<NumericType> getSubMatrix(const MatrixNumerical<NumericType>& matrix, size_t row, size_t col) const {
            size_t size = matrix.getRows();
            MatrixNumerical<NumericType> subMatrix(size - 1, size - 1);
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
};

#endif