#include "RNA.h"
#include "DNA.h"
#include "Sequence.h"
#include<bits/stdc++.h>
#include<istream>
#include"Protein.h"
#include"Codon.h"
#include"CodonsTable.h"
using namespace std;
string R[]= {"mRNA","pre_mRNA", "mRNA_exon", "mRNA_intron"};
class errorsize1 {}; ///Exception class
class errordefinition1 {}; ///Exception class
RNA::RNA()///empty constructor
{
    type=mRNA;
    seq=new char[50];
    memset (seq,'\0',50);
}
RNA::RNA(char * s, RNA_Type atype)///parametrize constructor
{
    seq=new char[strlen(s)];
    memset (seq,'\0',strlen(s));
    if(strlen(s)%3!=0)///Check that the size of the sequence is equal  3 or its multiples
    {
        RNA::errorsize1 b;///object from exception class errorsize1
        throw b;///throw object to the catch in the main if the size is not equal  3 or its multiples
    }
    strcpy(seq,s);///set value to the sequence
    int c=0;
    for(int i=0; i<strlen(s); i++)
    {
        if(s[i]!='A'&&s[i]!='C'&&s[i]!='G'&&s[i]!='U')/// Check for DNA sequence 's 4 characters (A,C,G,U)
            c++;
    }
    if(c!=0)
    {
        RNA::errordefinition1 t;///object from exception class errordefinition1
        throw t;///throw the object to the catch in the main if DNA sequence is not (A,C,G,T)
    }
    type=atype;///set value to type
}

RNA::RNA(RNA& rhs)///copy constructor
{

    seq=new char[strlen(rhs.seq)];
    memset (seq,'\0',strlen(seq));
    strcpy(seq,rhs.seq);
    type=rhs.type;
}
RNA::~RNA()///destructor
{
    delete []seq;/// delete the sequence
}
void RNA:: Print()///function to print the object of RNA
{
    cout<<"RNA sequence= "<<seq<<endl;///Print RNA sequence
    cout<<"RNA type= "<<R[type-1]<<endl;///Print the type of RNA
}
bool RNA:: operator ==(RNA otherRna)/// operator==
{
    if(strcmp(seq,otherRna.seq)==0&&strlen(seq)==strlen(otherRna.seq))///check if the sequence of the first RNA is equal the sequence of the second object

        return 1;
    else
        return 0;

}
bool RNA::operator !=(RNA otherRna)///operator !=
{
    if(strcmp(seq,otherRna.seq)!=0)///check if the sequence of the first RNA is not equal the sequence of the second object
        return 1;
    else
        return 0;

}
istream&operator >> (istream &in,RNA & obj)
{
    int c=0;
    cout<<"Enter RNA sequence= ";
    in>>obj.seq;
    if(strlen(obj.seq)%3!=0)///Check that the size of the sequence is equal  3 or its multiples
    {
        RNA::errorsize1 ob;///object from exception class errorsize1
        throw ob;///throw object to the catch in the main if the size is not equal  3 or its multiples
    }
    int w=0;
    for(int i=0; i<strlen(obj.seq); i++)
    {
        if(obj.seq[i]!='A'&&obj.seq[i]!='C'&&obj.seq[i]!='G'&&obj.seq[i]!='U')/// Check for RNA sequence 's 4 characters (A,C,G,U)

            w++;
    }
    if(w!=0)
    {
        RNA::errordefinition1 ob;///object from exception class errordefinition1
        throw ob;///throw the object to the catch in the main if RNA sequence is not (A,C,G,U)
    }

    cout<<"Choose the type of RNA:"<<endl;
    cout<<"1-mRNA,\n2-pre_mRNA\n3-mRNA_exon\n4-mRNA_intron"<<endl;
    cin>>c;
    if(c==1)
    {
        obj.type=mRNA;   ///set value to the type
    }
    if(c==2)
    {
        obj.type=pre_mRNA;   ///set value to the type
    }
    if(c==3)
    {
        obj.type=mRNA_exon;   ///set value to the type
    }
    if(c==4)
    {
        obj.type=mRNA_intron;   ///set value to the type
    }
    return in;

}
ostream&operator << (ostream &out,RNA & obj)
{
    out<<"RNA sequence= "<<obj.seq<<endl;///print the the sequence of the RNA
    out<<"RNA type= "<<R[obj.type-1]<<endl;///print the the type of the RNA
    return out;
}
DNA& RNA:: ConvertToDNA()///convert RNA to DNA
{
    DNA d;
    d.seq=new char[strlen(seq)];
    memset (d.seq,'\0',strlen(seq));
    strcpy(d.seq,seq);///Make the sequence of DNA equal to the sequence of RNA
    for (int i=0; i<strlen(seq); i++)
    {
        if (seq[i]=='U')///Replace U by T
            d.seq[i]='T';
    }

    return d;/// return the DNA

}
RNA RNA:: operator +(RNA& otherRNA)///Operator +
{
    RNA r;
    if (type==otherRNA.type)/// check if the the type of the two DNA is the same
        r.type=type;
    delete[]r.seq;
    r.seq=new char[strlen(seq)+strlen(otherRNA.seq)];
    memset (r.seq,'\0',strlen(seq)+strlen(otherRNA.seq));
    strcpy(r.seq,seq);///add the sequence of the first sequence to  r
    strcat(r.seq,otherRNA.seq);///add the sequence of the first sequence to  r
    return r;///return r
}

RNA& RNA:: operator =(const RNA &rhs)
{

    // self-assignment guard
    if (this == &rhs)
        return *this;

    // do the copy
    seq = rhs.seq;
    type=rhs.type;
    // return the existing object so we can chain this operator
    return *this;
}


Protein& RNA:: ConvertToProtein( CodonsTable & table)///convert RNA to protein
{
    Protein p;
    string temp="";///to take  each 3 characters of RNA sequence
    string temp2="";///to store the protein sequence
    int temp2_index=0,temp_index=0;///two counters one for temp and the other for temp2
    for (int j=0; j<strlen(seq); j++)
    {
        temp+=seq[j];///to take  each 3 characters of RNA sequence

        if((j+1)%3==0&&j!=0)///if temp size equal 3
        {
            if (temp=="UAA"||temp=="UAG"||temp=="UGA")///stop RNA sequence
                break;
            for (int i=0; i<64; i++)
            {

                if (temp==table.codons[i].value)/// check temp is equal to value of codons in the array of codons
                {
                    temp2+=table.codons[i].AminoAcid;/// set know the aminoacid of each codons
                    temp="";
                }
            }

        }
    }
    p.seq=new char[temp2.length()];///
    memset (p.seq,'\0',temp2.length());;
    strcpy(p.seq,temp2.c_str());///make the sequence of the p equal to the temp2
    return p; ///return the protein object
}
void RNA:: add(char*x)
{
    ofstream file ;
    file.open("user_data.txt",ios::app);///open the file
    file<<"\n"<<seq<<" "<<x;///add RNA sequence  to file
    file.close();/// close the file
}

void RNA:: load(int k)
{
    ifstream filee ;
    filee.open("user_data.txt");
    string x,y;
    int count1=1;///to know the place of the selecting sequence
    while(filee>>x>>y)
    {

        if(y=="RNA"&&count1==k)
        {
            strcpy(seq,x.c_str());///Load the selecting sequence from file
            break;
        }
        count1++;
    }
    filee.close();
}
void RNA:: load_all()
{
    ifstream filee ;
    filee.open("user_data.txt");///open the file
    string x,y;
    while(filee>>x>>y)
    {
        cout<<x<<" "<<y<<endl;/// Load all sequences from file
    }
    filee.close();///close file
}
