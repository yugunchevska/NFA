#include <iostream>
#include <fstream>
#include "list.h"

void List :: Read(std :: ifstream& in) //������ �� ����
{
    int n;
    int _from_;
    int _to_;
    char _ter;
    int q = 0;
    while(in >> n)
    {
        NFA temp;
        members.push_back((temp));
        for(int i = 0; i < n; ++i)
            {
            in >> _from_ >> _to_ >> _ter;
            Elem tmp(_from_, _to_, _ter);
            members[q].Add(tmp);
            }
        int t, w;
        in >> t;
        for(int j = 0; j < t; ++j)
        {
            in >> w;
            members[q].SetFinal(w);
        }
        ++q;
    }
}

void List::print()
{
    for (int i = 0; i < members.size(); i++)
    {
        members[i].Print();
        std :: cout << std :: endl;
    }
}

void List::Listprint() //��������� �� ���������������� �� ������ ��������
{
    int n = members.size();
    for (int i = 0; i < n; ++i)
    {
        std :: cout << i << " ";
    }
}

void List::printID(int a) //��������� �� ������� � ����� '�'
{
    members[a].Print();
}

void List::save(int a, char* name) //��������� ��� ���� � ��� "name" ������� � ����� '�'
{
    std :: ofstream out(name);
    members[a].saveToFile(out);
}

bool List :: EmptyID(int a) //�������� ���� ������ ������� � ����� '�' � ������
{
    return members[a].Empty();
}

bool List :: DFAid(int a) //�������� ���� ��������� � ����� '�' � ������������
{
    return members[a].DFA();
}

bool List :: Recognize(int a, char* word) //������������ �� ���� "word" �� ������� � ����� '�'
{
    return members[a].Recognize(word);
}

void List :: UnionID(int p, int q) //���������� �� �������� � ������� 'p' � 'q'
{
    NFA result, c;
    c = result.Union(members[p], members[q]);
    c.Print();
}

void List :: ConcatID(int p, int q) //������������ �� �������� � ������ 'p' � 'q'
{
    NFA result, c;
    c = result.Concat(members[p], members[q]);
    c.Print();
}

void List :: UnID(int a) //������ �� ������ �� ������� � ����� 'a'
{
    NFA result, c;
    c = result.Un(members[a]);
    c.Print();
}
