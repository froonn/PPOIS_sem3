//
// Created by xinardelis on 28/09/24.
//

#ifndef PPOIS_SEM3_ROW_H
#define PPOIS_SEM3_ROW_H

#include <stdexcept>

/**
 * \class Row
 * \brief A class for representing a Row of a matrix.
 */
class Row {
private:
    int cols_;       ///< Number of columns in the Row.
    double *vector_; ///< Pointer to the array of elements in the Row.

public:

    /// Default constructor.
    Row();

    /**
     * \brief Constructor with size.
     * \param size Number of columns in the Row.
     */
    explicit Row(int size);

    /**
     * \brief Copy constructor.
     * \param v The Row object to copy from.
     */
    Row(const Row &v);

    /// Destructor.
    ~Row();

    /**
     * \brief Assignment operator.
     * \param v The Row object to assign from.
     * \return Reference to the assigned Row object.
     */
    Row &operator=(const Row &v);

    /**
     * \brief Operator for getting an element of the vector_ by index.
     * \param y Index of the element.
     * \return Reference to the element at the specified index.
     * \throws std::out_of_range if the index is larger than the size of the vector_ or the index is negative
     */
    double &operator[](int y);

    /**
     * \brief Method for getting the size of the vector_.
     * \return The size of the vector_.
     */
    [[nodiscard]] int size() const;

    /**
     * \brief Method for resizing the vector_.
     * \param new_size The new size of the vector_.
     * The new vector_ is initialized with zeros.
     */
    void resize(int new_size);

    /**
     * \brief Inequality operator.
     * \param v The Row object to compare with.
     * \return True if the Rows are not equal, false otherwise.
     */
    bool operator!=(const Row &v);

    /**
     * \brief Equality operator.
     * \param v The Row object to compare with.
     * \return True if the Rows are equal, false otherwise.
     */
    bool operator==(const Row &v);

};

#endif //PPOIS_SEM3_ROW_H