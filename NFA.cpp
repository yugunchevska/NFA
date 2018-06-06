#include <iostream>
#include <fstream>
#include <cstring>
#include "NFA.h"

void NFA :: Add(Elem& p) // добавя нов преход към автомата
{
    lister.push_back(p);
}

void NFA :: SetFinal(int a) //добавя ново финално състояние
{
    final_state.push_back(a);
}

void NFA :: Print() const
{
    for(int i = 0; i < lister.size(); ++i)
        std :: cout << "q" <<lister[i].from << "-->q" << lister[i].to << " Terminal: " << lister[i].terminal << std :: endl;
    for(int i = 0; i < final_state.size(); ++i)
        std :: cout << "Final State: q" << final_state[i] << std :: endl;
}

void NFA::saveToFile(std::ofstream& out) //запазва в нов файл
{
    int n = lister.size();
    out << n << std::endl;
    for (int i = 0; i < n; ++i)
    {
        out << lister[i].from << " " << lister[i].to << " " << lister[i].terminal << std::endl;
    }
}

bool NFA :: Empty() const // проверява дали езикът на автомата не е празен, т.е. да се състои само от епсилон-преходи
{
    int counter = 0;
    for(int i = 0; i < lister.size(); ++i)
    {
        if(lister[i].terminal != 'e')
        {
            return 0;
        }
    }
    return 1;
}

bool NFA :: DFA() //проверява дали автоматът е детерминиран
{
    for(int i = 0; i < lister.size(); ++i)
    {
        for(int j = i + 1; j < lister.size() - 1; ++i)
        {
            if(lister[i].from == lister[j].from && lister[i].terminal == lister[j].terminal)
                return 0;
        }
    }
    return 1;
}


NFA NFA :: Union(NFA a, NFA b) //обединение на два автомата
{
    NFA result;
    for(int i = 0; i < a.lister.size(); ++i)
        result.Add(a.lister[i]);
    for(int i = 0; i < a.final_state.size(); ++i)
        result.SetFinal(a.final_state[i]);
    for(int i = 0; i < b.lister.size(); ++i)
        result.Add(b.lister[i]);
    for(int i = 0; i < b.final_state.size(); ++i)
        result.SetFinal(b.final_state[i]);

    return result;
}

NFA NFA :: Concat(NFA a, NFA b) //конкатенация на два автомата
{
    NFA result;
    for(int i = 0; i < a.lister.size(); ++i)
        result.Add(a.lister[i]);

    for(int j = 0; j < b.lister.size(); ++j)
    {
        if(b.lister[j].from == 1)
        {
            for(int i = 0; i < a.final_state.size();++i)
            {
                Elem tmp;
                tmp.from = a.final_state[i];
                tmp.to = b.lister[j].to;
                tmp.terminal = b.lister[j].terminal;

                result.Add(tmp);
            }
        }
        else
            result.Add(b.lister[j]);
    }

    return result;
}

NFA NFA :: Un(NFA a) //звезда на Клийни на автомат
{
    NFA result;

    for(int i = 0; i < a.lister.size(); ++i)
        result.Add(a.lister[i]);
    for(int i = 0; i < a.lister.size(); ++i)
    {
        if(a.lister[i].from == 1)
        {
            for(int j = 0; j < a.lister.size(); ++j)
            {
                if(a.lister[j].to != 1)
                {
                    Elem tmp;
                    tmp.from = a.lister[j].to;
                    tmp.to = a.lister[i].to;
                    tmp.terminal = a.lister[i].terminal;

                    result.Add(tmp);
                }
            }
        }
    }

    for (int i = 0; i < result.lister.size() - 1; ++i)
    {
        for(int k = i + 1; k < result.lister.size(); ++k)
        if(result.lister[i].from == result.lister[k].from && result.lister[i].to == result.lister[k].to && result.lister[i].terminal == result.lister[k].terminal)
            {
                result.lister.erase(result.lister.begin() + k);
            }
    }

    return result;
}

bool NFA :: Recognize(char* word) //разпознаване на дума от детерминиран автомат
{
    int currentPos = 1;
    int counter = 0;
    for(int i = 0; i < strlen(word); ++i)
    {
        for(int k = 0 ; k < lister.size(); ++k)
        {
            if(lister[k].from == currentPos && lister[k].terminal == word[i])
                {
                    currentPos = lister[k].to;
                    std :: cout << "curr : " << currentPos << std::endl;
                    counter++;
                    break;
                }
        }
        if(!counter)
        return 0;
        counter = 0;
    }

    counter = 0;
    for(int i = 0; i < final_state.size(); i++)
        if(currentPos == final_state[i])
        counter++;
    if(counter)
    return 1;
    return 0;

}
