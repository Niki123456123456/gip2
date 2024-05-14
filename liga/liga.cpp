#include <iostream>
#include "teamstatistics.hpp"
#include "liga.hpp"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void Liga::PushTeam(string abbreviation)
{
    teams.insert(std::pair<string,TeamStatistics>(abbreviation, TeamStatistics(abbreviation)));
}

void Liga::PushGame(string home_team, int home_goals, string away_team, int away_goals)
{
    teams.at(home_team).PushGame(home_goals, away_goals);
    teams.at(away_team).PushGame(away_goals, home_goals);
}

void Liga::WriteToCout()
{
    cout << "TeamStatistics: \n";

    std::vector<std::pair<std::string, TeamStatistics>> vec(teams.begin(), teams.end());

    std::sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) {
        return b.second < a.second;
    });


    for (auto &team : vec)
    {
        team.second.WriteToCout();
        cout << "\n";
    }
}