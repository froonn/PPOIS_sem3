#include "../include/real_matrix.h"

RealMatrix::RealMatrix() {
    this->rows_ = 0;
    this->cols_ = 0;
    this->vectors_ = nullptr;
}

RealMatrix::RealMatrix(int rows, int cols) {
    this->rows_ = rows;
    this->cols_ = cols;

    this->vectors_ = new Row*[this->rows_];
    for (int i = 0; i < rows; i += 1) {
        this->vectors_[i] = new Row(this->cols_);
    }
}

RealMatrix::RealMatrix(const RealMatrix &m) : Row(m) {
    this->rows_ = m.rows_;
    this->cols_ = m.cols_;

    this->vectors_ = new Row*[this->rows_];
    for (int i = 0; i < this->rows_; i += 1) {
        this->vectors_[i] = new Row(m.vectors_[i]->size());
        *(this->vectors_[i]) = *(m.vectors_[i]);
    }
}

RealMatrix::Row &RealMatrix::operator[](int x) const {
    if (0 <= x and x < this->rows_) {
        return *(this->vectors_[x]);
    } else {
        throw std::out_of_range("Index out of range");
    }
}

RealMatrix::~RealMatrix() {
    for (int i = 0; i < this->rows_; i += 1) {
        delete this->vectors_[i];
    }
    delete[] this->vectors_;
}

RealMatrix &RealMatrix::operator=(const RealMatrix &m) {
    if (this == &m) {
        return *this;
    }

    // Освобождаем текущие ресурсы
    for (int i = 0; i < this->rows_; i += 1) {
        delete this->vectors_[i];
    }
    delete[] this->vectors_;

    // Копируем данные из исходного объекта
    this->cols_ = m.cols_;
    this->rows_ = m.rows_;

    this->vectors_ = new Row*[this->rows_];
    for (int i = 0; i < this->rows_; i += 1) {
        this->vectors_[i] = new Row(this->cols_);
        *(this->vectors_[i]) = m[i];
    }

    return *this;
}


void RealMatrix::T() {
    RealMatrix result(this->cols_, this->rows_);

    for (int i = 0; i < this->rows_; i += 1) {
        for (int j = 0; j < this->cols_; j += 1) {
            result[j][i] = (*this)[i][j];
        }
    }

    *this = result;
}

bool RealMatrix::is_square() const {
    return this->rows_ == this->cols_;
}

