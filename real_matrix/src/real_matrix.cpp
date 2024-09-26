//
// Created by xinardelis on 14/09/24.
//

#include "../include/real_matrix.h"

real_matrix::real_matrix() {
    this->rows = 0;
    this->cols = 0;
    this->vectors = nullptr;
}

real_matrix::real_matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;

    this->vectors = new ROW*[this->rows];
    for (int i = 0; i < rows; i += 1) {
        this->vectors[i] = new ROW(this->cols);
    }
}

real_matrix::real_matrix(const real_matrix &m) {
    this->rows = m.rows;
    this->cols = m.cols;

    this->vectors = new ROW*[this->rows];
    for (int i = 0; i < this->rows; i += 1) {
        this->vectors[i] = new ROW(this->cols);
        *(this->vectors[i]) = m[i];
    }
}

real_matrix::ROW &real_matrix::operator[](int x) const {
    if (0 <= x and x < this->rows) {
        return *(this->vectors[x]);
    } else {
        throw std::out_of_range("Index out of range");
    }
}

real_matrix::~real_matrix() {
    for (int i = 0; i < this->rows; i += 1) {
        delete this->vectors[i];
    }
    delete[] this->vectors;
}

real_matrix &real_matrix::operator=(const real_matrix &m) {
    if (this == &m) {
        return *this;
    }

    // Освобождаем текущие ресурсы
    for (int i = 0; i < this->rows; i += 1) {
        delete this->vectors[i];
    }
    delete[] this->vectors;

    // Копируем данные из исходного объекта
    this->cols = m.cols;
    this->rows = m.rows;

    this->vectors = new ROW*[this->rows];
    for (int i = 0; i < this->rows; i += 1) {
        this->vectors[i] = new ROW(this->cols);
        *(this->vectors[i]) = m[i];
    }

    return *this;
}


void real_matrix::T() {
    real_matrix temp(this->cols, this->rows);

    for (int i = 0; i < this->rows; i += 1) {
        for (int j = 0; j < this->cols; j += 1) {
            temp[j][i] = (*this)[i][j];
        }
    }

    *this = temp;
}

bool real_matrix::is_square() {
    return this->rows == this->cols;
}

