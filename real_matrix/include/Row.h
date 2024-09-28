//
// Created by xinardelis on 28/09/24.
//

#ifndef PPOIS_SEM3_ROW_H
#define PPOIS_SEM3_ROW_H

#include <stdexcept>

    /**
     * \class Row
     * \brief A class for representing a row of a matrix.
     */
class Row {
private:
    int cols;       ///< Number of columns in the row.
    double *vector; ///< Pointer to the array of elements in the row.

public:

    /// Default constructor.
    Row();

    /**
     * \brief Constructor with size.
     * \param size Number of columns in the row.
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


#endif //PPOIS_SEM3_ROW_H
