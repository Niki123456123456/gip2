#include <string>

using namespace std;

class Greeting
{
    public:
    Greeting(string message);
    void Print();
    void Tick();

    private:
        string message = "test";
        int tick = 0;
};