#include <iostream>
using std::cout, std::cin, std::cerr, std::endl;
#include <string>
using std::string;
#include <fstream>
using std::ifstream;
#include <set>
using std::set;
#include <list>
using std::list;

bool duplicate(list<string>& items, const string& item)
{
    for (auto item_check : items)
    {
        if (item_check == item)
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char const* argv[]) 
{
    if (argc == 2)
    {
        ifstream file(argv[1]);
        if (!file.is_open())
        {
            cerr << "Could not open " << argv[1] << endl;
            return 1;
        }
        list<string> lines;
        string line;
        while (getline(file, line))
        {
            if (!duplicate(lines, line))
            {
                cout << line << endl;
                lines.push_back(line);
            }
            
        }
    }
    if (argc == 1)
    {
        list<string> lines;
        string line;
        getline(cin, line);
        while (line != "")
        {
            if (!duplicate(lines, line))
            {
                cout << line << endl;
                lines.push_back(line);
            }
            line = "";
            getline(cin, line);
        }
    }


    return 0;
}



