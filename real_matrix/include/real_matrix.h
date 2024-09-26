//
// Created by xinardelis on 14/09/24.
//

#ifndef PPOIS_SEM3_REAL_MATRIX_H
#define PPOIS_SEM3_REAL_MATRIX_H

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

/**
 * \class real_matrix
 * \brief A class for representing and manipulating real matrices.
 */
class real_matrix {
public:

    /**
     * \class ROW
     * \brief A class for representing a row of a matrix.
     */
    class ROW {
    private:
        int cols;       ///< Number of columns in the row.
        double *vector; ///< Pointer to the array of elements in the row.

    public:

        /// Default constructor.
        ROW();

        /**
         * \brief Constructor with size.
         * \param size Number of columns in the row.
         */
        explicit ROW(int size);

        /**
         * \brief Copy constructor.
         * \param v The ROW object to copy from.
         */
        ROW(const ROW &v);

        /// Destructor.
        ~ROW();

        /**
         * \brief Assignment operator.
         * \param v The ROW object to assign from.
         * \return Reference to the assigned ROW object.
         */
        ROW &operator=(const ROW &v);

        /**
         * \brief Operator for getting an element of the vector by index.
         * \param y Index of the element.
         * \return Reference to the element at the specified index.
         * \throws std::out_of_range if the index is larger than the size of the vector or the index is negative
         */
        double &operator[](int y);

        /**
         * \brief Method for getting the size of the vector.
         * \return The size of the vector.
         */
        int size() const;

        /**
         * \brief Method for resizing the vector.
         * \param new_size The new size of the vector.
         * The new vector is initialized with zeros.
         */
        void resize(int new_size);

    };

    /// Default constructor.
    real_matrix();

    /**
     * \brief Constructor with dimensions.
     * \param rows Number of rows in the matrix.
     * \param cols Number of columns in the matrix.
     */
    real_matrix(int rows, int cols);

    /**
     * \brief Copy constructor.
     * \param m The real_matrix object to copy from.
     */
    real_matrix(const real_matrix &m);

    /// Destructor.
    ~real_matrix();

    /**
     * \brief Assignment operator.
     * \param m The real_matrix object to assign from.
     * \return Reference to the assigned real_matrix object.
     */
    real_matrix &operator=(const real_matrix &m);

    /**
     * \brief Method for loading a matrix from a file.
     * \param filename The name of the file to load the matrix from.
     * \throw std::runtime_error if the file cannot be opened.
     */
    void load_from_file(std::string filename);

    /**
     * \brief Method for saving a matrix to a file.
     * \param filename The name of the file to save the matrix to.
     */
    void save_to_file(std::string filename);

    /**
     * \brief Method for resizing the matrix.
     * \param rows The new number of rows.
     * \param cols The new number of columns.
     * The new matrix is initialized with zeros.
     */
    void resize(int rows, int cols);

    /**
     * \brief Method for getting the number of rows in the matrix.
     * \return The number of rows in the matrix.
     */
    int size() const;

    /**
     * \brief Method for getting a submatrix of the matrix.
     * \param rows The number of rows in the submatrix.
     * \param cols The number of columns in the submatrix.
     * \return The submatrix.
     * The submatrix is always no larger than the current matrix.
     */
    real_matrix submatrix(int rows, int cols);

    /**
     * \brief Operator for getting a row of the matrix by index.
     * \param x Index of the row.
     * \return Reference to the row at the specified index.
     * \throws std::out_of_range if the index is out of range.
     */
    real_matrix::ROW &operator[](int x) const;

    /// Method for transposing the matrix.
    void T();

    /**
     * \brief Method for calculating the determinant of the matrix.
     * \return The determinant of the matrix.
     * \throw std::logic_error if the matrix is not square.
     */
    int det();

    /// Method for calculating the maximum norm of the matrix.
    double norm();

    /// Prefix increment operator.
    real_matrix &operator++();

    /// Postfix increment operator.
    real_matrix operator++(int);

    /// Prefix decrement operator.
    real_matrix &operator--();

    /// Postfix decrement operator.
    real_matrix operator--(int);

    /**
     * \brief Addition assignment operator.
     * \param other The matrix to add.
     * \return Reference to the resulting matrix.
     * \throw std::logic_error if the matrices have different dimensions.
     */
    real_matrix &operator+=(const real_matrix &other);

