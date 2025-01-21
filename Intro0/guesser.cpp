#include <iostream>
using std::cout, std::cerr, std::endl, std::cin, std::getline;
#include <cstdlib> // rand(), srand()
#include <ctime> // time()
#include <string>
using std::string;

int main()
{
    srand(time(0));
    int secret = rand() % 100;
    cout << "Guess a number between 1 and 99" << endl;
    int guess = -1;
    while (guess != secret)
    {
        cout << "Guess: ";
        string response;
        getline(cin, response);
        guess = stoi(response);
        if (guess > secret)
        {
            cout << "Too high" << endl;
        } else if (guess < secret)
        {
            cout << "Too low" << endl;
        }
    }
    cout << "You guessed it!" << endl;
}