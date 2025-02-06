#include <iostream>
#include <string>
using std::string;

void sort(string& a, string& b, string& c) 
{
    if (a > b)
    {
        swap(a, b);
    }
    if (b > c)
    {
        swap(b,c);
    }
    if (a > b)
    {
        swap(a,b);
    }


}

int main(int argc, char const* argv[]) 
{
    if (argc < 4) 
    {
        std::cerr << "Usage: " << argv[0] << " a b c" << std::endl;
        return 1;
    }

    string a = argv[1];
    string b = argv[2];
    string c = argv[3];

    sort(a, b, c);

    std::cout << a << ' ' << b << ' ' << c << std::endl;

    return 0;
}
