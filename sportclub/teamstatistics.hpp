#include <string>

using namespace std;

class TeamStatistics
{
public:
    TeamStatistics(string abbreviation);
    string Abbreviation();
    int GoalDifference();
    void WriteToCout();

private:
    string abbreviation;
    int games;
    int points;
    int goals;
    int opposing_goals;
};