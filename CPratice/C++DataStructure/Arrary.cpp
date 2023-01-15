#include<Arrary.hpp>

template <class Type>
void Array<Type>::getArray()
{
    elements = new Type[ArraySize];
    if(elements == NULL)
    {
        ArraySize = 0;
        std::cerr<<"Memory Allocation Error"<<std::endl;
        return;
    }
}

template <class Type> 
Array<Type>::Array(int sz)
{
    if (sz<=0)
    {
        ArraySize = 0;
        std::cerr<<"非法数组大小"<<std::endl;
        return;
    }
    ArraySize = sz;
    getArray();
}

template <class Type>
Array<Type>::Array(const Array<Type> &x)
{
    int n = ArraySize = x.ArraySize;
    elements = new Type[n];
    if(elements == 0)
    {
        ArraySize = 0
        std::cerr<<"存储分配错误"<<std::endl;
        return;
    }
    Type *srcptr = x.elements;
    Type *desptr = elements;
    while (n--)
    {
        *desptr++ = *srcptr++;
    }   
}

template <class Type>
Type & Array<Type>::operator[](int i)
{
    if(i<0 || i>ArraySize-1)
    {
        std::cerr<<"数组下标超界"<<std::endl;
        return NULL;
    }
    return elements[i];
}

template <class Type>
void Array<Type>::ReSize(int sz)
{
    if(sz >=0 && sz != ArraySize)
    {
        Type *newarray = new Type[sz];
        if(newarray == 0)
        {
            std::cerr<<"存储分配错误"<<std::endl;
            return;
        }

        int n = (sz <= ArraySize)?sz:ArraySize;
        Type *srcptr = elements;
        Type *destpr = newarray;
        while(n--) *destpr++=*srcptr++;
        delete []elements;
        elements = newarray;
        ArraySize = sz;
    }
}