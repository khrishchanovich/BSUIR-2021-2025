#include "_string.h"

void _string::init(size_t length) {
    len = length;
    if (length > our_size) {
        size_t capacity = length + 1;

        our.capacity = capacity;
        our.data[our_size] = '\1';

        str = (char*)malloc(capacity);
    }
    else {
        our.data[our_size] = '\0';
        str = our.data;
    }
}

void _string::resize(size_t new_capacity) {

    if (our.data[our_size] == '\1') {

        if (new_capacity > our.capacity) {
            our.capacity = new_capacity;
            str = (char*)realloc(str, new_capacity);
        }

    }
    else {
        if (new_capacity > our_size) {

            char* new_str = (char*)malloc(new_capacity);

            memcpy(new_str, str, len + 1);

            str = new_str;

            our.data[our_size] = '\1';

            our.capacity = new_capacity;

        }

    }
}

_string::_string(size_t length, void* value) : str((char*)value), len(length) {}

_string::_string(size_t length, size_t capacity) {

    len = length;
    if (capacity > our_capacity) {
        str = (char*)malloc(capacity);
        our.capacity = capacity;
        our.data[our_size] = '\1';
    }
    else {
        str = our.data;
        our.data[our_size] = '\0';
    }
}

_string::_string() {
    str = our.data;
    len = 0;
    our.data[0] = '\0';
    our.data[our_size] = '\0';
}

_string::_string(decltype(nullptr)) {
    str = our.data;
    len = 0;
    our.data[0] = '\0';
    our.data[our_size] = '\0';
}

_string::~_string() {
    if (our.data[our_size] == '\1') {
        //std::free(str);
    }
}

_string::_string(const char* value) {
    if (value == nullptr) {
        len = 0;
        our.data[0] = '\0';
        our.data[15] = '\0';

    }
    else {
        init(strlen(value));
        memcpy(str, value, len);

    }
}

_string::_string(const char* value, size_t length) {
        init(length);
        memcpy(str, value, len);
    }

size_t _string::size() {
    return len;
}

size_t _string::length() {
        return len;
    }

_string::_string(_string const& other) {

    if (other.our.data[our_size] == '\1') {
        len = other.len;
        our.capacity = len + 1;
        our.data[our_size] = '\1';

        str = (char*)malloc(our.capacity);
        memcpy(str, other.str, our.capacity);
    }
    else {
        str = our.data;
        len = other.len;
        memcpy(&our.data, &other.our.data, len + 1);
        our.data[our_size] = '\0';
    }

}

_string& _string::operator = (_string const& other) {

    if (other.our.data[our_size] == '\1') {
        len = other.len;
        our.capacity = len + 1;
        our.data[our_size] = '\1';

        str = (char*)malloc(our.capacity);
        memcpy(str, other.str, our.capacity);
    }
    else {
        str = our.data;
        len = other.len;
        memcpy(&our.data, &other.our.data, len + 1);
        our.data[our_size] = '\0';
    }

    return *this;

}

_string::_string(_string&& other) {

    if (other.our.data[our_size] == '\1') {
        len = other.len;
        our.capacity = other.our.capacity;
        our.data[our_size] = '\1';

        str = other.str;
        other.our.data[our_size] = '\0';
    }
    else {
        str = our.data;
        len = other.len;
        memcpy(&our.data, &other.our.data, len + 1);
        our.data[our_size] = '\0';
    }

}

_string& _string::operator = (_string&& other) noexcept {
    if (this != &other) {
        if (other.our.data[our_size] == '\1') {
            len = other.len;
            our.capacity = other.our.capacity;
            our.data[our_size] = '\1';

            str = other.str;
            other.our.data[our_size] = '\0';
        }
        else {
            str = our.data;
            len = other.len;
            memcpy(&our.data, &other.our.data, len + 1);
            our.data[our_size] = '\0';
        }
    }
    return *this;
}

int _string::begin() {
    return 0;
}

int _string::end() {
    return len - 1;
}

void _string::swap(_string& str1, _string& str2) {
    _string temp = str1;
    str1 = str2;
    str2 = temp;
}

void _string::reverse(int first_position, int last_position) {

    _string temp = str;
    for (int i = last_position; i >= first_position; --i) {
        str[i] = temp[last_position - i + first_position];
    }

}

const char* _string::c_str() const {
    return str;
}

bool _string::empty() const {
    return !len;
}

char& _string::operator [] (int pos) {

    return str[pos];
}

bool _string::operator ! () {
    return len == 0;
}

bool _string::operator == (const char* value) {
    return strcmp(str, value) == 0;
}

bool _string::operator != (const char* value) {
    return strcmp(str, value) != 0;
}

bool _string::operator == (_string value) {
    return len == value.len && strcmp(str, value.str) == 0;
}

void _string::insert(int pos, _string& value) {

    size_t new_len = len + value.len;
    resize(new_len + 1);

    memmove(&str[pos + value.len], &str[pos], len - pos);
    memcpy(&str[pos], value.str, value.len);

    str[new_len] = '\0';

    len = new_len;
}

void _string::insert(int pos, char value) {

    size_t value_len = 1;
    size_t new_len = len + value_len;

    resize(new_len + 1);

    _string Value = "a";
    Value[0] = value;

    memmove(&str[pos + value_len], &str[pos], len - pos);
    memcpy(&str[pos], Value.c_str(), value_len);

    str[new_len] = '\0';

    len = new_len;
}


void _string::append(_string const& value)
{

    size_t new_len = len + value.len;
    resize(new_len + 1);

    memcpy(&str[len], value.str, value.len);

    str[new_len] = '\0';

    len = new_len;
}

void _string::append(char value)
{

    size_t value_len = 1;
    size_t new_len = len + value_len;
    resize(new_len + 1);
    _string Value = "a";
    Value[0] = value;

    memcpy(&str[len], Value.c_str(), value_len);

    str[new_len] = '\0';

    len = new_len;
}

void _string::push_back(const char value)
{
    append(value);
}

void _string::pop_back()
{
    erase(len - 1, 1);
}

inline _string& _string::operator += (_string const& value)
{
    append(value);
    return *this;
}

inline _string& _string::operator += (const char* value)
{
    append(value);
    return *this;
}

void _string::erase(int position, int amount)
{
    int new_len = len - amount;

    memmove(&str[position], &str[position + amount], len - position - amount);

    str[new_len] = '\0';
    len = new_len;
}

void _string::remove(int position)
{
    erase(position, 1);
}
