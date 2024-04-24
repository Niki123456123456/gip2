#include <iostream>
#include "greeting.hpp"

using namespace std;


int main()
{
    Greeting g= Greeting("12");
    g.Tick();
    g.Tick();
    g.Print();
    cout << "Hello World" << endl;
}