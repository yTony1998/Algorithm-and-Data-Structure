#ifndef POLYNOMIAL
#define POLYNOMIAL

#include <iostream>
class Polynomial;
class term
{
    friend Polynomial;
private:
    float coef;
    int exp;
};

class Polynomial
{
private:
    static term termArray[MaxTerms];
    static int free;
    int start, finish;

public:


    Polynomial();
    ~Polynomial();
    int operator !();
    Polynomial operator+(Polynomial B);
    float Coef(int e);
    int LeadExp();
    Polynomial Add(Polynomial poly);
    Polynomial Mult(Polynomial poly);
    float Eval (float x);

    void NewTerm(float c, int e);
};

void Polynomial::NewTerm(float c, int e)
{
    if(free >= maxTerms)
    {
        std::cout<<"Too many terms in polynomial"<<std::endl;
        return ; 
    }

    termArray[free].coef = c;
    termArray[free].exp = e;
    free ++;
}

Polynomial Polynomial::operator+(Polynomial B)
{
    Polynomial C;
    int a = start; int b = B.start; C.start = free;
    float c;
    while (a <= finish && b <= B.finish)
    {
        switch (compare(termArray[a].exp, termArray[b].exp))
        {
        case '=':
            c = termArray[a].coef + termArray[b].coef;
            if(c)
                NewTerm(c, termArray[a].exp);
            break;
        case '>':
            NewTerm(termArray[b].coef, termArray[b].exp);
            b++;
            break;
        case '<':
            NewTerm(termArray[a].coef, termArray[a].exp);
            a++;
        }
            
    }

    for(; a<=finish;a++)
        NewTerm(termArray[a].coef, termArray[a].exp);
    for(; b<= B.finish; b++)
        NewTerm(termArray[b].coef, termArray[b].exp);
    C.finish = free -1;
    return C;
    
}


#endif POLYNOMIAL