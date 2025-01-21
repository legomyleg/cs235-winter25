#include <iostream>
using std::cout, std::cerr, std::cin, std::endl;
#include <string>
using std::string, std::stoi, std::getline;
#include <sstream>
using std::istringstream;
#include <fstream>
using std::ifstream, std::ofstream;

int main(int argc, char *argv[])
{
    ifstream input_file(argv[1]);
    ofstream output_file(argv[2]);

    if (!input_file.is_open())
    {
        cerr << argv[1] << " failed to open" << endl;
        return 1;
    }
    if (!output_file.is_open())
    {
        cerr << argv[2] << " failed to open" << endl;
        return 1;
    }

    string line;
    while (getline(input_file, line))
    {
        string first_name;
        string last_name;
        int points;
        double factor;
        istringstream line_stream(line);
        line_stream >> first_name;
        line_stream >> last_name;
        line_stream >> points;
        line_stream >> factor;

        output_file << last_name << ", " << first_name << ": " << points * factor << endl;
    }
    input_file.close();
    output_file.close();
    return 0;
}