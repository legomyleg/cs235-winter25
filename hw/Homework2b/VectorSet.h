#pragma once
#include <vector>
using std::vector, std::swap;


template<class T>
class VectorSet {
vector<T> vector_set;    
public:
    
    bool contains(T item) const 
    {
        for (auto n : vector_set)
        {
            if (n == item)
            {
                return true;
            }
        }
        return false;
    }

    bool insert(T item) {
        if (contains(item))
        {
            return false;
        }
        vector_set.push_back(item);
        return true;
    }

    bool remove(T item) {
        int back = vector_set.size() - 1;
        if (!contains(item))
        {
            return false;
        }
        for (int i = 0; i < vector_set.size(); i++)
        {
            if (item == vector_set[i])
            {
                swap(vector_set[i], vector_set[back]);
                vector_set.pop_back();
                break;
            }
        }
        return true;
    }

    int size() const {
        return vector_set.size();
    }

    bool empty() const {
        return size() == 0;
    }

    void clear() {
       
        int curr_size = size();
        for (int i = 0; i < curr_size; i++)
        {
            vector_set.pop_back();
        }
        
    }
};
