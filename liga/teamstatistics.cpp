#include <iostream>
#include "teamstatistics.hpp"
#include <string>

using namespace std;

void TeamStatistics::PushGame(int goals_scored, int goals_received){
    games++;
    goals += goals_scored;
    opposing_goals += goals_received;
    if (goals_scored > goals_received){
        points += 3;
    } else if (goals_scored == goals_received) {
        points += 1;
    }
}

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

 bool TeamStatistics::operator<(const TeamStatistics& other) const {
        if (points != other.points) {
            return points < other.points;
        }
        int goaldiff = goals - opposing_goals;
        int goaldiff2 = other.goals - other.opposing_goals;

        if (goaldiff != goaldiff2) {
            return goaldiff < goaldiff2;
        }
        if (goals != other.goals) {
            return goals < other.goals;
        }
        return abbreviation < other.abbreviation;
    }