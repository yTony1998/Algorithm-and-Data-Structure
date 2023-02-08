#ifndef STACKARRAY
#define STACKARRAY

#include <assert.h>

template <class Type> class StackArray
{
private:
    int top;
    Type *elements;
    int maxSize;

public:
    StackArray(int = 10);
    ~StackArray(){delete [] elements;}
    void Push( const Type & item);
    Type Pop();
    Type GetTop();
    void MakeEmpty(){top =-1;}
    int IsEmpty() const {return top == -1;}
    int IsFull() const {return top == maxSize -1;}

};



#endif STACKARRAY