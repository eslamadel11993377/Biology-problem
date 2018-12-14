#include "DNA.h"
#include "Sequence.h"
#include<bits/stdc++.h>
#include"RNA.h"
string D[]= {"promoter","motif","tail","noncoding"};
;
class errorsize {};///Exception class
class errordefinition {};///Exception class
DNA::DNA()///empty constructor
{
    seq=new char[50];
    type=noncoding;
}
DNA::DNA(char* s, DNA_Type atype) ///parametrize constructor
{
    if(strlen(s)%3!=0)///Check that the size of the sequence is equal  3 or its multiples
    {
        DNA::errorsize ob; ///object from exception class errorsize
        throw ob; ///throw object to the catch in the main if the size is not equal  3 or its multiples
    }

    seq=new char[strlen(s)];
    strcpy(seq,s);///set value to the sequence
    int c=0;
    for(int i=0; i<strlen(s); i++)
    {
        if(s[i]!='A'&&s[i]!='C'&&s[i]!='G'&&s[i]!='T')/// Check for DNA sequence 's 4 characters (A,C,G,T)
            c++;
    }
    if(c!=0)
    {
        DNA:: errordefinition ob;///object from exception class errordefinition
        throw ob;///throw the object to the catch in the main if DNA sequence is not (A,C,G,T)
    }

    type=atype;///set value to type

}
DNA::DNA(DNA& rhs)///copy constructor
{
    delete[]seq;
    seq=new char[strlen(rhs.seq)];
    strcpy(seq,rhs.seq);

    type=rhs.type;

}
DNA::~DNA()///destructor
{
    delete []seq;/// delete the sequence
}
void DNA::Print()///function to print the object of DNA
{
    cout<<"DNA sequence= "<<seq<<endl;///Print DNA sequence
    cout<<"DNA type= "<<D[type-1]<<endl;///Print the type of DNA
}
bool DNA:: operator ==(DNA otherDna)/// operator==
{
    if(strcmp(seq,otherDna.seq)==0&&strlen(seq)==strlen(otherDna.seq))///check if the sequence of the first DNA is equal the sequence of the second object
        return 1;
    else
        return 0;
}
bool DNA:: operator !=(DNA otherDna)///operator !=
{
    if(strcmp(seq,otherDna.seq)!=0)///check if the sequence of the first DNA is not equal the sequence of the second object

        return 1;
    else
        return 0;

}
istream&operator >> (istream &in,DNA & obj)
{
    int c=0;
    cout<<"Enter DNA sequence= ";
    in>>obj.seq;
    if(strlen(obj.seq)%3!=0)///Check that the size of the sequence is equal  3 or its multiples
    {
        DNA::errorsize ob;///object from exception class errorsize
        throw ob;///throw object to the catch in the main if the size is not equal  3 or its multiples

    }
    int w=0;
    for(int i=0; i<strlen(obj.seq); i++)
    {
        if(obj.seq[i]!='A'&&obj.seq[i]!='C'&&obj.seq[i]!='G'&&obj.seq[i]!='T')/// Check for DNA sequence 's 4 characters (A,C,G,T)
            w++;
    }
    if(w!=0)
    {
        DNA::errordefinition ob;///object from exception class errordefinition
        throw ob;///throw the object to the catch in the main if DNA sequence is not (A,C,G,T)
    }
    cout<<"Choose the type of DNA:"<<endl;
    cout<<"1-promoter\n2-motif\n3-tail\n4-noncoding"<<endl;
    cin>>c;
    if(c==1)
    {
        obj.type=promoter;///set value to the type
    }
    if(c==2)
    {
        obj.type=motif;///set value to the type
    }
    if(c==3)
    {
        obj.type=tail;///set value to the type
    }
    if(c==4)
    {
        obj.type=noncoding;///set value to the type
    }
    return in;
}
ostream&operator << (ostream &out,DNA & obj)
{
    out<<"DNA sequence= "<<obj.seq<<endl;///print the the sequence of the DNA
    out<<"DNA type= "<<D[obj.type-1]<<endl;///print the the type of the DNA
    return out;
}
RNA DNA ::ConvertToRNA()///convert DNA to RNA
{

    RNA r;
    r.seq=new char(strlen(seq));
    strcpy(r.seq,seq);///Make the sequence of RNA equal to the sequence of DNA

    for (int i=0; i<strlen(seq); i++)
    {
        if (r.seq[i]=='T')///Replace T by U
            r.seq[i]='U';
    }
    return r;/// return the RNA
}
DNA DNA:: operator +(DNA &otherDna)///Operator +
{
    DNA dna3;
    if(type==otherDna.type)/// check if the the type of the two DNA is the same
        dna3.type=type;
    dna3.seq=new char[strlen(seq)+strlen(otherDna.seq)] ;
    strcpy(dna3.seq,seq);///add the sequence of the first sequence to  dna3
    strcat(dna3.seq,otherDna.seq);///add the sequence of the second sequence to dna3
    return dna3;///return dna3
}
DNA& DNA:: operator =(const DNA &rhs)
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
void DNA::BuildComplementaryStrand(int start,int endd)///Get the complementary strand of the DNA
{
    if (start!=endd)
    {
        startIndex=start;
        endIndex=endd;
    }
    else
    {
        startIndex=0;
        endIndex=strlen(seq);
    }
    char *temp;
    temp=new char[startIndex+endIndex];
    temp[startIndex+endIndex]='\0';
    for (int i=startIndex; i<endIndex; i++)
    {
        if (seq[strlen(seq)-i-1]=='T')///Replace each T with A
            temp[i]='A';
        else if (seq[strlen(seq)-i-1]=='A')///Replace each A with T
            temp[i]='T';
        else if (seq[strlen(seq)-i-1]=='C')///Replace each C with G
            temp[i]='G';
        else if (seq[strlen(seq)-i-1]=='G')///Replace each G with C
            temp[i]='C';
        else
            temp[i]=seq[strlen(seq)-i-1];

    }

    complementary_strand=new DNA;
    strcpy(complementary_strand->seq,temp); ///Make complementary strand of DNA equal to the temp
    complementary_strand->type=type;///Make complementary type of DNA equal to the type of the base DNA
    cout<<*complementary_strand;///Print the complementary strand of DNA
    delete[]temp;
}
void DNA:: add(char*x)
{
    ofstream file ;
    file.open("user_data.txt",ios::app);///open the file
    file<<"\n"<<seq<<" "<<x;///add DNA sequence to file
    file.close();/// close the file
}
void DNA:: load(int k)
{
    ifstream filee ;
    filee.open("user_data.txt");///open the file
    string x,y;
    int count1=1;///to know the place of the selecting sequence
    while(filee>>x>>y)
    {
        if(y=="DNA"&&count1==k)
        {
            strcpy(seq,x.c_str());///Load the selecting sequence from file
            break;
        }
        count1++;
    }
    filee.close();
}
void DNA:: load_all()
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
