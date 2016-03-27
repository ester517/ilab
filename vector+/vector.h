#include <iostream>
#include <cmath>
#include <cassert>
#include <cstring>
#include <cstdlib>
class mException
{
protected:
	std::string mwhat;
public:
    mException (const std::string what):
        mwhat(what)
    {}
    void show_error()
    {
        std::string m = mwhat;
        std::cout << m;
    }
};
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
