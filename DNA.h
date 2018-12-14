#ifndef DNA_H
#define DNA_H

#include <Sequence.h>
#include<iostream>
using namespace std;

enum DNA_Type {promoter=1, motif, tail, noncoding};
class RNA;
class DNA : public Sequence
{
    private:
    DNA_Type type;
    DNA * complementary_strand;
    int startIndex;
    int endIndex;
    public:
        class errorsize{};
        class errordefinition{};
        DNA();
        DNA(char* s , DNA_Type atype);
        DNA(DNA& rhs);
        ~DNA();
        void Print();
        void  add(char*);
        void load_all();
        void load(int );
        DNA &operator =(const DNA&);
        bool operator ==(DNA otherDna);
        bool operator !=(DNA otherDna);
        friend istream&operator >> (istream &in,DNA & obj);
        friend ostream&operator << (ostream &out,DNA & obj);
        RNA ConvertToRNA();
        DNA operator +(DNA &otherDna);
        void BuildComplementaryStrand(int start,int endd);







};

#endif // DNA_H
