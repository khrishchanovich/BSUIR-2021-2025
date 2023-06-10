#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <iostream>

template<typename T>
class my_shared_ptr
{
    template<typename Y>
    friend class my_weak_ptr;

public:
    my_shared_ptr();

    my_shared_ptr(T* obj)
    {
        ptr = obj;
        count = new int(1);
    };

    my_shared_ptr(my_shared_ptr<T>& other)
    {
        ptr = other.ptr;
        count = other.count;
        (*count)++;

    };

    my_shared_ptr(T* obj, int* objCount)
    {
        ptr = obj;
        count = objCount;
    }

    my_shared_ptr<T> operator= (my_shared_ptr<T>& other);

    my_shared_ptr<T> operator=(my_shared_ptr<T>&& other);

    ~my_shared_ptr();

    int use_count() const;

    void reset();

    T& operator*()
    {
        return *ptr;
    }

    T* operator->()
    {
        return ptr;
    }


    // Меняет местами два объекта
    void swap(my_shared_ptr& mp)
    {
        T* swap = mp.ptr;
        int* swapCounter = mp.count;

        mp.ptr = this->ptr;
        mp.count = this->count;
        this->ptr = swap;
        this->count = swapCounter;
    }

private:
    T* ptr;
    int* count;
};

template<typename T>
my_shared_ptr<T>::my_shared_ptr() :ptr(nullptr), count(nullptr)
{

}

template<typename T>
my_shared_ptr<T> my_shared_ptr<T>::operator=(my_shared_ptr<T>& other)
{
    if (ptr == nullptr)
    {
        ptr = other.ptr;
        count = other.count;
        ++*(count);
        return *this;

    }
    else
    {
        if (other.ptr != nullptr)
        {
            this->reset();
            ptr = other.ptr;
            count = other.count;
            ++*(count);

        }
        else
        {
            this->reset();
            return *this;
        }
        return *this;
    }
}

template<typename T>
my_shared_ptr<T> my_shared_ptr<T>::operator=(my_shared_ptr<T>&& other)
{
    if (ptr == nullptr)
    {
        ptr = other.ptr;
        count = other.count;
        ++*(count);
        return *this;

    }
        else
    {
            this->reset();
            ptr = other.ptr;
            count = other.count;
            ++*(count);
            return *this;
        }

}


template<typename T>
my_shared_ptr<T>::~my_shared_ptr()
{
    if (count != nullptr)
    {
        if (-- * (count))
        {
        }
        else
        {
            delete(ptr);
        }
    }
}

template<typename T>
int my_shared_ptr<T>::use_count() const
{
    return *(this->count);
}


 // ==================================================
template<typename T>
void my_shared_ptr<T>::reset()
{
    if (count != nullptr)
    {
        if (-- * (count))
        {
            this->ptr = nullptr;
            this->count = nullptr;
        }
        else
        {
            delete(ptr);
            this->ptr = nullptr;
            this->count = nullptr;
        }
    }
}

#endif // SHARED_PTR_H
