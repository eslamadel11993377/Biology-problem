#include "Protein.h"
#include "DNA.h"
#include "Sequence.h"
#include<bits/stdc++.h>
#include"RNA.h"
#include"CodonsTable.h"
#include"Codon.h"
string P[]= {"Hormon", "Enzyme", "TF", "Cellular_Function"};

class errorsize2 {};
class errordefinition2 {};
Protein::Protein()
{
    seq=new char[50];
    memset (seq,'\0',50);
    type=Cellular_Function;
}
Protein::Protein(char * s,Protein_Type atype)
{

    seq=new char[strlen(s)];
    memset (seq,'\0',strlen(s));
    strcpy(seq,s);
    int c=0;
    for(int i=0; i<strlen(s); i++)
    {
        if(s[i]!='K'&&s[i]!='N'&&s[i]!='T'&&s[i]!='R'&&s[i]!='S'&&s[i]!='F'&&s[i]!='M'&&s[i]!='Q'&&s[i]!='H'&&s[i]!='P'&&s[i]!='L'&&s[i]!='E'&&s[i]!='D'&&s[i]!='A'&&s[i]!='G'&&s[i]!='V'&&s[i]!='Y'&&s[i]!='C'&&s[i]!='W')
            c++;
    }
    if(c!=0)
    {
        Protein:: errordefinition2 ob;
        throw ob;
    }
    type=atype;
}
Protein::Protein(Protein& rhs)
{
    seq=new char[strlen(rhs.seq)];
    memset (seq,'\0',strlen(rhs.seq));
    strcpy(seq,rhs.seq);
    type=rhs.type;
}
Protein::~Protein()
{
    delete []seq;
}
DNA* Protein:: GetDNAStrandsEncodingMe( const DNA  bigDNA,CodonsTable & table,int &obj_index)///
{


    for(int j=0; j<strlen(bigDNA.seq); j++)//convert big dna to rna
    {
        if(bigDNA.seq[j]=='T')
            bigDNA.seq[j]='U';

    }

    bool check=false;
    char arr[strlen(bigDNA.seq)*2];//to put the word 2 times

    memset (arr,'\0',strlen(bigDNA.seq)*2);
    strcpy(arr,bigDNA.seq);
    strcat(arr,bigDNA.seq);
    cout<<arr<<" arr"<<endl;
    RNA Convert_RNA_to_Protein;//to use the function of rna to protein the =n check it with the protein
    Protein Protein_After_Convert;
    Protein_After_Convert.seq=new char[strlen(seq)];
    memset (Protein_After_Convert.seq,'\0',strlen(seq));
    string temp="";
    int temp_index=0,arr2_index=0;
    string arr2[strlen(bigDNA.seq)*2];//to store all converted from dna to protein
    for (int i=0; i<strlen(bigDNA.seq); i++)
    {
        for (int j=i; j<i+(strlen(seq)*3); j++)//to take number of protein * 3 to take each 3 character in rna
        {
            temp+=arr[j];
            temp_index++;
        }
        temp_index=0;
        delete[]Convert_RNA_to_Protein.seq;
        Convert_RNA_to_Protein.seq=new char[temp.length()];
        memset (Convert_RNA_to_Protein.seq,'\0',temp.length());
        strcpy(Convert_RNA_to_Protein.seq,temp.c_str());//put the rna to object from rna to use to convir to protein
        cout<<"Convert_RNA_to_Protein: "<<Convert_RNA_to_Protein.seq<<endl;
        cout<<endl;
        delete[]Protein_After_Convert.seq;
        Protein_After_Convert.seq=new char[strlen(seq)];
        memset (Protein_After_Convert.seq,'\0',strlen(seq));
        Protein_After_Convert=Convert_RNA_to_Protein.ConvertToProtein(table);//CONVERT rna to protein and put it in protein object
        if (strcmp(seq,Protein_After_Convert.seq)==0)//to chaech if the converted protein equal to the protein
        {
            for(int j=0; j<temp.length(); j++)//CONVERT that rna to dna
            {
                if(temp[j]=='U')
                    temp[j]='T';
            }
            arr2[arr2_index]=temp;//add the converted temp to the arr
            arr2_index++;
            check=true;//if we do not found the converted show a message to user that protein not found
        }
        temp="";
    }
    obj_index=arr2_index;//put the number of elements to the main to know how many operators do we need
    DNA *DNA_After_Convert;//the pointer operator to return
    DNA_After_Convert=new DNA[arr2_index];
    if(!check)//the not found message
        cout<<"their is no DNA from that Protein\nur protein still: "<<seq<<endl;
    else
    {
        for(int i=0; i<arr2_index; i++)//put every dna to the operator
        {
            DNA_After_Convert[i].seq=new char[arr2[i].length()];
            memset (DNA_After_Convert[i].seq,'\0',arr2[i].length());
            strcpy(DNA_After_Convert[i].seq,arr2[i].c_str());
        }
        return DNA_After_Convert;
    }

}
Protein& Protein:: operator =(const Protein &rhs)
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
void Protein::Print()
{
    cout<<"Protein sequence= "<<seq<<endl;
    cout<<"Protein type= "<<P[type-1]<<endl;

}



