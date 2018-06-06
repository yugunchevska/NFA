#ifndef NFA_H_INCLUDED
#define NFA_H_INCLUDED

#include <vector>
#include <fstream>
#include "Elem.h"

class NFA
{
private:
    std :: vector<Elem> lister;
    std :: vector<int> final_state;
public:
    void saveToFile(std :: ofstream&);

    void Add(Elem&);
    void SetFinal(int);

    void Print() const;

    bool Empty() const;
    bool DFA();
    bool Recognize(char*);

    NFA Union(NFA, NFA);
    NFA Concat(NFA, NFA);
    NFA Un(NFA);
};

#endif // NFA_H_INCLUDED
