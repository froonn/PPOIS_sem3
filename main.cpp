//
// Created by xinardelis on 26/09/24.
//

#include "real_matrix.h"
#include <iostream>

int main() {
    real_matrix m(3, 3);
    m[0][0] = 1;
    m.print();
    return 0;
}