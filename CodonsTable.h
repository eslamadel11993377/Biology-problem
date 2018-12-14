#ifndef CODONSTABLE_H
#define CODONSTABLE_H

#include"Codon.h"
class CodonsTable
{
public:
    Codon codons[64];
    CodonsTable();
    ~CodonsTable();
    void LoadCodonsFromFile();
    CodonsTable getAminoAcid(char * value);
    void setCodon(char * value, char AminoAcid, int index);



protected:
private:
};

#endif // CODONSTABLE_H
