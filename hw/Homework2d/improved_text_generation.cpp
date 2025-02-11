#include <unordered_map>
using std::unordered_map;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using std::istream, std::cout, std::cin, std::endl, std::ostream;
#include <fstream>
using std::ifstream, std::ofstream;
#include <cstdlib>
using std::rand, std::srand;
#include <ctime>
using std::time;
#include <random>
using std::random_device, std::mt19937, std::uniform_int_distribution;

void display_map(unordered_map<string, vector<string>> dmap)
{
    for (auto pair : dmap)
    {
        cout << pair.first << ": ";
        for (auto item : pair.second)
        {
            cout << item << " ";
        }
        cout << endl;
    }
}


void generate(unordered_map<string, vector<string>>& text_map, string& starting_word, int word_count, ostream& out)
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

void aggregate(istream& in, unordered_map<string, vector<string>>& text_map)
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
    unordered_map<string, vector<string>> text_map;

    aggregate(file, text_map);

    ifstream file1(argv[2]);

    aggregate(file1, text_map);

    ifstream file2(argv[3]);

    aggregate(file2, text_map);

    ofstream out("generated_text.txt");
    string start_word = "";
    generate(text_map, start_word, atoi(argv[4]), cout);
    
    return 0;
}