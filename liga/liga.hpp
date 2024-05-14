#pragma once
#include <string>
#include <map>
#include "teamstatistics.hpp"

using namespace std;

class Liga
{
public:
    void PushTeam(string abbreviation);
    void PushGame(string home_team, int home_goals, string away_team, int away_goals);
    void WriteToCout();

private:
    map<string, TeamStatistics> teams;
};