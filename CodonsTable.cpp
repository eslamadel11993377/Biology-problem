#include "CodonsTable.h"
#include"Codon.h"
#include<istream>
#include<bits/stdc++.h>
#include "Protein.h"
using namespace std;
CodonsTable::CodonsTable()///empty constructor
{

}
CodonsTable::~CodonsTable()
{
    for(int i=0; i<64; i++)
    {
        delete &codons[i];///delete codons of i
    }
    delete []codons;
}
void CodonsTable:: LoadCodonsFromFile()///load codons from file
{
    ifstream file;
    file.open("protien.txt");///open file
    int i=0;
    char rnaa[4];/// to take the value of codon
    char amino;/// to take the value of amino
    while(file>>rnaa>>amino)///RNA amino
    {
        strcpy(codons[i].value,rnaa);///set the value of codon
        codons[i].AminoAcid=amino;///set the value of amino
        i++;
    }
}
CodonsTable CodonsTable:: getAminoAcid(char * value)/// take the value of codon and get the value of aminoacid of that codon
{
    string temp;
    for (int j=0; j<strlen(value); j++)
    {
        temp+=value[j];
        if((j+1)%3==0&&j!=0)///to take  each 3 characters of RNA sequence
        {
            if (temp=="UAA"||temp=="UAG"||temp=="UGA")///stop RNA sequence
                break;
            //cout<<":::"<<x<<endl;
            for (int i=0; i<64; i++)
            {
                if (temp==codons[i].value)
                {
                    cout<<codons[i].AminoAcid;///print the aminoacid of the value
                    temp="";
                }

            }
        }
    }
}
void CodonsTable:: setCodon(char * value, char AminoAcid, int index) /// replace one index of array of codons
{
    strcpy(codons[index].value,value);///to make the value of codons of that index equal to the value that need to be added
    codons[index].AminoAcid=AminoAcid;///to make the aminoacid of codons of that index equal to the aminoacid that need to be added
}

