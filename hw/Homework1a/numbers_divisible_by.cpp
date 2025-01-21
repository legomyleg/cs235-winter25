#include <iostream>
using std::cout, std::cerr, std::endl;
#include <cstdlib>
using std::atoi;

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cerr << "you need to provide three arguments" << endl;
        return 1;
    }

    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    int divisor = atoi(argv[3]);

    for (int i = start; i <= end; i++)
    {
        if (i % divisor == 0)
        {
            cout << i << endl;
        }
    }
    for (int i = start; i >= end; i--)
    {
        if (i % divisor == 0)
        {
            cout << i << endl;
        }
    }

}