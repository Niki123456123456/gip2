#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
#include <map>

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
    string name;
    int pos_x;
    int pos_y;

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
};

class PathCost
{
public:
    int total_costs;
    string predecessor;
};

class Graph
{

public:
    void ToStream(std::ostream &s)
    {
        // s << nodes.size();
        s << "graph {\nnode [shape=\"box\"]\n";
        for (auto &node : nodes)
        {
            node->ToStream(s);
            s << "\n";
        }

        int n = nodes.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (matrix[i][j] == 1)
                {
                    // [id1] -- [id2]
                    s << nodes[i]->name << " -- " << nodes[j]->name << "\n";
                }
            }
        }
        s << "}";
    }

    void push_node(Node *node)
    {
        nodes.push_back(node);
    }

    void get_shortest_distances(int start_costs, string node_name, map<string, PathCost> *result)
    {
        for (auto &node : nodes)
        {
            if (node->name == node_name)
            {
                for (auto &node2 : nodes)
                {
                    int dx = abs(node->pos_x - node2->pos_x);
                    int dy = abs(node->pos_y - node2->pos_y);
                    if (dx <= 1 && dy == 0 || dx == 0 && dy <= 1)
                    {
                        int neighbor_total_costs = max(dx, dy) + start_costs;
                        bool found_new_shortest_path = true;
                        auto it = result->find(node2->name);
                        if (it != result->end())
                        {
                            found_new_shortest_path = neighbor_total_costs < it->second.total_costs;
                            if (found_new_shortest_path)
                            {
                                PathCost cost = PathCost();
                                cost.predecessor = node_name;
                                cost.total_costs = neighbor_total_costs;
                                (*result)[node2->name] = cost;
                            }
                        }
                        else
                        {
                            PathCost cost = PathCost();
                            cost.predecessor = node_name;
                            cost.total_costs = neighbor_total_costs;
                            (*result)[node2->name] = cost;
                        }
                        if (found_new_shortest_path)
                        {
                            get_shortest_distances(neighbor_total_costs, node2->name, result);
                        }
                    }
                }
                break;
            }
        }
    }

private:
    std::vector<Node *> nodes;
    std::vector<std::vector<float>> matrix;
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
    for (size_t i = 0; i < fields.size(); i++)
    {
        for (size_t j = 0; j < fields[i].size(); j++)
        {
            if (fields[i][j]->Walbable())
            {
                // std::cout <<"\n  x=" << i << " y=" << j;
                g.push_node(new Node(j, i));
            }
        }
    }

    string node_name = "n_3_3";

    //std::getline(std::cin, node_name);

    auto costs = new std::map<std::string, PathCost>();
    g.get_shortest_distances(0, node_name, costs);

    for (const auto &pair : (*costs))
    {
        // NODE_2_1 2 NODE_2_2
        if (pair.second.total_costs == 0) {
            std::cout << pair.first << " " << pair.second.total_costs << " -" << std::endl;
        } else {
            std::cout << pair.first << " " << pair.second.total_costs << " " << pair.second.predecessor << std::endl;
        }
        
    }

    return 0;
}

/*
build command: g++ -g main.cpp -o main.exe
run command in git bash: ./main.exe
*/