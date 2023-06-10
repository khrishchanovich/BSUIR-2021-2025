#ifndef ARRAY_H
#define ARRAY_H

#include <QMainWindow>
#include <QDebug>
template < class T>
class ArrayList {
public:
    typedef T * iterator;

    ArrayList();
    ArrayList(int size, T const& a);
    ArrayList(const ArrayList<T> & a);
    ~ArrayList();
    int size() const;
    void push_back(const T& val);
    void push_front(const T& val);
    void push_insert(int,const T& val);
    void deleteNum(int,const T& val);
    void pop_back();
    T& operator[](int index);
    ArrayList<T>& operator=(const ArrayList<T>& a);
private:
    int  _size;
    int  _capacity;
    T*      _buf;
    const int _max_capacity = 65536;
};

template<class T>
ArrayList<T>::ArrayList()
{
    _size = 0;
    _buf = new T[1];
    _capacity = 1;
}

template<class T>
ArrayList<T>::ArrayList(int s, const T& a)
{
    if (s > _max_capacity) {
        s = _max_capacity;
    }
    _size = s;
    _capacity = 1;
    while (_capacity < _size) {
        _capacity *= 2;
    }
    _buf = new T[_capacity];
    for (int i = 0; i < _size; i++) {
        _buf[i] = a;
    }
}
template<class T>
ArrayList<T>::ArrayList(const ArrayList<T> & a)
{
    _size = a._size;
    _capacity = a._capacity;
    _buf = new T[_capacity];
    for (int i = 0; i < _size; i++) {
        _buf[i] = a._buf[i];
    }
}
template<class T>
ArrayList<T>::~ArrayList()
{
    delete[] _buf;
}

template<class T>
int ArrayList<T>::size() const
{
    return _size;
}

template<class T>
T& ArrayList<T>::operator[](int index)
{
    return _buf[index];
}

template<class T>
void ArrayList<T>::push_back(const T& val)
{
    T * tmp = new T[++_size];
    for (int i = 0; i < _size-1; i++) {
        tmp[i] = _buf[i];
    }
    tmp[_size-1] = val;
    delete[] _buf;
    qDebug() << _size;
    _buf = tmp;
}

template<class T>
void ArrayList<T>::push_front(const T& val)
{
    T * tmp = new T[++_size];
    for (int i = 1; i < _size; i++) {
        tmp[i] = _buf[i-1];
    }
    tmp[0] = val;
    delete[] _buf;
    _buf = tmp;
}

template<class T>
void ArrayList<T>::push_insert(int a, const T& val)
{
    if(a==0){
        push_front(val);
        return;
    }
    if(a==size()){
        push_back(val);
        return;
    }
    if (_size < _capacity) {
        _buf[_size] = val;
        _size++;
        return ;
    } else if (_size == _max_capacity) {
        return ;
    }

    T * tmp = new T[++_size];

    for (int i = 0; i < a; i++) {
        tmp[i] = _buf[i];
    }
    tmp[a] = val;
    for (int i = a+1; i < size(); i++) {
        tmp[i] = _buf[i-1];
    }
    delete[] _buf;
    _buf = tmp;
}


template<class T>
void ArrayList<T>::deleteNum(int a, const T& val)
{
    T * tmp = new T[_size];
    for (int i = 0; i < a; i++) {
        tmp[i] = _buf[i];
    }
    for (int i = a; i < size()-1; i++) {
        tmp[i] = _buf[i+1];
    }
    _size--;
    delete[] _buf;
    _buf = tmp;
}


template<class T>
void ArrayList<T>::pop_back()
{
    _size--;
}

template<class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T> & a)
{
    if (this == &a) {
        return *this ;
    }
    delete[] _buf;
    _size = a._size;
    _capacity = a._capacity;
    _buf = new T[_capacity];
    for (int i = 0; i < _size; i++) {
        _buf[i] = a._buf[i];
    }
    return *this;
}

#endif // ARRAY_H
