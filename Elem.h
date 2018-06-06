#ifndef ELEM_H_INCLUDED
#define ELEM_H_INCLUDED

struct Elem
{
    int from;
    int to;
    char terminal;

    Elem(int = 0, int = 0, char = 'ε'); //конструктор по подразбиране и с параметри
};


#endif // ELEM_H_INCLUDED
