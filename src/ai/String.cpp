#include "String.h"

#include <string.h>

namespace ai
{
    size_t min(size_t l, size_t r) {
        return (l < r ? l : r);
    }

    String::String() {
        _capacity = DELTA_CAPACITY;

        _data = static_cast<char*>(malloc(_capacity + 1));
        _data[0] = '\0';
    }
    
    String::~String() {
        free(_data);
    }
        
    String::String(const char* cStr)
        : _size(strlen(cStr))
    {
        _capacity = _size + DELTA_CAPACITY;

        _data = static_cast<char*>(malloc(_capacity + 1));
        memcpy(_data, cStr, _size + 1);
    }
        
    String::String(const String& other)
        : _size(other._size),
        _capacity(other._capacity)
    {
        _data = static_cast<char*>(malloc(_capacity + 1));
        memcpy(_data, other.GetData(), _size + 1);
    }
        
    String::String(String&& other) noexcept {
        _size = other._size;
        _capacity = other._capacity;

        _data = other._data;

        other._capacity = DELTA_CAPACITY;
        other._size = 0;
        other._data = static_cast<char*>(malloc(other._capacity + 1));
        other._data[0] = '\0';
    }

    String& String::operator=(const String& other) {
        if (this == &other) {
            return *this;
        }

        free(_data);

        _size = other._size;
        _capacity = other._capacity;

        _data = static_cast<char*>(malloc(_capacity + 1));
        memcpy(_data, other.GetData(), _size + 1);

        return *this;
    }
        
    String& String::operator=(String&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        
        free(_data);

        _size = other._size;
        _capacity = other._capacity;

        _data = other._data;

        other._capacity = DELTA_CAPACITY;
        other._size = 0;
        other._data = static_cast<char*>(malloc(other._capacity + 1));
        other._data[0] = '\0';

        return *this;
    }

    void String::Resize(size_t newSize) {
        if (newSize > _capacity) {
            _capacity = newSize + DELTA_CAPACITY;
            char* newData = static_cast<char*>(malloc(_capacity + 1));
            memcpy(newData, _data, _size + 1);

            free(_data);
            
            _data = newData;
        }
        else if (newSize < _size) {
            memset(_data + newSize, '\0', 1);
        }

        _size = newSize;
    }

    void String::Reserve(size_t newCapacity) {
        if (newCapacity > _capacity) {
            char* newData = static_cast<char*>(malloc(newCapacity + 1));

            if (_size > 0) {
                memcpy(newData, _data, _size);
                free(_data);
            }

            newData[_size] = '\0';
            _data = newData;

            _capacity = newCapacity;
        }
    }

    std::ostream& operator<<(std::ostream& os, const String& str)
    {
        os << str.GetData();
        return os;
    }
} // ai
