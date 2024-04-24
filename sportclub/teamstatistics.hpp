#include <string>

using namespace std;

class TeamStatistics
{
public:
    TeamStatistics(string abbreviation);
    string Abbreviation();

private:
    string abbreviation;
};