bool real_matrix::is_diagonal() {
    if (!this->is_square()) {
        return false;
    }

    for (int i = 0; i < this->rows; i += 1) {
        for (int j = 0; j < this->cols; j += 1) {
            if (i != j and (*this)[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
}

bool real_matrix::is_zero() {
    for (int i = 0; i < this->rows; i += 1) {
        for (int j = 0; j < this->cols; j += 1) {
            if ((*this)[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool real_matrix::is_identity() {
    if (!this->is_square()) {
        return false;
    }

    for (int i = 0; i < this->rows; i += 1) {
        for (int j = 0; j < this->cols; j += 1) {
            if ((i != j and (*this)[i][j] != 0) or (i == j and (*this)[i][j] != 1)) {
                return false;
            }
        }
    }

    return true;
}

bool real_matrix::is_symmetric() {
    if (!this->is_square()) {
        return false;
    }

    for (int i = 0; i < this->rows; i += 1) {
        for (int j = i + 1; j < this->cols; j += 1) {
            if ((*this)[i][j] != (*this)[j][i]) {
                return false;
            }
        }
    }

    return true;
}

bool real_matrix::is_upper_triangular() {
    if (!this->is_square()) {
        return false;
    }

    for (int i = 0; i < this->rows; i += 1) {
        for (int j = 0; j < i; j += 1) {
            if ((*this)[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
}

bool real_matrix::is_lower_triangular() {
    if (!this->is_square()) {
        return false;
    }

    for (int i = 0; i < this->rows; i += 1) {
        for (int j = i + 1; j < this->cols; j += 1) {
            if ((*this)[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
}

// Resize of the current matrix
// The new matrix is initialized with zeros
void real_matrix::resize(int rows, int cols) {
    real_matrix temp(rows, cols);

    for (int i = 0; i < std::min(this->rows, rows); i += 1) {
        for (int j = 0; j < std::min(this->cols, cols); j += 1) {
            temp[i][j] = (*this)[i][j];
        }
    }

    *this = temp;
}

// Create a submatrix from the current matrix
// The submatrix is always no larger than the current matrix
real_matrix real_matrix::submatrix(int rows, int cols) {
    real_matrix temp(std::min(this->rows, rows), std::min(this->cols, cols));

    for (int i = 0; i < temp.rows; i += 1) {
        for (int j = 0; j < temp.cols; j += 1) {
            temp[i][j] = (*this)[i][j];
        }
    }

    return temp;
}

void real_matrix::save_to_file(std::string filename) {
    std::ofstream file(filename);

    file << this->rows << ' ' << this->cols << std::endl;

    for (int i = 0; i < this->rows; i += 1) {
        for (int j = 0; j < this->cols; j += 1) {
            file << (*this)[i][j] << ' ';
        }
        file << std::endl;
    }

    file.close();
}

void real_matrix::load_from_file(std::string filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("File not found");
    }

    int rows, cols;
    file >> rows >> cols;

    real_matrix temp(rows, cols);
    for (int i = 0; i < rows; i += 1) {
        for (int j = 0; j < cols; j += 1) {
            file >> temp[i][j];
        }
    }

    *this = temp;
    file.close();
}

int real_matrix::det() {
    if (!this->is_square()) {
        throw std::logic_error("Matrix is not square");
    }

    if (this->rows == 1) {
        return (*this)[0][0];
    }

    if (this->rows == 2) {
        return (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
    }

    int result = 0;
    for (int i = 0; i < this->rows; i += 1) {
        real_matrix temp = this->submatrix(this->rows - 1, this->cols - 1);
        for (int j = 0; j < this->rows - 1; j += 1) {
            for (int k = 0; k < this->cols - 1; k += 1) {
                temp[j][k] = (*this)[j + 1][k >= i ? k + 1 : k];
            }
        }

        result += (i % 2 == 0 ? 1 : -1) * (*this)[0][i] * temp.det();
    }

    return result;
}

double real_matrix::norm() {
    double result = 0;
    for (int i = 0; i < this->rows; i += 1) {
        double sum = 0;
        for (int j = 0; j < this->cols; j += 1) {
            sum += std::abs((*this)[i][j]);
        }
        result = std::max(result, sum);
    }

    return result;
}

real_matrix &real_matrix::operator++() {
    for (int i = 0; i < this->rows; i += 1) {
        for (int j = 0; j < this->cols; j += 1) {
            (*this)[i][j] += 1;
        }
    }

    return *this;
}

real_matrix real_matrix::operator++(int) {
    real_matrix temp(*this);
    ++(*this);
    return temp;
}

real_matrix &real_matrix::operator--() {
    for (int i = 0; i < this->rows; i += 1) {
        for (int j = 0; j < this->cols; j += 1) {
            (*this)[i][j] -= 1;
        }
    }

    return *this;
}

real_matrix real_matrix::operator--(int) {
    real_matrix temp(*this);
    --(*this);
    return temp;
}

real_matrix &real_matrix::operator+=(const real_matrix &other) {
    if (this->rows != other.rows or this->cols != other.cols) {
        throw std::logic_error("Matrices have different sizes");
    }

    for (int i = 0; i < this->rows; i += 1) {
        for (int j = 0; j < this->cols; j += 1) {
            (*this)[i][j] += other[i][j];
        }
    }

    return *this;
}

real_matrix real_matrix::operator+(const real_matrix &other) const {
    real_matrix temp(*this);
    temp += other;
    return temp;
}

real_matrix &real_matrix::operator+=(double value) {
    for (int i = 0; i < this->rows; i += 1) {
        for (int j = 0; j < this->cols; j += 1) {
            (*this)[i][j] += value;
        }
    }

    return *this;
}

real_matrix real_matrix::operator+(double value) const {
    real_matrix temp(*this);
    temp += value;
    return temp;
}

real_matrix &real_matrix::operator-=(const real_matrix &other) {
    if (this->rows != other.rows or this->cols != other.cols) {
        throw std::logic_error("Matrices have different sizes");
    }

    for (int i = 0; i < this->rows; i += 1) {
        for (int j = 0; j < this->cols; j += 1) {
            (*this)[i][j] -= other[i][j];
        }
    }

    return *this;
}

real_matrix real_matrix::operator-(const real_matrix &other) const {
    real_matrix temp(*this);
    temp -= other;
    return temp;
}

real_matrix &real_matrix::operator-=(double value) {
    for (int i = 0; i < this->rows; i += 1) {
        for (int j = 0; j < this->cols; j += 1) {
            (*this)[i][j] -= value;
        }
    }

    return *this;
}

real_matrix real_matrix::operator-(double value) const {
    real_matrix temp(*this);
    temp -= value;
    return temp;
}

real_matrix &real_matrix::operator*=(double value) {
    for (int i = 0; i < this->rows; i += 1) {
        for (int j = 0; j < this->cols; j += 1) {
            (*this)[i][j] *= value;
        }
    }

    return *this;
}

real_matrix real_matrix::operator*(double value) const {
    real_matrix temp(*this);
    temp *= value;
    return temp;
}

real_matrix real_matrix::operator*(const real_matrix &other) const {
    if (this->cols != other.rows) {
        throw std::logic_error("Matrices have incompatible sizes");
    }

    real_matrix temp(this->rows, other.cols);
    for (int i = 0; i < this->rows; i += 1) {
        for (int j = 0; j < other.cols; j += 1) {
            for (int k = 0; k < this->cols; k += 1) {
                temp[i][j] += (*this)[i][k] * other[k][j];
            }
        }
    }

    return temp;
}

real_matrix real_matrix::operator*=(const real_matrix &other) {
    *this = *this * other;
    return *this;
}

real_matrix real_matrix::operator/=(double value) {
    for (int i = 0; i < this->rows; i += 1) {
        for (int j = 0; j < this->cols; j += 1) {
            (*this)[i][j] /= value;
        }
    }

    return *this;
}

real_matrix real_matrix::operator/(double value) const {
    real_matrix temp(*this);
    temp /= value;
    return temp;
}

real_matrix real_matrix::operator^=(double value) {
    if (value == 0) {
        if (!this->is_square()) {
            throw std::logic_error("Matrix is not square");
        }

        for (int i = 0; i < this->rows; i += 1) {
            (*this)[i][i] = 1;
        }

        return *this;
    }

    if (value < 0) {
        throw std::logic_error("Negative power is not supported");
    }

    for (int i = 1; i < value; i += 1) {
        *this *= *this;
    }

    return *this;
}

real_matrix real_matrix::operator^(double value) const {
    real_matrix temp(*this);
    temp ^= value;
    return temp;
}

bool real_matrix::operator==(const real_matrix &other) const {
    if (this->rows != other.rows or this->cols != other.cols) {
        return false;
    }

    for (int i = 0; i < this->rows; i += 1) {
        for (int j = 0; j < this->cols; j += 1) {
            if ((*this)[i][j] != other[i][j]) {
                return false;
            }
        }
    }

    return true;
}

bool real_matrix::operator!=(const real_matrix &other) const {
    return !(*this == other);
}


std::ostream &operator<<(std::ostream &os, const real_matrix &m) {
    for (int i = 0; i < m[0].size(); i += 1) {
        for (int j = 0; j < m.size(); j += 1) {
            os << m[i][j] << ' ';
        }
        os << std::endl;
    }

    return os;
}

int real_matrix::size() const {
    return this->rows;
}
