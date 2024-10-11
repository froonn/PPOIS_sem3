//
// Created by xinardelis on 16/09/24.
//

#include "../include/row.h"

Row::Row() {
    this->cols_ = 0;
    this->vector_ = nullptr;
}

Row::Row(int size) {
    this->vector_ = new double[size];
    this->cols_ = size;

    for (int i = 0; i < size; i += 1) {
        this->vector_[i] = 0;
    }
}

Row::Row(const Row &v) {
    this->cols_ = v.cols_;
    this->vector_ = new double[this->cols_];

    for (int i = 0; i < this->cols_; i += 1) {
        this->vector_[i] = v.vector_[i];
    }
}

Row::~Row() {
    delete[] this->vector_;
}

Row &Row::operator=(const Row &v) {
    if (this == &v) {
        return *this;
    }

    delete[] this->vector_;

    this->cols_ = v.cols_;
    this->vector_ = new double[this->cols_];

    for (int i = 0; i < this->cols_; i += 1) {
        this->vector_[i] = v.vector_[i];
    }

    return *this;
}

double &Row::operator[](int y) {
    if (0 <= y and y < this->cols_) {
        return this->vector_[y];
    } else {
        throw std::out_of_range("Index out of range");
    }
}

int Row::size() const {
    return this->cols_;
}

void Row::resize(int new_size) {
    auto *new_vector = new double[new_size];

    for (int i = 0; i < new_size; i += 1) {
        new_vector[i] = 0;
    }

    for (int i = 0; i < std::min(this->cols_, new_size); i += 1) {
        new_vector[i] = this->vector_[i];
    }

    delete[] this->vector_;

    this->cols_ = new_size;
    this->vector_ = new_vector;
}

bool Row::operator!=(const Row &v) {
    if (this->cols_ != v.cols_) {
        return true;
    }

    for (int i = 0; i < this->cols_; i += 1) {
        if (this->vector_[i] != v.vector_[i]) {
            return true;
        }
    }

    return false;
}

bool Row::operator==(const Row &v) {
    return !(*this != v);
}




