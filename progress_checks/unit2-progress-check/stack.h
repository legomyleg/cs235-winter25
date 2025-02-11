#include <vector>
using std::vector;

template <class T>
class Stack {
    vector<T> _data;

    public:
    Stack() { }

    void push(T const& item) { }

    void pop() { }

    T top() { return T(); }

    size_t size() { return 0; }
};
