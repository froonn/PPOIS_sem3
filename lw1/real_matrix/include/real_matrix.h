//
// Created by xinardelis on 14/09/24.
//

#ifndef PPOIS_SEM3_REAL_MATRIX_H
#define PPOIS_SEM3_REAL_MATRIX_H

#include <algorithm>
#include <iostream>
#include <fstream>
#include <stdexcept>

#include "row.h"


/**
 * \class RealMatrix
 * \brief A class for representing and manipulating real matrices.
 */
class RealMatrix : public Row {
public:

    /// Default constructor.
    RealMatrix();

    /**
     * \brief Constructor with dimensions.
     * \param rows Number of rows_ in the matrix.
     * \param cols Number of columns in the matrix.
     */
    explicit RealMatrix(int rows, int cols);

    /**
     * \brief Copy constructor.
     * \param m The RealMatrix object to copy from.
     */
    RealMatrix(const RealMatrix &m);

    /// Destructor.
    ~RealMatrix();

    /**
     * \brief Assignment operator.
     * \param m The RealMatrix object to assign from.
     * \return Reference to the assigned RealMatrix object.
     */
    RealMatrix &operator=(const RealMatrix &m);

    /**
     * \brief Method for loading a matrix from a file.
     * \param filename The name of the file to load the matrix from.
     * \throw std::runtime_error if the file cannot be opened.
     */
    void load_from_file(const std::string& filename);

    /**
     * \brief Method for saving a matrix to a file.
     * \param filename The name of the file to save the matrix to.
     */
    void save_to_file(const std::string& filename) const;

    /**
     * \brief Method for resizing the matrix.
     * The new matrix is initialized with zeros.
     * \param rows The new number of rows_.
     * \param cols The new number of columns.
     */
    void resize(int rows, int cols);

    /**
     * \brief Method for getting the number of rows_ in the matrix.
     * \return The number of rows_ in the matrix.
     */
    [[nodiscard]] int size() const;

    /**
     * \brief Method for getting a submatrix of the matrix. The
     * submatrix is always no larger than the current matrix.
     * \param rows The number of rows_ in the submatrix.
     * \param cols The number of columns in the submatrix.
     * \return The submatrix.
     */
    [[nodiscard]] RealMatrix submatrix(int rows, int cols) const;

    /**
     * \brief Operator for getting a Row of the matrix by index.
     * \param x Index of the Row.
     * \return Reference to the Row at the specified index.
     * \throws std::out_of_range if the index is out of range.
     */
    RealMatrix::Row &operator[](int x) const;

    /// Method for transposing the matrix.
    void T();

    /**
     * \brief Method for calculating the determinant of the matrix.
     * \return The determinant of the matrix.
     * \throw std::logic_error if the matrix is not square.
     */
    [[nodiscard]] double det() const;

    /// Method for calculating the maximum norm of the matrix.
    [[nodiscard]] double norm() const;

    /// Prefix increment operator.
    RealMatrix &operator++();

    /// Postfix increment operator.
    RealMatrix operator++(int);

    /// Prefix decrement operator.
    RealMatrix &operator--();

    /// Postfix decrement operator.
    RealMatrix operator--(int);

    /**
     * \brief Addition assignment operator.
     * \param other The matrix to add.
     * \return Reference to the resulting matrix.
     * \throw std::logic_error if the matrices have different dimensions.
     */
    RealMatrix &operator+=(const RealMatrix &other);

    /**
     * \brief Addition operator.
     * \param other The matrix to add.
     * \return The resulting matrix.
     * \throw std::logic_error if the matrices have different dimensions.
     */
    RealMatrix operator+(const RealMatrix &other) const;

    /**
     * \brief Addition assignment operator with a scalar.
     * \param value The scalar value to add.
     * \return Reference to the resulting matrix.
     */
    RealMatrix &operator+=(double value);

    /**
     * \brief Addition operator with a scalar.
     * \param value The scalar value to add.
     * \return The resulting matrix.
     */
    RealMatrix operator+(double value) const;

