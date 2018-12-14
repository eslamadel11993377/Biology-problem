#include "Sequence.h"
#include<bits/stdc++.h>
using namespace std;
Sequence::Sequence()
{
seq=new char[50];
}
Sequence::Sequence(const Sequence& rhs)///copy constructor
{
        seq=new char[strlen(rhs.seq)];
        seq=rhs.seq;
}
Sequence::Sequence(char* x)///parametrize constructor
{
        seq=new char[strlen(x)];
        strcpy(seq,x);///make seq = x
}
Sequence::~Sequence()///destructor
    {
        delete[]seq;///delete the sequence
    };
 char*  Align(Sequence & s1, Sequence & s2)
    {
        int L[strlen(s1.seq)+1][strlen(s1.seq)+1];///make 2d array

        for (int i=0; i<=strlen(s1.seq); i++)
        {
            for (int j=0; j<=strlen(s2.seq); j++)
            {
                if (i == 0 || j == 0)///put the start index =0
                    L[i][j] = 0;
                else if (s1.seq[i-1] == s2.seq[j-1])
                {
                    L[i][j] = L[i-1][j-1] + 1;///make the index before the last equal to 1
                }

                else
                    L[i][j] = max(L[i-1][j], L[i][j-1]);///else get the bigger of two numbers
            }
        }

        int index = L[strlen(s1.seq)][strlen(s2.seq)];///make the maximum possible number of column and rows

        char* lcs=new char[index+1];///make char array to store the chosen character
        lcs[index]='\0'; /// make the last index = /0 to avoid the garbage

        int i = strlen(s1.seq), j = strlen(s2.seq);
        while (i > 0 && j > 0)
        {

            if (s1.seq[i-1] == s2.seq[j-1])///if two characters are equal
            {
                lcs[index-1] = s1.seq[i-1]; /// Put the character in lcs char array
                i--;
                j--;
                index--;
            }

            else if (L[i-1][j] > L[i][j-1])
                i--;
            else///L[i-1][j] < L[i][j-1]
                j--;
        }
        return lcs;
    }

