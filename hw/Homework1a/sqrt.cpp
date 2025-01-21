#include <iostream>
using std::cout, std::cerr, std::endl;
#include <cstdlib>  // atof
using std::abs, std::atof;

const double EPSILON = 0.0001;

int main(int argc, char *argv[])
{
    if (argc != 2 || atof(argv[1]) <= 0)
    {
        cerr << "Input must be greater than 0" << endl;
        return 1;
    }
    double start = atof(argv[1]);
    double upper = start;
    double lower = 0;
    double middle = upper / 2;
    while (abs((middle*middle) - start) > EPSILON)
    {
        cout << middle << " (" << middle*middle << ")" << endl;
        if (middle*middle > start)
        {
            upper = middle;
            middle = (upper + lower) / 2;
        }
        else if (middle*middle < start)
        {
            lower = middle;
            middle = (upper + lower) / 2;
        }
    }
    cout << middle << " (" << middle*middle << ")" << endl;
}

