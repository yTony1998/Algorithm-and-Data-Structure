
#include <iostream>
#include "StackArray.hpp"
using namespace std;

int main()
{
    StackArray<int> a;
    for(int i=0; i<10; i++)
        a.Push(i);
    for(int i=0; i<10; i++)
    {
        cout<<a.GetTop();
        a.Pop();
    }
}