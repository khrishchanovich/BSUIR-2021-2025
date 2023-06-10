#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <iostream>
#include <QMainWindow>
#include <QDebug>

template <typename T>
class my_unique_ptr
{
public:

    my_unique_ptr(T* obj)
    {
        ptr = obj;
    }

    my_unique_ptr()
    {
        ptr = nullptr;
    }



    ~my_unique_ptr()
    {
       qDebug() << 1;
       qDebug() << ptr;
            delete ptr;

       qDebug() << 2;
            ptr = nullptr;
        }

    my_unique_ptr(const my_unique_ptr& other) noexcept

        : ptr(other.ptr)
        {
        other.ptr = nullptr;
        }
      // не допущение конструктора копирования
       // unique_ptr(const unique_ptr& rhs) = delete;   // не допущение оператора присваивания



        T& operator*()
        {
            return *ptr;
        }
        T* operator->()
        {
            return ptr;
        }

        T* operator[](int i)
        {
            ptr[i];
        }

        // функция get(), возвращающая указатель, который лежит в нём.
        T* get() const
        {
            return ptr;
        }

        // release() - зануляет ptr, хранящийся внутри, а старое значение возвращает наружу
        T* release()
        {
            T* tmp = ptr;
            ptr = nullptr;
            return tmp;
        }



        void reset()
        {
            delete ptr;
            this->ptr = nullptr;
        }

        // Меняет местами два объекта
        void swap(my_unique_ptr<T>& mp) noexcept
        {

            T* swap = mp.ptr;

            mp.ptr = this->ptr;
            this->ptr = swap;
        }

        // в аргументе куда хочешь передать
        void move(my_unique_ptr<T>& mp)
        {
//            if(mp.ptr != nullptr){
//                //mp.reset();
//                mp = this->ptr;
//                this->ptr = nullptr;
//            } else {
            if(mp.ptr!= this->ptr)
            {
            mp = this->ptr;
            this->ptr = nullptr;
            }

//            T* tmp = ptr;
//            ptr = nullptr;
//            mp = tmp;

}
       // }
public:
        QString tostring(my_unique_ptr<T> &pt)
        {
           int con = &pt;
           QString convert = QString::number(con);
            return convert;
        }


      private:
        T* ptr;
};

#endif // UNIQUE_PTR_H
