#include <iostream>
#include "teamstatistics.hpp"
#include <string>

using namespace std;

TeamStatistics::TeamStatistics(string abbreviation){
    (*this).abbreviation = abbreviation;
};

string TeamStatistics::Abbreviation()
{
    return abbreviation;
};