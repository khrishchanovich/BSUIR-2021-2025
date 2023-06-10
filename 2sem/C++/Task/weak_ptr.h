#ifndef WEAK_PTR_H
#define WEAK_PTR_H

#include "shared_ptr.h"

template <typename T>
class my_weak_ptr
{
public:
   // constexpr my_weak_ptr() noexcept {}
    my_weak_ptr();

// -> =(weak, shared) reset swap lock get_shared_count get_weak_count

    T* operator->()
    {
        return ptr;
    }

//=========================================================
    my_weak_ptr<T> operator=(my_shared_ptr<T>& other)
    {
        if(ptr == nullptr)
        {
            ptr = other.ptr;
            count = other.count;
            weak_count = new int(1);
             return *this;

        } else
        {
            if(other.ptr == nullptr)
            {
                this->reset();
                return *this;

            } else{
                 this->reset();
                ptr = other.ptr;
                count = other.count;
                weak_count = new int(1);
                 return *this;
            }
        }
        }

    my_weak_ptr<T> operator=(my_weak_ptr<T>& other)
    {
        if(ptr == nullptr)
        {
            ptr = other.ptr;
            count = other.count;
            weak_count = other.weak_count;
            (*weak_count)++;
             return *this;

        } else
        {
            if(other.ptr == nullptr)
            {
                this->reset();
                return *this;

            } else
            {
                 this->reset();
                ptr = other.ptr;
                count = other.count;
                weak_count = other.weak_count;
                (*weak_count)++;
                 return *this;
            }
        }
        }

    //=========================================================
    void reset() noexcept
    {
        if(weak_count != nullptr)
        {
            if(--*(weak_count))
            {
                this->count = nullptr;
                this->ptr = nullptr;
                this->weak_count = nullptr;
            } else
            {
                this->count = nullptr;
                this->ptr = nullptr;
                this->weak_count = nullptr;
            }
        }
        }

    //=========================================================

        void swap(my_weak_ptr& _Other) noexcept
        {
            T* swap = _Other.ptr;
            int* swapCounter = _Other.count;
            int* swapWeak_Counter = _Other.weak_count;

            _Other.ptr = this->ptr;
            _Other.count = this->count;
            _Other.weak_count = this->weak_count;
            this->ptr = swap;
            this->count = swapCounter;
            this->weak_count = swapWeak_Counter;
        }


         //=========================================================

         my_shared_ptr<T>& lock()
         {

             my_shared_ptr<T> *ptr = new  my_shared_ptr<T>(this->ptr, this->count);
             this->reset();
             return *ptr;


            }

         //=========================================================

         int get_shared_count() const
         {
             return *(this->count);
         }

         int get_weak_count() const
         {
             return *(this->weak_count);
         }

private:
         T* ptr;
         int *count, *weak_count;
};

template<typename T>
my_weak_ptr<T>::my_weak_ptr():ptr(nullptr), count(nullptr)
{

}
#endif // WEAK_PTR_H