    /**
     * \brief Subtraction assignment operator.
     * \param other The matrix to subtract.
     * \return Reference to the resulting matrix.
     * \throw std::logic_error if the matrices have different dimensions.
     */
    RealMatrix &operator-=(const RealMatrix &other);

    /**
     * \brief Subtraction operator.
     * \param other The matrix to subtract.
     * \return The resulting matrix.
     * \throw std::logic_error if the matrices have different dimensions.
     */
    RealMatrix operator-(const RealMatrix &other) const;

    /**
     * \brief Subtraction assignment operator with a scalar.
     * \param value The scalar value to subtract.
     * \return Reference to the resulting matrix.
     */
    RealMatrix &operator-=(double value);

    /**
     * \brief Subtraction operator with a scalar.
     * \param value The scalar value to subtract.
     * \return The resulting matrix.
     */
    RealMatrix operator-(double value) const;

    /**
     * \brief Multiplication assignment operator with a scalar.
     * \param value The scalar value to multiply.
     * \return Reference to the resulting matrix.
     */
    RealMatrix &operator*=(double value);

    /**
     * \brief Multiplication operator with a scalar.
     * \param value The scalar value to multiply.
     * \return The resulting matrix.
     */
    RealMatrix operator*(double value) const;

    /**
     * \brief Multiplication assignment operator with another matrix.
     * \param other The matrix to multiply.
     * \return Reference to the resulting matrix.
     * \throw std::logic_error if the matrices have incompatible dimensions.
     */
    RealMatrix operator*=(const RealMatrix &other);

    /**
     * \brief Multiplication operator with another matrix.
     * \param other The matrix to multiply.
     * \return The resulting matrix.
     * \throw std::logic_error if the matrices have incompatible dimensions.
     */
    RealMatrix operator*(const RealMatrix &other) const;

    /**
     * \brief Division assignment operator with a scalar.
     * \param value The scalar value to divide.
     * \return Reference to the resulting matrix.
     */
    RealMatrix operator/=(double value);

    /**
     * \brief Division operator with a scalar.
     * \param value The scalar value to divide.
     * \return The resulting matrix.
     */
    RealMatrix operator/(double value) const;

    /**
     * \brief Exponentiation assignment operator with a scalar.
     * \param value The scalar value to exponentiate.
     * \return Reference to the resulting matrix.
     * \throw std::logic_error if the matrix is not square or the exponent is negative.
     */
    RealMatrix operator^=(double value);

    /**
     * \brief Exponentiation operator with a scalar.
     * \param value The scalar value to exponentiate.
     * \return The resulting matrix.
     * \throw std::logic_error if the matrix is not square or the exponent is negative.
     */
    RealMatrix operator^(double value) const;

    /**
     * \brief Equality operator.
     * \param other The matrix to compare.
     * \return True if the matrices are equal, false otherwise.
     */
    bool operator==(const RealMatrix &other) const;

    /**
     * \brief Inequality operator.
     * \param other The matrix to compare.
     * \return True if the matrices are not equal, false otherwise.
     */
    bool operator!=(const RealMatrix &other) const;

    /// Method for checking if the matrix is square.
    [[nodiscard]] bool is_square() const;

    /// Method for checking if the matrix is diagonal.
    [[nodiscard]] bool is_diagonal() const;

    /// Method for checking if the matrix is a zero matrix.
    [[nodiscard]] bool is_zero() const;

    /// Method for checking if the matrix is an identity matrix.
    [[nodiscard]] bool is_identity() const;

    /// Method for checking if the matrix is symmetric.
    [[nodiscard]] bool is_symmetric() const;

    /// Method for checking if the matrix is upper triangular.
    [[nodiscard]] bool is_upper_triangular() const;

    /// Method for checking if the matrix is lower triangular.
    [[nodiscard]] bool is_lower_triangular() const;

private:

    int cols_;       ///< Number of columns in the matrix.
    int rows_;       ///< Number of rows_ in the matrix.
    Row **vectors_;  ///< Pointer to the array of Row pointers.

};

std::ostream &operator<<(std::ostream &os, const RealMatrix &m);

#endif //PPOIS_SEM3_REAL_MATRIX_H