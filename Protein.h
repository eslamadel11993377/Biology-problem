#ifndef PROTEIN_H
#define PROTEIN_H

#include <Sequence.h>
#include<iostream>
#include"DNA.h"
#include"CodonsTable.h"
using namespace std;

enum Protein_Type {Hormon=1, Enzyme, TF, Cellular_Function};

class Protein : public Sequence
{
public:
    class errorsize2 {};
    class errordefinition2 {};
    Protein();
    Protein(char * p,Protein_Type atype);
    Protein(Protein& );
    ~Protein();
    DNA* GetDNAStrandsEncodingMe( const DNA  bigDNA,CodonsTable & table,int &);
    void Print();
    void  add(char*);
    void load_all();
    void load(int );
    Protein operator +(Protein& );
    Protein &operator =(const Protein&);
    bool operator ==(Protein otherProtein);
    bool operator !=(Protein otherProtein);
    friend istream&operator >> (istream &in,Protein & obj);
    friend ostream&operator << (ostream &out,Protein & obj);

private:
    Protein_Type type;

};

#endif // PROTEIN_H
