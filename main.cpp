#include <iostream>
#include <cstring>
#include "NFA.h"
#include "Elem.h"
#include "List.h"

using namespace std;

int main()
{
    ifstream in("data.txt");
    List test;
    test.Read(in);

    char command[20];
    int n, m;
    cin.getline(command, 20);

    if(!strcmp(command, "Open"))
        test.Read(in);
    if(!strcmp(command, "List"))
        test.Listprint();
    if(!strcmp(command, "Print"))
    {
        std::cin >> n;
        test.printID(n);
    }
    if(!strcmp(command, "Save"))
        {
            std::cin >> n;
            cin >> command;
            test.save(n, command);
        }
    if(!strcmp(command, "Empty"))
    {
        std::cin >> n;
        test.EmptyID(n);
    }
    if(!strcmp(command, "Deterministic"))
    {
        std::cin >> n;
        test.DFAid(n);
    }
    if(!strcmp(command, "Recognize"))
    {
        std::cin >> n;
        cin >> command;
        test.Recognize(n, command);
    }
     if(!strcmp(command, "Union"))
    {
        std::cin >> n >> m;
        test.UnionID(n, m);
    }
    if(!strcmp(command, "Concat"))
    {
        std::cin >> n >> m;
        test.ConcatID(n, m);
    }
    if(!strcmp(command, "Un"))
    {
        std::cin >> n;
        test.UnID(n);
    }

    return 0;
}
