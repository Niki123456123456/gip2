#include <iostream>
#include "liga.hpp"
#include <string>

using namespace std;

int main()
{
    int count;
    cin >> count;

    Liga l = Liga();

    for (int i = 0; i < count; i++)
    {
        string abbreviation;
        cin >> abbreviation;
        l.PushTeam(abbreviation);
    }

    string w, h;
    int wg, hg;
    while (cin >> h >> hg >> wg >> w)
    {
        l.PushGame(h, hg, w, wg);
    }

    l.WriteToCout();
}
/*
2
AAA
BBB
AAA 1 0 BBB
BBB 2 0 AAA
strg + z

AAA 2 3 1:2 -1
BBB 2 3 2:1 +1

build command: g++ -g main.cpp -o main.exe teamstatistics.cpp liga.cpp
run command: ./main.exe
*/