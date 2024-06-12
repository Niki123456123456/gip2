#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>

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

class NodeBase
{
public:
    string name;
    virtual void ToStream(std::ostream &) const = 0;

    virtual bool IsNeighbor(NodeBase &node) { return false; }

private:
};

template <typename T>
class Node : public NodeBase
{
public:
    Node(T x, T y)
    {
        // n_X_Y
        name = "n_" + std::to_string(x) + "_" + std::to_string(y);
        pos_x = x;
        pos_y = -y;
    }

    void ToStream(std::ostream &s) const override
    {
        // FOO [pos="1,3!"]
        s << " " << name << "[pos=\"" << pos_x << "," << pos_y << "!\"]";
    }

    bool IsNeighbor(NodeBase &node) override
    {
        Node<T> *derived = dynamic_cast<Node<T> *>(&node);
        if (derived != nullptr)
        {
            return (pos_x == derived->pos_x && (pos_y == derived->pos_y + 1 || pos_y == derived->pos_y - 1)) ||
                   (pos_y == derived->pos_y && (pos_x == derived->pos_x + 1 || pos_x == derived->pos_x - 1));
        }
        return false;
    }

private:
    T pos_x;
    T pos_y;
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

    void push_node(NodeBase *node)
    {
        nodes.push_back(node);
    }

    bool are_connected(int a, int b)
    {
        int n = nodes.size();
        return a < n && b < n && matrix[a][b] == 1;
    }

    void init_matrix()
    {
        int n = nodes.size();
        matrix = std::vector<std::vector<float>>(n, std::vector<float>(n, std::numeric_limits<float>::infinity()));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    matrix[i][j] = 0;
                }
                else
                {
                    auto a = nodes[i];
                    auto b = nodes[j];
                    if (a->IsNeighbor(*b))
                    {
                        matrix[i][j] = 1;
                    }
                }
            }
        }

        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (matrix[i][k] < std::numeric_limits<float>::infinity() &&
                        matrix[k][j] < std::numeric_limits<float>::infinity() &&
                        matrix[i][j] > matrix[i][k] + matrix[k][j])
                    {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }
    }

private:
    std::vector<NodeBase *> nodes;
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

    g.init_matrix();

    std::cout << g.are_connected(0, 1) << "\n"; // 0
    std::cout << g.are_connected(1, 1) << "\n"; // 1
    std::cout << g.are_connected(1, 2) << "\n"; // 1

    // g.ToStream(std::cout);
    return 0;
}

/*
build command: g++ -g main.cpp -o main.exe
run command in git bash: ./main.exe < ./maze.txt | neato -Tpdf > ./output.pdf

*/