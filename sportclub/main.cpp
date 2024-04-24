#include <iostream>
#include "teamstatistics.hpp"
#include <string>

using namespace std;

int main()
{
    string abbreviation;
    cin >> abbreviation;

    TeamStatistics s = TeamStatistics(abbreviation);

    //cout << s.Abbreviation();
    s.WriteToCout();
}