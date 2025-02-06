#include <iostream>
using std::cout, std::cin, std::cerr, std::endl;
#include <string>
using std::string, std:: getline;
#include <vector>
using std::vector;
#include <queue>
using std::priority_queue;

string get_input(const string& prompt)
{
    cout << prompt;
    string input;
    getline(cin, input);
    return input;
}

int main(int argc, char const* argv[]) 
{
    priority_queue<string> queue;
    string opp_prompt = "What do you want to do? ";
    string name_prompt = "Name: ";
    string priority_prompt = "Priority: ";
    string input = get_input(opp_prompt);
    while (!input.empty())
    {
        if (input == "add")
        {
            string name = get_input(name_prompt);
            string priority = get_input(priority_prompt);
            if (priority.size() == 1) {priority = "0" + priority;}
            queue.push(priority + " - " + name);

        }
        else if (input == "take")
        {
            if (!queue.empty())
            {
                cout << queue.top() << endl;
                queue.pop();
            }
            else
            {
                cout << "There are no more people in line" << endl;
            }
            
        }
        else
        {
            cerr << input << "isn't a valid operation" << endl;
        }
        input = get_input(opp_prompt);
    }

    return 0;
}
