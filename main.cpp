#include <iostream>
#include "DNA.h"
#include "RNA.h"
#include"DNA.h"
#include"Sequence.h"
#include "CodonsTable.h"
#include"Codon.h"
using namespace std;

int main()
{
    int choice=0;
    CodonsTable c;
    c.LoadCodonsFromFile();
    DNA d1,d2,d3,d4;
    RNA r1,r2,r3,r4;
    Protein p1,p2,p3,p4;
    while (true)
    {
        cout<<"1-Create a DNA\n2-Create a RNA\n3-Create a Protein\n4-Do something with codons table\n5-Exit\n";
        cin>>choice;
        if(choice==1)
        {
            try
            {

                while(true)
                {

                    cout<<"0-To enter ur Data\n1-Do operators for DNA\n2-Load specific sequence from file\n3-Load all sequences from File\n4-The complement strand of a DNA \n5-Convert a DNA to RNA\n6-Alignment\n7-Exit\n";

                    int choice2=0;
                    cin>>choice2;
                    if (choice2==0)
                    {
                        cout<<"Enter DNA1:"<<endl;
                        cin>>d1;
                        d1.add("DNA");
                        cout<<"Enter DNA2:"<<endl;
                        cin>>d2;
                        d2.add("DNA");
                        cout<<"DNA1= "<<endl<<d1;
                        cout<<"DNA2= "<<endl<<d2;
                    }
                    if(choice2==1)
                    {
                        cout<<"1-IS(DNA1==DNA2)\n2-IS(DNA1!=DNA2)\n3-DNA1+DNA2\n4-DNA1=DNA2\n";
                        int choice3=0;
                        cin>>choice3;
                        if(choice3==1)
                            cout<<"IS(DNA1==DNA2)= "<<(d1==d2)<<endl;
                        if (choice3==2)
                            cout<<"IS(DNA1!=DNA2)= "<<(d1!=d2)<<endl;
                        if (choice3==3)
                        {
                            d3=d1+d2;
                            d3.add("DNA");
                            cout<<"(DNA1+DNA2)= "<<d3<<endl;
                        }
                        if(choice3==4)
                        {
                            cout<<"(DNA1=DNA2)= "<<endl;
                            d1=d2;
                            cout<<d1;
                        }
                    }
                    if(choice2==2)
                    {
                        int choice3=0;
                        cout<<"enter the number for the line's sequence: ";
                        cin>>choice3;
                        d4.load(choice3);
                        cout<<d4;
                    }
                    if(choice2==3)
                    {
                        d4.load_all();
                    }
                    if(choice2==4)
                    {
                        cout<<"enter star & end : ";
                        int start=0,endd=0;
                        cin>>start>>endd;
                        cout<<"The complement strand of DNA1= "<<endl;
                        d1.BuildComplementaryStrand(start,endd);
                    }
                    if(choice2==5)
                    {
                        RNA r;
                        cout<<"Convert DNA1 to RNA: "<<endl;
                        r=(d1.ConvertToRNA());
                        r.add("RNA");
                        cout<<r;
                    }
                    if(choice2==6)
                    {
                        Align(d1,d2);
                    }
                    if(choice2==7)
                    {
                        break;
                    }
                    cout<<endl;
                }
            }
            catch(DNA::errorsize)
            {
                cout<<"The size of the sequence must be equal to 3 and its multiples"<<endl;

            }
            catch(DNA ::errordefinition)
            {
                cout<<"DNA sequence is formed only by the following 4 characters A,C,G,T"<<endl;
            }
        }
        if(choice==2)
        {
            try
            {

                while(true)
                {
                    int choice2=0;
                    cout<<"0-To enter ur Data\n1-Do operators for RNA\n2-Load specific sequence from file\n3-Load all sequences from File\n4-Convert a RNA to DNA \n5-Convert a RNA to Protein\n6-Alignment\n7-Exit\n";
                    cin>>choice2;
                    if (choice2==0)
                    {

                        cout<<"Enter RNA1:"<<endl;
                        cin>>r1;
                        r1.add("RNA");
                        cout<<"Enter RNA2:"<<endl;
                        cin>>r2;
                        r2.add("RNA");
                        cout<<"RNA1= "<<endl<<r1;
                        cout<<"RNA2= "<<endl<<r2;
                    }
                    if(choice2==1)
                    {
                        cout<<"1-IS(RNA1==RNA2)\n2-IS(RNA1!=RNA2)\n3-RNA1+RNA2\n4-RNA1=RNA2\n";
                        int choice3=0;
                        cin>>choice3;
                        if(choice3==1)
                            cout<<"IS(RNA1==RNA2)= "<<(r1==r2)<<endl;
                        if (choice3==2)
                            cout<<"IS(RNA1!=RNA2)= "<<(r1!=r2)<<endl;
                        if (choice3==3)
                        {
                            r3=r1+r2;
                            r3.add("RNA");
                            cout<<"(RNA1+RNA2)= "<<r3<<endl;
                        }
                        if(choice3==4)
                        {
                            cout<<"(RNA1=RNA2)= "<<endl;
                            r1=r2;
                            cout<<r1;
                        }
                    }

                    if(choice2==2)
                    {
                        int choice3=0;
                        cout<<"enter the number for the line's sequence: ";
                        cin>>choice3;
                        r4.load(choice3);
                        cout<<r4;
                    }
                    if(choice2==3)
                    {
                        r4.load_all();
                    }

                    if(choice2==4)
                    {
                        DNA d;
                        cout<<"Convert RNA1 to DNA: "<<endl;
                        d=r1.ConvertToDNA();
                        d.add("DNA");
                        cout<<d;
                    }
                    if(choice2==5)
                    {
                        Protein p;
                        cout<<"Convert RNA1 to Protein: "<<endl;
                        p=r1.ConvertToProtein(c);
                        p.add("Protein");
                        cout<<p;
                    }
                    if(choice2==6)
                    {
                        cout<<Align(r1,r2);
                    }

                    if(choice2==7)
                    {
                        break;
                    }
                    cout<<endl;
                }
            }
            catch(RNA::errorsize1)
            {
                cout<<"The size of the sequence must be equal to 3 and its multiples"<<endl;

            }
            catch(RNA ::errordefinition1)
            {
                cout<<"RNA sequence is formed only by the following 4 characters A,C,G,U"<<endl;
            }
        }
        if(choice==3)
        {
            try
            {

                while(true)
                {
                    int choice2=0;
                    cout<<"0-To enter ur Data\n1-Do operators for Protein\n2-Load specific sequence from file\n3-Load all sequences from File\n4-Convert a Protein to DNA \n5-Alignment\n6-Exit\n";
                    cin>>choice2;
                    if (choice2==0)
                    {

                        cout<<"Enter Protein1:"<<endl;
                        cin>>p1;
                        p1.add("Protein");
                        cout<<"Enter Protein2:"<<endl;
                        cin>>p2;
                        p2.add("Protein");
                        cout<<"Protein1= "<<endl<<p1;
                        cout<<"Protein2= "<<endl<<p2;
                    }
                    if(choice2==1)
                    {
                        int choice3=0;
                        cout<<"1-IS(Protein1==Protein2)\n2-IS(Protein1!=Protein2)\n3-Protein1+Protein2\n4-Protein1=Protein2\n";
                        cin>>choice3;
                        if(choice3==1)
                            cout<<"IS(Protein1==Protein2)= "<<(p1==p2)<<endl;
                        if(choice3==2)
                            cout<<"IS(Protein1!=Protein2)= "<<(p1!=p2)<<endl;
                        if(choice3==3)
                        {
                            p3=p1+p2;
                            p3.add("Protein");
                            cout<<"(Protein1+Protein2)= "<<p3<<endl;
                        }
                        if(choice3==4)
                            cout<<"(Protein1=Protein2)= "<<(p1=p2)<<endl;
                    }
                    if(choice2==2)
                    {
                        int choice3=0;
                        cout<<"enter the number for the line's sequence: ";
                        cin>>choice3;
                        p4.load(choice3);
                        cout<<p4;
                    }
                    if(choice2==3)
                    {
                        p4.load_all();
                    }

                    if(choice2==4)
                    {
                        cout<<"enter ur big dna:"<<endl;
                        DNA bigDNA;
                        cin>>bigDNA;
                        DNA *DNA_After_convert;
                        int obj_index=0;
                        DNA_After_convert=p1.GetDNAStrandsEncodingMe(bigDNA,c,obj_index);
                        for(int i=0; i<obj_index; i++)
                        {
                            cout<<*(DNA_After_convert+i)<<endl;
                        }

                    }
                    if(choice2==5)
                    {
                        cout<<Align(p1,p2);
                    }
                    if(choice2==6)
                    {
                        break;
                    }
                    cout<<endl;
                }

            }
            catch(Protein ::errordefinition2)
            {
                cout<<"Do not match the protein's letters"<<endl;
            }
            catch(DNA::errorsize)
            {
                cout<<"The size of the sequence must be equal to 3 and its multiples"<<endl;

            }
            catch(DNA ::errordefinition)
            {
                cout<<"DNA sequence is formed only by the following 4 characters A,C,G,T"<<endl;
            }
        }

        if(choice==4)
        {
            int choice2=0;
            cout<<"1-getAminoAcid\n2-setCodon\n";
            cin>>choice2;
            if (choice2==1)
            {
                int lengthOfValue=0;
                cout<<"enter the length of the value: ";
                cin>>lengthOfValue;
                cout<<"enter ur value: ";
                char *value;
                value=new char[lengthOfValue];
                cin>>value;
                c.getAminoAcid(value);
                cout<<endl;
            }
            if (choice2==2)
            {
                cout<<"enter value & amino acid & the number of ur index:\n";
                char *value;
                value=new char[3];
                cin>>value;
                char amino;
                cin>>amino;
                int index=0;
                cin>>index;
                index++;
                c.setCodon(value,amino,index);
            }
        }

        if(choice==5)
        {
            exit(0);
        }
    }



}
