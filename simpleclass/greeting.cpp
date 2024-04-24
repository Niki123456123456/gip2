#include <iostream>
#include "greeting.hpp"
#include <string>

using namespace std;

void Greeting::Print()
{
    cout << message << " Tick:" << tick << endl;
};

void Greeting::Tick()
{
    tick++;
};


Greeting::Greeting(string message){
    (*this).message = message;
};
