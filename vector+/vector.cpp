#include "vector.h"
template <class T> Cvector<T>::Cvector(int s)
{
    size = s;
    val = new T[size];
}

template <class T> Cvector<T>::~Cvector()
{
    delete []val;
}

template <class T> T& Cvector<T>::operator[] (int num)
{
    assert((num >= 0) && (num < size));
    return val[num];
}

template <class T> Cvector<T> Cvector<T>::operator = (Cvector v)
{
    int i;
    for(i = 0; i < size; i++)
        val[i] = v.val[i];
    return *this;
}

template <class T> Cvector<T> Cvector<T>::operator +(Cvector<T> &v)
{
    assert(size == v.size);

    Cvector<T> v2 (size);

    int i;
    for (i = 0; i < size; i++)
    {
        v2.val[i] =v.val[i] + val[i];
    }
    return v2;
}

template <class T> Cvector<T> Cvector<T>::operator - (Cvector<T> & v)
{
    assert(size == v.size);

    Cvector<T> v2(size);
    int i;
    for (i = 0; i < size; i++)
    {
        v2.val[i] = val[i] - v.val[i];
    }
    return v2;
}
template <class T> Cvector<T> Cvector<T>::operator * (int k)
{
    int i;
    Cvector<T> v2(size);
    for(i = 0; i < size; i++)
    {
        v2.val[i] = val[i] * k;
    }
    return v2;
}


template <class T> Cvector<T> Cvector<T>::operator / (int k)
{
    int i;
    Cvector<T> v2(size);
    for(i = 0; i < size; i++)
    {
        v2.val[i] = val[i] / k;
    }
    return v2;
}
template <class T> T Cvector<T>::operator & (Cvector<T> & v)
{
    assert(size == v.size);
    int i;
    T  pr = 0;
    for(i = 0; i < size; i++)
    {
        pr = pr + val[i] * v.val[i];
    }
    return pr;
}

template <class T> double Cvector<T>::operator ^ (Cvector<T> & v)
{
    assert(size == v.size);
    double cos = 0;
    int pr = 0;
    double a1 = 0, a2 = 0;
    int i;
    for(i = 0; i < size; i++)
    {
        a1 = a1 + val[i] * val[i];
        a2 = a2 + v.val[i] * v.val[i];
        pr = pr + val[i] * v.val[i];
    }
    a1 = sqrt(a1);
    a2 = sqrt(a2);
    cos =  pr / (a1 * a2);
    return cos;
}
