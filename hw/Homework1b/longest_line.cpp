#include <iostream>
using std::cout, std::cerr, std::cin, std::endl;
#include <string>
using std::string, std::stoi, std::getline;
#include <sstream>
using std::istringstream;
#include <fstream>
using std::ifstream, std::ofstream;

int count(string line)
{
    istringstream line_stream(line);
    int total(0);
    string word;
    while (line_stream >> word)
    {
        total = total + 1;
    }
    return total;
}

int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    if (!file.is_open())
    {
        cerr << argv[1] << " did not open" << endl;
        return 1;
    }

    string line;
    int highest(0);
    string highest_line("");
    while (getline(file, line))
    {
        if (count(line) > highest)
        {
            highest = count(line);
            highest_line = line;
        }
    }
    
    cout << highest_line << endl;
    return 0;

}