#include "SeqList.hpp"

template <class Type>
SeqList<Type>::SeqList(int sz)
{
    if(sz > 0)
    {
        MaxSize = sz;
        last = -1;
        data = new Type[MaxSize]；
        if(data == NULL)
        {
            MaxSize = 0;
            last = -1;
            return;
        }
    }
}

template <class Type>
int SeqList<Type>::Find(Type &x) const
{
    int i = 0;
    while( i<= last && data[i] != x)
        i++;
    if(i>last) return -1;
    else return i;
}

template <class Type> 
int SeqList<Type>::IsIn(Type &x)
{
    int i=0, found=0;
    while(i<=last && !found)
        if(data[i]!=x) i++;
        else found = 1;
    return found;
}
template <class Type>
int SeqList<Type>::Insert(Type &x, int i)
{
    if(i<0 || i>last+1 || last==MaxSize-1)
        return 0;
    else
    {
        last++;
        for(int j=last; j>i; j--)
            data[j] = data[j-1];
        data[i] = x;
        return 1;
    }
}

template <class Type>
int SeqList<Type>::Remove(Type &x)
{
    int i = Find(x);
    if(i>=0)
    {
        last--;
        for(int j=i; j<=last;j++)
            data[j]=data[j+1];
        return 1;
    }
    else
    {
        return 0;
    }
}

template <class Type>
int SeqList<Type>::Next(Type &x)
{
    int i = Find(x);
    if(i>=0 && i<last) return i+1;
    else return -1;
}

template <class Type>
int SeqList<Type>::Prior(Type &x)
{
    int i=Find(x);
    if(i>0 && i<=last) return i-1;
    else return -1;
}