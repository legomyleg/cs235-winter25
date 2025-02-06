#include <iostream>
using std::cout, std::cerr, std::cin, std::endl;
#include <string>
using std::string, std::getline, std::stoi;
#include <sstream>
using std::istringstream;
#include <fstream>
using std::ifstream;
#include <cctype>

int main(int argc, char const* argv[]) 
{
    if (argc == 1)
    {
        for (int i = 0; i < 10; i++)
        {
            string input;
            cin >> input;
            cout << input << endl;
        }
    } else if (argc == 2)
    {
        try
        {
            int n = stoi(argv[1]);
            if (n < 0) {n = n * -1;}
            for (int i=0; i < n; i++)
            {
                string input;
                cin >> input;
                cout << input << endl;
            }
        } catch (...)
        {
            ifstream file(argv[1]);
            if (!file.is_open())
            {
                cerr << "ERROR: can't open " << argv[1] << endl;
                return 1;
            }
            string line;
            int i(0);
            while (getline(file, line) && i < 10)
            {
                cout << line << endl;
                i++;
            }
        }
    } else if (argc == 3)
    {
        int n = stoi(argv[1]);
        if (n < 0) {n = n * -1;}
        ifstream file(argv[2]);
        if (!file.is_open())
        {
            cerr << "ERROR: can't open " << argv[2] << endl;
            return 1;
        }
        string line;
        int i(0);
        while (getline(file, line) && i < n)
        {
            cout << line << endl;
            i++;
        }
    }

    return 0;
}
