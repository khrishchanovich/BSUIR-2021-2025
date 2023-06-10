#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <type_traits>
#include <iostream>

template <typename T>

class unique_ptr {

public:
    unique_ptr()
        : ptr(nullptr)
    {

    }

    unique_ptr(T* ptr)
        : ptr(ptr)
    {

    }

    ~unique_ptr()
    {
        delete ptr;
    }

    T& operator*() const
    {
        return *ptr;
    }
    T* operator->() const noexcept
    {
        return ptr;
    }

    T* get() const
    {
        return ptr;
    }

    T* release()
    {
        T* tmp = ptr;
        ptr = nullptr;
        return tmp;
    }

    void reset(T* p)
    {
        delete ptr;
        ptr = p;
    }

    unique_ptr(unique_ptr const& other) = delete;
    unique_ptr& operator=(unique_ptr const& other) = delete;
    unique_ptr& operator=(unique_ptr&& other) noexcept
    {
        reset(other.release());
        return *this;
    }
    unique_ptr(unique_ptr&& other) noexcept
        : ptr(other.release())
    {

    }
private:
    T* ptr;
};
#endif // UNIQUE_PTR_H
