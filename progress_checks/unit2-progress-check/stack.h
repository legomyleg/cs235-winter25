#include <vector>
using std::vector;

template <class T>
class Stack {
    vector<T> _data;

    public:
    Stack() {}

    void push(T const& item) 
    {
        _data.push_back(item);
    }

    void pop() 
    { 
        _data.pop_back();
    }

    T top() 
    { 
        return _data[_data.size()-1];
    }

    size_t size() 
    { 
        return _data.size(); 
    }
};
