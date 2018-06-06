#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <vector>
#include <fstream>
#include "NFA.h"
#include "Elem.h"

class List
{
private:
    std :: vector<NFA> members;
public:
    void Read(std :: ifstream&);
    void print();
    void Listprint();
    void printID(int);
    void save(int, char* name);
    bool EmptyID(int);
    bool DFAid(int);
    bool Recognize(int, char*);
    void UnionID(int, int);
    void ConcatID(int, int);
    void UnID(int);
};


#endif // LIST_H_INCLUDED
