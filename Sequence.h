#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <bits/stdc++.h>
class Sequence
{
protected:

public:
    char* seq;
    Sequence();
    /// Sequence(int length);
    Sequence(const Sequence& rhs);
    Sequence(char* x);
    virtual ~Sequence();
    virtual void Print()= 0;
    virtual void  add(char*)=0;
    virtual void load_all()=0;
    virtual void load(int )=0;

    friend char* Align(Sequence & , Sequence & );
};

#endif // SEQUENCE_H
