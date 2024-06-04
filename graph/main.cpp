#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Field
{
public:
    virtual void ToStream(std::ostream &) const = 0;

    virtual bool Walbable() { return true; }
};

class Wall : public Field
{
public:
    void ToStream(std::ostream &s) const override
    {
        s << "#";
    }

    bool Walbable() { return false; }
};

class Exit : public Field
{
public:
    void ToStream(std::ostream &s) const override
    {
        s << "!";
    }
};

class Blank : public Field
{
public:
    void ToStream(std::ostream &s) const override
    {
        s << " ";
    }
};

class Node
{
public:
    Node(int x, int y)
    {
        // n_X_Y
        name = "n_" + std::to_string(x) + "_" + std::to_string(y);
        pos_x = x;
        pos_y = -y;
    }

    void ToStream(std::ostream &s)
    {
        // FOO [pos="1,3!"]
        s << " " << name << "[pos=\"" << pos_x << "," << pos_y << "!\"]";
    }

private:
    string name;
    int pos_x;
    int pos_y;
};

class Graph
{

public:
    void ToStream(std::ostream &s)
    {
        //s << nodes.size();
        s << "graph {\nnode [shape=\"box\"]\n";
        for (auto &node : nodes)
        {
            node->ToStream(s);
            s << "\n";
        }
        s << "}";
    }

    void push_node(Node *node)
    {
        nodes.push_back(node);
    }

private:
    std::vector<Node *> nodes;
};

int main()
{
    std::vector<std::vector<Field *>> fields = std::vector<std::vector<Field *>>();

    string input;
    while (std::getline(std::cin, input))
    {
        std::vector<Field *> f = std::vector<Field *>();
        for (char c : input)
        {
            if (c == '#')
            {
                f.push_back(new Wall());
            }
            else if (c == ' ')
            {
                f.push_back(new Blank());
            }
        }
        fields.push_back(f);
    }

    Graph g = Graph();
    for (size_t i = 0; i < fields.size(); ++i)
    {
        for (size_t j = 0; j < fields[i].size(); ++j)
        {
            if (fields[i][j]->Walbable())
            {
                //std::cout <<"\n  x=" << i << " y=" << j;
                g.push_node(new Node(j, i));
            }
        }
    }
    
    g.ToStream(std::cout);
    return 0;
}

/*
build command: g++ -g main.cpp -o main.exe teamstatistics.cpp liga.cpp
run command in git bash: ./main.exe < ./maze.txt | neato -Tpdf > ./output.pdf

*/