Protein Protein:: operator +(Protein& otherProtien)
{
    Protein p;
    delete[]p.seq;
    p.seq=new char[strlen(seq)+strlen(otherProtien.seq)];
    memset (p.seq,'\0',strlen(seq)+strlen(otherProtien.seq));
    if (type==otherProtien.type)
        p.type=type;
    strcpy(p.seq,seq);
    strcat(p.seq,otherProtien.seq);
    return p;
}
bool Protein:: operator ==(Protein otherProtein)
{
    if(strcmp(seq,otherProtein.seq)==0&&strlen(seq)==strlen(otherProtein.seq))
        return 1;
    else
        return 0;
}
bool Protein:: operator  !=(Protein otherProtein)
{
    if(strcmp(seq,otherProtein.seq)!=0)
        return 1;
    else
        return 0;

}
istream&operator >> (istream &in,Protein & obj)
{
    int c=0;
    cout<<"Enter Protein sequence= ";
    in>>obj.seq;
    int w=0;
    for(int i=0; i<strlen(obj.seq); i++)
    {
        if(obj.seq[i]!='K'&&obj.seq[i]!='N'&&obj.seq[i]!='T'&&obj.seq[i]!='R'&&obj.seq[i]!='S'&&obj.seq[i]!='F'&&obj.seq[i]!='M'&&obj.seq[i]!='Q'&&obj.seq[i]!='H'&&obj.seq[i]!='P'&&obj.seq[i]!='L'&&obj.seq[i]!='E'&&obj.seq[i]!='D'&&obj.seq[i]!='A'&&obj.seq[i]!='G'&&obj.seq[i]!='V'&&obj.seq[i]!='Y'&&obj.seq[i]!='C'&&obj.seq[i]!='W')
            w++;
    }
    if(w!=0)
    {
        Protein::errordefinition2 ob;
        throw ob;
    }
    cout<<"Choose the type of DNA:"<<endl;
    cout<<"1-Hormon\n2-Enzyme\n3-TF\n4-Cellular_Function"<<endl;
    cin>>c;
    if(c==1)
    {
        obj.type=Hormon;
    }
    if(c==2)
    {
        obj.type=Enzyme;
    }
    if(c==3)
    {
        obj.type=TF;
    }
    if(c==4)
    {
        obj.type=Cellular_Function;
    }
    return in;



}
ostream&operator << (ostream &out,Protein & obj)
{
    out<<"Protein sequence= "<<obj.seq<<endl;

    out<<"Protein type= "<<P[obj.type-1]<<endl;
    return out;
}

void Protein:: add(char*x)
{
    ofstream file ;
    file.open("user_data.txt",ios::app);
    file<<"\n"<<seq<<" "<<x;
    file.close();
}
void Protein:: load(int k)
{
    ifstream filee ;
    filee.open("user_data.txt");
    string x,y;
    int count1=1;
    while(filee>>x>>y)
    {
        if(y=="Protein"&&count1==k)
        {
            strcpy(seq,x.c_str());
            break;
        }
        count1++;
    }
    filee.close();
}
void Protein:: load_all()
{
    ifstream filee ;
    filee.open("user_data.txt");
    string x,y;
    while(filee>>x>>y)
    {
        cout<<x<<" "<<y<<endl;
    }
    filee.close();
}




