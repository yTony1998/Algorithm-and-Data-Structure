#ifndef ARRARY
#define ARRARY

#include <iostream>
#include <stdlib.h>

template <class Type>
class Array
{
private:
    Type *elements;
    int ArraySize;
    void getArray()
public:
    Array(int Size = DefaultSize);
    Array(const Array<Type>& x);
    ~Array(){delete []elements;}
    Array<type> & operator = (const Array<Type>& A);
    Type& operator[](int i);
    Type* operator *() const {return elements;}
    int Length() const {return ArraySize;}
    void ReSize(int sz);
};

#endif ARRARY