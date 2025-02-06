#include <unordered_set>
using std::unordered_set;
#include <string>
using std::string, std::getline;
#include <iostream>
using std::cout, std::cin, std::endl;
#include <vector>
using std::vector;

bool unique(const unordered_set<string>& all_ids, const string& id)
{
    if (all_ids.find(id) != all_ids.end())    // if id already in use 
    {
        return false;
    }
    return true;
}

int main(int argc, const char *argv[])
{
    cout << "Provide a unique ID: ";    // prompt user for user id
    string user_id;
    unordered_set<string> seen_ids;
    getline(cin, user_id);
    vector<string> names;
    vector<string> ids;

    while (!user_id.empty())    // loop the following as long as the user input is not empty
    {

        while (!unique(seen_ids, user_id))    // loop until unique() return false:
        {
            if (user_id.empty()) {break;}
            cout << "ID already in use. Please provide another one: ";    // indicate this to user
            getline(cin, user_id);    // prompt again
            
        }
        seen_ids.insert(user_id);
        
        string first_name;
        string last_name;
        cout << "Please provide a first name: ";    // Prompt for first and last name
        getline(cin, first_name);
        cout << "Please provide a last name: ";
        getline(cin, last_name);
        names.push_back(first_name + " " + last_name);
        ids.push_back(user_id);

        cout << "Next user ID: ";
        getline(cin, user_id);
    }

    if (names.size() == 0) {return 0;}
    for (int i = 0; i < names.size(); i++)
    {
        cout << names.at(i) << " " << "(" << ids.at(i) << ")" << endl;
    }
        
            
            
            // else: procees
    
        // next user
    // when loop is over, print all as First Last (ID)

    return 0;
}
