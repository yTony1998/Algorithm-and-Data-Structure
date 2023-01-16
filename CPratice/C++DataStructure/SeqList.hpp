#ifndef SEQLIST
#define SEQLIST

template <class Type> class SeqList
{
private:
    Type *data;
    int MaxSize;
    int last;
public:
    SeqList(int MaxSize = defaultSize);
    ~SeqList(){delete []data;}
    int Length() const {return last+1;}
    int Find(Type &x) const;
    int IsIn(Type &x);
    int Insert (Type &x, int i);
    int Remove(Type &x);
    int Next(Type &x);
    int Prior(Type &x);
    int IsEmpty(){return last == -1;}
    int IsFull(){return last == MaxSize-1;}
    Type Get(int i)
    {
        return i<0 ||i>last ? NULL:data[i];
    }


};

#endif SEQLIST