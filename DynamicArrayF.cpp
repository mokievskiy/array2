#include "DynamicArray.h"
#include <iostream>


int comp(const void *a, const void *b)
{
    double x,y ;
    x = *(double*)a;
    y = *(double*)b;
    if (x < y) return -1;
    if (x > y) return  1;
    return 0;
}

Array::Array() {
    _arr = 0;
    _len = 0;
}
Array::~Array() {
    free(_arr);
}

size_t Array::length() const {
    return _len/sizeof(double);
}

double &Array::operator[] (size_t i) {
    if (i >= _len)
        resize(i + 1);
    return _arr[i];
}

const double & Array::operator[] (size_t i) const {
    if (i >= _len)
        throw 1; // Out of range
    return _arr[i];
}

void Array::resize (size_t l) {
    if (l > _len) {
        double *a = (double*)malloc(l * sizeof(double));
        if (!a)
            throw 2; // Memory allocation error
        memset(a, 0, l * sizeof(double));
        memcpy(a, _arr, _len * sizeof(double));
        free(_arr);
        _arr = a;
        _len = l;
    }
    else
        _len = l;
}

Array::Array (const Array &a) {
    _arr = 0;
    _len = 0;
    resize(a._len);
    memcpy(_arr, a._arr, a._len * sizeof(double));
}

Array::Array(const double *a, const size_t l) : _arr(0), _len(0) {
    resize(l);
    memcpy(_arr, a, l * sizeof(double));
}

Array & Array::operator= (const Array &a) {
    resize(a._len);
    memcpy(_arr, a._arr, a._len * sizeof(double));
    return *this;
}

Array & Array::operator+= (const double a) {
    
    resize(_len+1);
    _arr[_len-1] = a;
    return *this;
}

Array & Array::operator-= (const int i) {
    if (i >= (int)_len)
        throw 3; // Index out of range
    for (size_t j = i + 1; j < _len; j++) {
        _arr[j - 1] = _arr[j];
    }
    _len--;
    return *this;
}

Array Array::operator+ (const Array &b) {
    Array A(_arr,_len);
    A.resize(_len + b._len);
    memcpy(A._arr + _len, b._arr, b._len*sizeof(double));
    return A;
}

void Array::sorti () {
     std::qsort(_arr, _len/sizeof(double), sizeof(double), comp);
}

std:: ostream& operator<<(std:: ostream &out, const Array& a) {
    for (size_t i = 0; i < a.length(); i++) {
        out << a[i] << " ";
    }
    out << "\n";
    return out;
}
