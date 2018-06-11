#include "addMATR.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <initializer_list>


template <typename type, size_t i, size_t j>
Matrix<type, i, j>::Matrix() : ptr(nullptr) {
}

template <typename type, size_t i, size_t j>
Matrix<type, i, j>::Matrix(std::initializer_list<type> list) {
    ptr = new type*[i];
    auto p = list.begin();
    for (int n = 0; n < i; n++)
        ptr[i] = new type[j];
    for (int n = 0; n < i; n++) {
        for (int m = 0; m < j; m++, p++)
            ptr[n][m] = *p;
    }
}
template <typename type, size_t i, size_t j>
Matrix<type, i, j>::Matrix(const Matrix& mat) {
    ptr = new type *[i];
    for (int n = 0; n < i; n++){
        ptr[n] = new type[j];
        for (int m = 0; m < j; m++)
            ptr[n][m] = mat.ptr[n][m];
    }
}

template <typename type, size_t i, size_t j>
bool Matrix<type, i, j>::empty()  {
    if (ptr == nullptr)
        return true;
    else
        return false;
}
template <typename type, size_t i, size_t j>
size_t Matrix<type, i, j>::columns()  {
    return j;
}

template <typename type, size_t i, size_t j>
size_t Matrix<type, i, j>::rows() {
    return i;
}

template <typename type, size_t i, size_t j>
auto Matrix<type, i, j>::operator-(const Matrix& mat)->Matrix{
    for (int n = 0; n < i; n++){
        for (int m = 0; m < j; m++)
            ptr[n][m] = ptr[n][m] - mat.ptr[n][m];
    }
    return *this;
}

template <typename type, size_t i, size_t j>
auto Matrix<type, i, j>::operator+(const Matrix& mat) -> Matrix{
    for (int n = 0; n < i; n++){
        for (int m = 0; m < j; m++)
            ptr[n][m] = ptr[n][m] + mat.ptr[n][m];
    }
    return *this;
}
template <typename type, size_t i, size_t j>
type* Matrix<type, i, j>::operator[](size_t index) {
    return ptr[index];
}


template <typename type, size_t i, size_t j>
bool Matrix<type, i, j>::operator==(const Matrix& mat) {
    for (int n = 0; n < i; n++){
        for (int m = 0; m < j; m++){
            if (ptr[n][m] != mat.ptr[n][m])
                return false;
        }
    }
    return true;
}
template <typename type, size_t i, size_t j>
auto Matrix<type, i, j>::operator=(const Matrix& mat) ->Matrix& {
    if (ptr != nullptr) {
        for (int n = 0; n < i; n++)
            delete[] ptr[n];
        delete [] ptr;
        return *this;
    }
    ptr = new type*[i];
    for (int n = 0; n < i; n++)
        ptr[n] = new type[j];
    for (int n = 0; n < i; n++){
        for (int m = 0; m < j; m++)
            ptr[n][m] = mat.ptr[n][m];
    }
    return *this;
}


template <typename type, size_t i, size_t j>
std::ostream& operator<<(std::ostream& os, const Matrix<type, i, j>& mat) {
    os << i << " " << j << std::endl;
    for (int n = 0; n < i; n++){
        for (int m = 0; m < j; m++)
            os << mat.ptr[n][m]<<"  ";
        os <<std:: endl;
    }
    return os;
}

template <typename type, size_t i, size_t j>
std::istream& operator>>(std::istream& is, Matrix<type, i, j>& mat) {
    if(is) {
        mat.ptr = new type*[i];
        for(int n = 0; n < i; n++)
            mat.ptr[n] = new type[j];
        for (int n = 0; n < i; n++) {
            for (int m = 0; m < j; m++)
                is >> mat.ptr[n][m];
        }
    }
    return is;
}

template <typename type, size_t i, size_t j>
void Matrix<type, i, j>::swap(Matrix& m_matrix)  {
    type **curr;
    curr = new type *[i];
    for (int n = 0; n < i; n++) {
        curr[n] = new type[j];
        for ( int m = 0; m < j; m++)
            curr[n][m] = m_matrix.ptr[n][m];
    }
    for (int n = 0; n < i; n++) {
        for(int m = 0; m < j; m++)
            m_matrix.ptr[n][m] = this->ptr[n][m];
    }
    for (int n = 0; n < i; n++) {
        for(int m = 0; m < j; m++)
            this->ptr[n][m] = curr[n][m];
    }
    for (int n = 0; n < i; n++)
        delete[] curr[n];
    delete [] curr;
}

template <typename type, size_t i, size_t j>
Matrix<type, i, j>::~Matrix() {
    for (int n = 0; n < i; n++)
        delete[] ptr[n];
    delete [] ptr;
}
