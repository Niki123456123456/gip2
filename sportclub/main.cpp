#include <iostream>
#include "teamstatistics.hpp"
#include <string>

using namespace std;

int main()
{
    string abbreviation;
    cin >> abbreviation;

    TeamStatistics s = TeamStatistics(abbreviation);

    int w, h;
    while (cin >> w >> h) {
        s.PushGame(w, h);
    }

    //cout << s.Abbreviation();
    s.WriteToCout();
}
/*
WH
0 0
0 1
3 1

WH 3 4 3:2 +1
*/