#include <iostream>
using std::cout, std::cin, std::endl, std::getline;
#include <string>
using std::string, std::stoi;
#include <vector>

string get_operator()
{
    string user_operator;
    cout << "operation: ";
    getline(cin, user_operator);
    return user_operator;
}

int left_operand()
{
    string left_operand;
    cout << "left operand: ";
    getline(cin, left_operand);
    return stoi(left_operand);
}
int right_operand()
{
    string right_operand;
    cout << "right operand: ";
    getline(cin, right_operand);
    return stoi(right_operand);
}

int main()
{
    string user_operator = get_operator();

    while (user_operator != "")
    {

        if (user_operator == "add")
        {
            int operand1 = left_operand();
            int operand2 = right_operand();
            cout << operand1 + operand2 << endl;
            user_operator = get_operator();
        } else if (user_operator == "subtract")
        {
            int operand1 = left_operand();
            int operand2 = right_operand();
            cout << operand1 - operand2 << endl;
            user_operator = get_operator();
        } else if (user_operator == "divide")
        {
            int operand1 = left_operand();
            int operand2 = right_operand();
            cout << operand1 / operand2 << endl;
            user_operator = get_operator();
        } else if (user_operator == "multiply")
        {
            int operand1 = left_operand();
            int operand2 = right_operand();
            cout << operand1 * operand2 << endl;
            user_operator = get_operator();
        } else if (user_operator == "mod")
        {
            int operand1 = left_operand();
            int operand2 = right_operand();
            cout << operand1 % operand2 << endl;
            user_operator = get_operator();
        } else
        {
            cout << user_operator << " isn't a valid operation" << endl;
            user_operator = get_operator();
        }

    }
    
    return 0;
}