#ifndef _STRING_H
#define _STRING_H

#define di __declspec( dllimport )

#include "_string_global.h"

#include <iostream>

#include <cstring>

class _STRING_EXPORT _string
{
private:

    enum {
        our_capacity = 16,
        our_size = our_capacity - 1
    };

    char* str;
    size_t len;

    union {
        size_t capacity;
        char data[our_capacity];

    } our;

    void init(size_t length);

    void resize(size_t new_capacity);

    _string(size_t length, void* value);

    _string(size_t length, size_t capacity);

public:
    _string();

    _string(decltype(nullptr));

    _string(const char* value);

    _string(const char* value, size_t length);


    ~_string();

    size_t size();

    size_t length();

    _string(_string const& other);

    _string& operator = (_string const& other);

    _string(_string&& other);

    _string& operator = (_string&& other) noexcept;

    int begin();

    int end();

    void swap(_string& str1, _string& str2);

    void reverse(int first_position, int last_position);

    const char* c_str() const;

    bool empty() const;

    operator const char* ();

    char& operator [] (int pos);

    bool operator ! ();

    explicit operator bool() {
        return len != 0;
    }

    bool operator == (const char* value);

    bool operator != (const char* value);

    bool operator == (_string value);

    void insert(int pos, _string& value);

    void insert(int pos, char value);

//    template <typename T>
//    void insert(int pos, T const& value) {

//        insert(pos, _string(value));
//    }

    void append(_string const& value);

    void append(char value);

    void push_back(const char value);

    void pop_back();

    template <typename T>
    void append(T const& value) {
        append(_string(value));
    }

    inline _string& operator += (_string const& value);

    inline _string& operator += (const char* value);

    template <typename T>
    _string& operator += (T const& value) {
        append(_string(value));
        return *this;
    }

    void erase(int position, int amount);

    void remove(int position);

    _string friend operator + (_string const& left, _string const& right) {

        size_t new_len = left.len + right.len;

        _string s(new_len, new_len + 1);

        memcpy(s.str, left.c_str(), left.len);
        memcpy(&s.str[left.len], right.c_str(), right.len);

        s.str[new_len] = '\0';

        return s;
    }

    _string friend operator + (_string&& left, _string const& right) {


            size_t new_len = left.len + right.len;

            left.resize(new_len + 1);

            memcpy(&left.str[left.len], right.c_str(), right.len);

           left.len = new_len;

            left.str[new_len] = '\0';

            return std::move(left);

    }

    template <typename T>
    _string friend operator + (_string const& left, T const& right) {

        return left + _string(right);
    }

    template <typename T>
    _string friend operator + (T const& left, const _string& right) {

        return _string(left) + right;
    }


    template <typename T>
    _string friend operator + (_string&& left, T const& right) {

        return std::forward<_string>(left) + _string(right);
    }

    _string friend operator + (_string const& left, const char* right) {

        size_t right_len = strlen(right);

        size_t new_len = left.len + right_len;

        _string s(new_len, new_len + 1);

        memcpy(s.str, left.c_str(), left.len);
        memcpy(&s.str[left.len], right, right_len);

        s.str[new_len] = '\0';

        return s;
    }


    _string friend operator + (const char* left, _string const& right) {

        size_t left_len = strlen(left);

        size_t new_len = left_len + right.len;

        _string s(new_len, new_len + 1);

        memcpy(s.str, left, left_len);
        memcpy(&s.str[left_len], right.c_str(), right.len);

        s.str[new_len] = '\0';

        return s;
    }

    _string friend operator + (_string&& left, const char* right) {

        size_t right_len = strlen(right);

        size_t new_len = left.len + right_len;

        left.resize(new_len + 1);

        memcpy(&left.str[left.len], right, right_len);

        left.len = new_len;

        left.str[new_len] = '\0';

        return std::move(left);
    }
};

#endif // _STRING_H