    /**
     * \brief Addition operator.
     * \param other The matrix to add.
     * \return The resulting matrix.
     * \throw std::logic_error if the matrices have different dimensions.
     */
    real_matrix operator+(const real_matrix &other) const;

    /**
     * \brief Addition assignment operator with a scalar.
     * \param value The scalar value to add.
     * \return Reference to the resulting matrix.
     */
    real_matrix &operator+=(double value);

    /**
     * \brief Addition operator with a scalar.
     * \param value The scalar value to add.
     * \return The resulting matrix.
     */
    real_matrix operator+(double value) const;

    /**
     * \brief Subtraction assignment operator.
     * \param other The matrix to subtract.
     * \return Reference to the resulting matrix.
     * \throw std::logic_error if the matrices have different dimensions.
     */
    real_matrix &operator-=(const real_matrix &other);

    /**
     * \brief Subtraction operator.
     * \param other The matrix to subtract.
     * \return The resulting matrix.
     * \throw std::logic_error if the matrices have different dimensions.
     */
    real_matrix operator-(const real_matrix &other) const;

    /**
     * \brief Subtraction assignment operator with a scalar.
     * \param value The scalar value to subtract.
     * \return Reference to the resulting matrix.
     */
    real_matrix &operator-=(double value);

    /**
     * \brief Subtraction operator with a scalar.
     * \param value The scalar value to subtract.
     * \return The resulting matrix.
     */
    real_matrix operator-(double value) const;

    /**
     * \brief Multiplication assignment operator with a scalar.
     * \param value The scalar value to multiply.
     * \return Reference to the resulting matrix.
     */
    real_matrix &operator*=(double value);

    /**
     * \brief Multiplication operator with a scalar.
     * \param value The scalar value to multiply.
     * \return The resulting matrix.
     */
    real_matrix operator*(double value) const;

    /**
     * \brief Multiplication assignment operator with another matrix.
     * \param other The matrix to multiply.
     * \return Reference to the resulting matrix.
     * \throw std::logic_error if the matrices have incompatible dimensions.
     */
    real_matrix operator*=(const real_matrix &other);

    /**
     * \brief Multiplication operator with another matrix.
     * \param other The matrix to multiply.
     * \return The resulting matrix.
     * \throw std::logic_error if the matrices have incompatible dimensions.
     */
    real_matrix operator*(const real_matrix &other) const;

    /**
     * \brief Division assignment operator with a scalar.
     * \param value The scalar value to divide.
     * \return Reference to the resulting matrix.
     */
    real_matrix operator/=(double value);

    /**
     * \brief Division operator with a scalar.
     * \param value The scalar value to divide.
     * \return The resulting matrix.
     */
    real_matrix operator/(double value) const;

    /**
     * \brief Exponentiation assignment operator with a scalar.
     * \param value The scalar value to exponentiate.
     * \return Reference to the resulting matrix.
     * \throw std::logic_error if the matrix is not square or the exponent is negative.
     */
    real_matrix operator^=(double value);

    /**
     * \brief Exponentiation operator with a scalar.
     * \param value The scalar value to exponentiate.
     * \return The resulting matrix.
     * \throw std::logic_error if the matrix is not square or the exponent is negative.
     */
    real_matrix operator^(double value) const;

    /**
     * \brief Equality operator.
     * \param other The matrix to compare.
     * \return True if the matrices are equal, false otherwise.
     */
    bool operator==(const real_matrix &other) const;

    /**
     * \brief Inequality operator.
     * \param other The matrix to compare.
     * \return True if the matrices are not equal, false otherwise.
     */
    bool operator!=(const real_matrix &other) const;

    /// Method for checking if the matrix is square.
    bool is_square();

    /// Method for checking if the matrix is diagonal.
    bool is_diagonal();

    /// Method for checking if the matrix is a zero matrix.
    bool is_zero();

    /// Method for checking if the matrix is an identity matrix.
    bool is_identity();

    /// Method for checking if the matrix is symmetric.
    bool is_symmetric();

    /// Method for checking if the matrix is upper triangular.
    bool is_upper_triangular();

    /// Method for checking if the matrix is lower triangular.
    bool is_lower_triangular();

private:

    int cols;       ///< Number of columns in the matrix.
    int rows;       ///< Number of rows in the matrix.
    ROW **vectors;  ///< Pointer to the array of row pointers.

};

std::ostream &operator<<(std::ostream &os, const real_matrix &m);

#endif //PPOIS_SEM3_REAL_MATRIX_H