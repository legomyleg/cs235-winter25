#include <unordered_set>
using std::unordered_set;
#include <string>
using std::string;
#include <iostream>
using std::cout, std::endl;

bool stored(const string& id)
{
    return true;
}

int main(int argc, char *argv[])
{
    unordered_set<int> my_set = {1,2,3,4,5};
    if (my_set.find(atoi(argv[1])) != my_set.end())
    {
        cout << "In set" << endl;
    } else
    {
        cout << "Not in set" << endl;
    }
    return 0;
}
