#include <unordered_map>
using std::unordered_map;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using std::istream, std::cout, std::cin, std::endl, std::ostream;
#include <fstream>
using std::ifstream;
#include <cstdlib>
using std::rand, std::srand;
#include <ctime>
using std::time;
#include <random>
using std::random_device, std::mt19937, std::uniform_int_distribution;

void generate(std::unordered_map<string, vector<string>>& text_map, string& starting_word, int word_count, ostream& out)
{
    string prev_word = starting_word;
    if (!starting_word.empty())
    {
        out << starting_word << " ";
    }
    for (int i = 1; i < word_count; i++)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<size_t> dist(0, text_map[prev_word].size() - 1);
        string curr_word = text_map[prev_word][dist(gen)];
        out << curr_word << " ";
        prev_word = curr_word;
    }
    cout << endl;
}

void aggregate(istream& in, std::unordered_map<string, vector<string>>& text_map)
{
    string prev = "";
    string curr;
    while (in >> curr)
    {
        text_map[prev].push_back(curr);
        prev = curr;
    }
}

int main(int argc, char const* argv[])
{

    ifstream file(argv[1]);
    string prev = "";
    string curr;
    std::unordered_map<string, vector<string>> text_map;

    aggregate(file, text_map);

    // while (file >> curr)
    // {
    //     text_map[prev].push_back(curr);
    //     prev = curr;
    // }
    string start_word = "";
    generate(text_map, start_word, atoi(argv[2]), cout);
    
}