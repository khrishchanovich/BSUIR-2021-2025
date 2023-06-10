#ifndef UNORDERED_MAP_H
#define UNORDERED_MAP_H

#include <cmath>
#include <list>

#define GoldenRatio 0.6180339887499

template <class T1, class T2, class HashFunctor>

class Unordered_Map
{
protected:

    int getHash(T1 key)
    {
        HashFunctor hashFunctor;
        double temp = hashFunctor(key) * GoldenRatio;
        temp = fabs(temp - (int)temp);
        return (int)(capacity * temp);
    }

    std::list<std::pair<T1, T2>>* list;

    int capacity;
    int size_;

public:
    Unordered_Map(int capacity_)
    {
        capacity = capacity_;
        list = new std::list<std::pair<T1, T2>>[capacity];
        size_ = 0;
    }


    ~Unordered_Map() {
        Clear();

        delete[] list;
    }

    void Clear()
    {
        for (int i = 0; i < capacity; i++)
            list[i].clear();

       size_ = 0;
    }

    std::pair<T1, T2>* Search(T1 key)
    {
        int hash = getHash(key);

        for (auto& it : list[hash])
            if (it.first == key)
                return &it;

        return nullptr;
    }

    bool Contains(T1 key)
    {
        return Search(key) ? true : false;
    }

    void Insert(std::pair<T1, T2> item)
    {
        int hash = getHash(item.first);

        if (!Search(item.first))
        {
            list[hash].push_back(item);
            ++size_;
        }
    }

    void Erase(T1 key)
    {
        int hash = getHash(key);

        for (auto it = list[hash].begin(); it != list[hash].end(); ++it)
        {
            if ((*it).first == key)
            {
                list[hash].erase(it);
                --size_;
                return;
            }
        }
    }

    T2& operator[](T1 key)
    {

        Insert(std::make_pair(key, T2()));

        return Search(key)->second;
    }

    T2 operator[](T1 key) const
    {

        Insert(std::make_pair(key, T2()));

        return Search(key)->second;
    }

    int get_capacity()
    {
        return capacity;
    }

    int get_size_()
    {
        return size_;
    }

    std::list<std::pair<T1, T2>>* get_arr()
    {
        return list;
    }


};

#endif // UNORDERED_MAP_H
