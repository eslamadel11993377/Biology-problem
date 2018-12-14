#ifndef RNA_H
#define RNA_H
#include <Sequence.h>
#include<DNA.h>
#include<iostream>
#include"Protein.h"
using namespace std;

enum RNA_Type {mRNA=1, pre_mRNA, mRNA_exon, mRNA_intron};
class DNA;
class RNA : public Sequence
{
public:
    class errorsize1 {};
    class errordefinition1 {};
    RNA();
    RNA(char * s, RNA_Type atype);
    RNA(RNA& );
    ~RNA();
    void Print();
    void  add(char*);
    void load_all();
    void load(int );
    bool operator ==(RNA otherRna);
    bool operator !=(RNA otherRna);
    RNA operator +(RNA &);
    RNA &operator =(const RNA&);
    friend istream&operator >> (istream &in,RNA & obj);
    friend ostream&operator << (ostream &out,RNA & obj);
    DNA& ConvertToDNA();
    Protein& ConvertToProtein( CodonsTable & table);


protected:
private:
    RNA_Type type;

};

#endif // RNA_H
