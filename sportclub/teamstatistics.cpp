#include <iostream>
#include "teamstatistics.hpp"
#include <string>

using namespace std;

TeamStatistics::TeamStatistics(string abbreviation){
    (*this).abbreviation = abbreviation;
    goals = 0;
    games = 0;
    points = 0;
    opposing_goals = 0;
};

int TeamStatistics::GoalDifference(){
    return goals - opposing_goals;
}

string TeamStatistics::Abbreviation()
{
    return abbreviation;
};

void TeamStatistics::WriteToCout() {
    // [KÜRZEL] [Spiele] [Punkte] [geschossene Tore]:[erhaltene Tore] [Tordifferenz]
    // std::cout << std::showpos << 5 << std::noshowpos;
    cout << Abbreviation() << " " << games << " " << points << " " << goals << ":" << opposing_goals << " " << showpos << GoalDifference() << noshowpos;
}