#include <iostream>
using std::cout, std::cerr, std::endl;

bool even(int n)
{
    return n % 2 == 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "you need to provide just one argument" << endl;
        return 1;
    }
    int start = atoi(argv[1]);
    for (int i = start; i != 1;)
    {
        cout << i << endl;
        if (even(i))
        {
            i = i / 2;
        } else {
            i = (i * 3) + 1;
        }
    }
    cout << 1 << endl;
    return 0;
}