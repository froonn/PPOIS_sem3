//
// Created by xinardelis on 16/09/24.
//

#include "../include/real_matrix.h"

real_matrix::ROW::ROW() {
    this->cols = 0;
    this->vector = nullptr;
}

real_matrix::ROW::ROW(int size) {
    this->vector = new double[size];
    this->cols = size;

    for (int i = 0; i < size; i += 1) {
        this->vector[i] = 0;
    }
}

real_matrix::ROW::ROW(const real_matrix::ROW &v) {
    this->cols = v.cols;
    this->vector = new double[this->cols];

    for (int i = 0; i < this->cols; i += 1) {
        this->vector[i] = v.vector[i];
    }
}

real_matrix::ROW::~ROW() {
    delete[] this->vector;
}

real_matrix::ROW &real_matrix::ROW::operator=(const real_matrix::ROW &v) {
    if (this == &v) {
        return *this;
    }

    delete[] this->vector;

    this->cols = v.cols;
    this->vector = new double[this->cols];

    for (int i = 0; i < this->cols; i += 1) {
        this->vector[i] = v.vector[i];
    }

    return *this;
}

double &real_matrix::ROW::operator[](int y) {
    if (0 <= y and y < this->cols) {
        return this->vector[y];
    } else {
        throw std::out_of_range("Index out of range");
    }
}

int real_matrix::ROW::size() const {
    return this->cols;
}

void real_matrix::ROW::resize(int new_size) {
    auto *new_vector = new double[new_size];

    for (int i = 0; i < new_size; i += 1) {
        this->vector[i] = 0;
    }

    for (int i = 0; i < std::min(this->cols, new_size); i += 1) {
        new_vector[i] = this->vector[i];
    }

    delete[] this->vector;

    this->cols = new_size;
    this->vector = new_vector;
}




