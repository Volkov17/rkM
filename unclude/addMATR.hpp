#include <iostream>
#include <fstream>
#include <cstdlib>
#include <initializer_list>
using namespace std;

template <typename type, size_t i, size_t j>
class Matrix {
public:
    Matrix();
    Matrix(initializer_list<type> il);
    Matrix(const Matrix&);
    bool empty();
    size_t columns();
    size_t rows();
    auto operator-(const Matrix&)->Matrix;
    auto operator+(const Matrix&)->Matrix;
    type* operator[](size_t index);
    bool operator==(const Matrix&);
    auto operator=(const Matrix& q)->Matrix&;
    template <typename T2, size_t i2, size_t j2>
    friend std::ostream& operator<<(std::ostream&, const Matrix<T2, i2, j2>&);
    template <typename T3, size_t i3, size_t j3>
    friend std::istream& operator>>(std::istream&, Matrix<T3, i3, j3>&);
    void swap(Matrix&);
    ~Matrix();
private:
    type** ptr;
};