bool RealMatrix::is_diagonal() const {
    if (!this->is_square()) {
        return false;
    }

    for (int i = 0; i < this->rows_; i += 1) {
        for (int j = 0; j < this->cols_; j += 1) {
            if (i != j and (*this)[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
}

bool RealMatrix::is_zero() const {
    for (int i = 0; i < this->rows_; i += 1) {
        for (int j = 0; j < this->cols_; j += 1) {
            if ((*this)[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool RealMatrix::is_identity() const {
    if (!this->is_square()) {
        return false;
    }

    for (int i = 0; i < this->rows_; i += 1) {
        for (int j = 0; j < this->cols_; j += 1) {
            if ((i != j and (*this)[i][j] != 0) or (i == j and (*this)[i][j] != 1)) {
                return false;
            }
        }
    }

    return true;
}

bool RealMatrix::is_symmetric() const {
    if (!this->is_square()) {
        return false;
    }

    for (int i = 0; i < this->rows_; i += 1) {
        for (int j = i + 1; j < this->cols_; j += 1) {
            if ((*this)[i][j] != (*this)[j][i]) {
                return false;
            }
        }
    }

    return true;
}

bool RealMatrix::is_upper_triangular() const {
    if (!this->is_square()) {
        return false;
    }

    for (int i = 0; i < this->rows_; i += 1) {
        for (int j = 0; j < i; j += 1) {
            if ((*this)[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
}

bool RealMatrix::is_lower_triangular() const {
    if (!this->is_square()) {
        return false;
    }

    for (int i = 0; i < this->rows_; i += 1) {
        for (int j = i + 1; j < this->cols_; j += 1) {
            if ((*this)[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
}

// Resize of the current matrix
// The new matrix is initialized with zeros
void RealMatrix::resize(int rows, int cols) {
    RealMatrix result(rows, cols);

    for (int i = 0; i < std::min(this->rows_, rows); i += 1) {
        for (int j = 0; j < std::min(this->cols_, cols); j += 1) {
            result[i][j] = (*this)[i][j];
        }
    }

    *this = result;
}

// Create a submatrix from the current matrix
// The submatrix is always no larger than the current matrix
RealMatrix RealMatrix::submatrix(int rows, int cols) const {
    RealMatrix result(std::min(this->rows_, rows), std::min(this->cols_, cols));

    for (int i = 0; i < result.rows_; i += 1) {
        for (int j = 0; j < result.cols_; j += 1) {
            result[i][j] = (*this)[i][j];
        }
    }

    return result;
}

void RealMatrix::save_to_file(const std::string& filename) const {
    std::ofstream file(filename);

    file << this->rows_ << ' ' << this->cols_ << std::endl;

    for (int i = 0; i < this->rows_; i += 1) {
        for (int j = 0; j < this->cols_; j += 1) {
            file << (*this)[i][j] << ' ';
        }
        file << std::endl;
    }

    file.close();
}

void RealMatrix::load_from_file(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("File not found");
    }

    int rows, cols;
    file >> rows >> cols;

    RealMatrix result(rows, cols);
    for (int i = 0; i < rows; i += 1) {
        for (int j = 0; j < cols; j += 1) {
            file >> result[i][j];
        }
    }

    *this = result;
    file.close();
}

double RealMatrix::det() const {
    if (!this->is_square()) {
        throw std::logic_error("Matrix is not square");
    }

    if (this->rows_ == 1) {
        return (*this)[0][0];
    }

    if (this->rows_ == 2) {
        return (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
    }

    int result = 0;
    for (int i = 0; i < this->rows_; i += 1) {
        RealMatrix tmp = this->submatrix(this->rows_ - 1, this->cols_ - 1);
        for (int j = 0; j < this->rows_ - 1; j += 1) {
            for (int k = 0; k < this->cols_ - 1; k += 1) {
                tmp[j][k] = (*this)[j + 1][k >= i ? k + 1 : k];
            }
        }

        result += (i % 2 <= 0.1 ? 1. : -1.) * (*this)[0][i] * tmp.det();
    }

    return result;
}

double RealMatrix::norm() const {
    double result = 0;
    for (int i = 0; i < this->rows_; i += 1) {
        double sum = 0;
        for (int j = 0; j < this->cols_; j += 1) {
            sum += std::abs((*this)[i][j]);
        }
        result = std::max(result, sum);
    }

    return result;
}

RealMatrix &RealMatrix::operator++() {
    for (int i = 0; i < this->rows_; i += 1) {
        for (int j = 0; j < this->cols_; j += 1) {
            (*this)[i][j] += 1;
        }
    }

    return *this;
}

RealMatrix RealMatrix::operator++(int) {
    RealMatrix result(*this);
    ++(*this);
    return result;
}

RealMatrix &RealMatrix::operator--() {
    for (int i = 0; i < this->rows_; i += 1) {
        for (int j = 0; j < this->cols_; j += 1) {
            (*this)[i][j] -= 1;
        }
    }

    return *this;
}

RealMatrix RealMatrix::operator--(int) {
    RealMatrix result(*this);
    --(*this);
    return result;
}

RealMatrix &RealMatrix::operator+=(const RealMatrix &other) {
    if (this->rows_ != other.rows_ or this->cols_ != other.cols_) {
        throw std::logic_error("Matrices have different sizes");
    }

    for (int i = 0; i < this->rows_; i += 1) {
        for (int j = 0; j < this->cols_; j += 1) {
            (*this)[i][j] += other[i][j];
        }
    }

    return *this;
}

RealMatrix RealMatrix::operator+(const RealMatrix &other) const {
    RealMatrix result(*this);
    result += other;
    return result;
}

RealMatrix &RealMatrix::operator+=(double value) {
    for (int i = 0; i < this->rows_; i += 1) {
        for (int j = 0; j < this->cols_; j += 1) {
            (*this)[i][j] += value;
        }
    }

    return *this;
}

RealMatrix RealMatrix::operator+(double value) const {
    RealMatrix result(*this);
    result += value;
    return result;
}

RealMatrix &RealMatrix::operator-=(const RealMatrix &other) {
    if (this->rows_ != other.rows_ or this->cols_ != other.cols_) {
        throw std::logic_error("Matrices have different sizes");
    }

    for (int i = 0; i < this->rows_; i += 1) {
        for (int j = 0; j < this->cols_; j += 1) {
            (*this)[i][j] -= other[i][j];
        }
    }

    return *this;
}

RealMatrix RealMatrix::operator-(const RealMatrix &other) const {
    RealMatrix result(*this);
    result -= other;
    return result;
}

RealMatrix &RealMatrix::operator-=(double value) {
    for (int i = 0; i < this->rows_; i += 1) {
        for (int j = 0; j < this->cols_; j += 1) {
            (*this)[i][j] -= value;
        }
    }

    return *this;
}

RealMatrix RealMatrix::operator-(double value) const {
    RealMatrix result(*this);
    result -= value;
    return result;
}

RealMatrix &RealMatrix::operator*=(double value) {
    for (int i = 0; i < this->rows_; i += 1) {
        for (int j = 0; j < this->cols_; j += 1) {
            (*this)[i][j] *= value;
        }
    }

    return *this;
}

RealMatrix RealMatrix::operator*(double value) const {
    RealMatrix result(*this);
    result *= value;
    return result;
}

RealMatrix RealMatrix::operator*(const RealMatrix &other) const {
    if (this->cols_ != other.rows_) {
        throw std::logic_error("Matrices have incompatible sizes");
    }

    RealMatrix result(this->rows_, other.cols_);
    for (int i = 0; i < this->rows_; i += 1) {
        for (int j = 0; j < other.cols_; j += 1) {
            for (int k = 0; k < this->cols_; k += 1) {
                result[i][j] += (*this)[i][k] * other[k][j];
            }
        }
    }

    return result;
}

RealMatrix RealMatrix::operator*=(const RealMatrix &other) {
    *this = *this * other;
    return *this;
}

RealMatrix RealMatrix::operator/=(double value) {
    for (int i = 0; i < this->rows_; i += 1) {
        for (int j = 0; j < this->cols_; j += 1) {
            (*this)[i][j] /= value;
        }
    }

    return *this;
}

RealMatrix RealMatrix::operator/(double value) const {
    RealMatrix result(*this);
    result /= value;
    return result;
}

RealMatrix RealMatrix::operator^=(double value) {
    if (value == 0) {
        if (!this->is_square()) {
            throw std::logic_error("Matrix is not square");
        }

        for (int i = 0; i < this->rows_; i += 1) {
            for (int j = 0; j < this->cols_; j += 1) {
                if (i == j) {
                    (*this)[i][j] = 1;
                } else {
                    (*this)[i][j] = 0;
                }
            }
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

RealMatrix RealMatrix::operator^(double value) const {
    RealMatrix result(*this);
    result ^= value;
    return result;
}

bool RealMatrix::operator==(const RealMatrix &other) const {
    if (this->rows_ != other.rows_ or this->cols_ != other.cols_) {
        return false;
    }

    for (int i = 0; i < this->rows_; i += 1) {
        for (int j = 0; j < this->cols_; j += 1) {
            if ((*this)[i][j] != other[i][j]) {
                return false;
            }
        }
    }

    return true;
}

bool RealMatrix::operator!=(const RealMatrix &other) const {
    return !(*this == other);
}


std::ostream &operator<<(std::ostream &os, const RealMatrix &m) {
    for (int i = 0; i < m[0].size(); i += 1) {
        for (int j = 0; j < m.size(); j += 1) {
            os << m[i][j] << ' ';
        }
        os << std::endl;
    }

    return os;
}

int RealMatrix::size() const {
    return this->rows_;
}
