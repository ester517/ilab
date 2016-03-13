#include <iostream>
#include <cmath>
#include <cassert>
template <class T> class Cvector
{
private:
    int size;
    T* val;
public:
    Cvector(int s);
    ~Cvector();

    T& operator[] (int num);

    Cvector operator = (Cvector v);

    Cvector operator + (Cvector &v);
    Cvector operator - (Cvector &v);

    Cvector operator * (int k);
    Cvector operator / (int k);

    T operator & (Cvector & v);

    double operator ^ (Cvector & v);
};
