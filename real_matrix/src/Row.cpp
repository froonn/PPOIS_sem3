//
// Created by xinardelis on 16/09/24.
//

#include "../include/Row.h"

Row::Row() {
    this->cols = 0;
    this->vector = nullptr;
}

Row::Row(int size) {
    this->vector = new double[size];
    this->cols = size;

    for (int i = 0; i < size; i += 1) {
        this->vector[i] = 0;
    }
}

Row::Row(const Row &v) {
    this->cols = v.cols;
    this->vector = new double[this->cols];

    for (int i = 0; i < this->cols; i += 1) {
        this->vector[i] = v.vector[i];
    }
}

Row::~Row() {
    delete[] this->vector;
}

Row &Row::operator=(const Row &v) {
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

double &Row::operator[](int y) {
    if (0 <= y and y < this->cols) {
        return this->vector[y];
    } else {
        throw std::out_of_range("Index out of range");
    }
}

int Row::size() const {
    return this->cols;
}

void Row::resize(int new_size) {
    double *new_vector = new double[new_size];

    for (int i = 0; i < new_size; i += 1) {
        new_vector[i] = 0;
    }

    for (int i = 0; i < std::min(this->cols, new_size); i += 1) {
        new_vector[i] = this->vector[i];
    }

    delete[] this->vector;

    this->cols = new_size;
    this->vector = new_vector;
}




