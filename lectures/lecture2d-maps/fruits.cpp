#include <iostream>
using std::cout, std::endl;
#include <map>
using std::map;
#include <vector>
using std::vector;
#include <set>
using std::set;
#include <string>
using std::string;
#include "input.h"

int main()
{
    map<char, set<string>> fruits;
    string fruit;
    while (input("Fruit: ", fruit))
    {
        fruits[fruit[0]].insert(fruit);
    }
    for (auto &pair : fruits)
    {
        cout << pair.first << ": ";
        for (auto &item : pair.second)
        {
            cout << item << " ";
        }
        cout << endl;
    }
}