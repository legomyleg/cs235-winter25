#pragma once

#include <iostream>
using std::cout, std::endl;
#include <vector>
using std::vector;

template<class T>
class NoisyVector
{
    private:
    int pop_count(0);
    int push_count(0);
    int size_count(0);
    int index_count(0);

    public:
    vector<T> _data;
    NoisyVector() {}

    void pop_back()
    {
        _data.pop_back();
        pop_count++;
        cout << "pop called " << pop_count << " times" << endl;
    }
    void push_back()
    {
        
    }


};