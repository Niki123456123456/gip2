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

    int x, y;

    for (size_t i = 0; i < fields.size(); ++i)
    {
        for (size_t j = 0; j < fields[i].size(); ++j)
        {
            if (fields[i][j]->Walbable())
            {
                if (i == 0 || j == 0 || i + 1 == fields.size() || j + 1 == fields[i].size())
                {
                    x = i;
                    y = j;
                }
            }
        }
    }

    fields[x][y] = new Exit();
    for (const auto &row : fields)
    {
        for (const auto &field : row)
        {
            field->ToStream(std::cout);
        }
        std::cout << std::endl;
    }

    return 0;
}
