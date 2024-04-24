#include <string>

using namespace std;

class TeamStatistics
{
public:
    TeamStatistics(string abbreviation);
    string Abbreviation();
    int GoalDifference();
    void WriteToCout();
    void PushGame(int goals_scored, int goals_received);

private:
    string abbreviation;
    int games;
    int points;
    int goals;
    int opposing_goals;
};