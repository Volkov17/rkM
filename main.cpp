#include "addMATR.hpp"


int main() {

    Matrix <int, 2, 1> m1{3,5};
    Matrix <int, 3, 2> m2{1, 2, 3, 4, 5, 6};
    Matrix <int, 3, 2> m3{m2};

    cout << m1 << endl;
    cout << m2 << endl;
    cout << m3 << endl;

    Matrix <int, 3, 2> m4;
    m4 = m3;
    cout << m4 << endl;

    m4[0][0] = 8;
    cout << m4 << endl;

    cout << boolalpha  << (m2 == m3) << (m3 == m4) << endl;

    cout << m1.rows() << "" << m1.columns() << endl;
    cout << endl;

    Matrix <int, 3, 2> m5{0, 2, 4, 6, 8, 10};
    cout << m5 << endl;
    cout << endl;

    cout << m3 + m5 << endl;
    cout << m3 - m5 << endl;

    Matrix <int, 3, 2> m6{};
    cout << m6.empty()<<endl;

    ofstream out{"matrix.txt"};
    out << m3;

    ifstream in{"matrix.txt"};
    in >> m6;

    m6[0][0] = 145;
    m3.swap(m6);

    cout << m3 << endl;

}
