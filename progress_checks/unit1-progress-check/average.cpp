#include <iostream>
using std::cout, std::endl;
#include <string>
using std::string, std::atof;
#include <sstream>
using std::istringstream;


int main(int argc, char *argv[])
{
    float total(0);
    for (int i = 1; i < argc; i++)
    {
        total = total + atof(argv[i]);
    }
    cout << total/(argc-1) << endl;
    return 0;
}