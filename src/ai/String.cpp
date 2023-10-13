#include "String.h"

#include <string.h>

namespace ai
{
    size_t min(size_t l, size_t r) {
        return (l < r ? l : r);
    }

    size_t max(size_t l, size_t r) {
        return (l > r ? l : r);
    }

    String::String() {
        _capacity = DELTA_CAPACITY;

        _data = static_cast<char*>(malloc(_capacity + 1));
        _data[0] = '\0';
    }
    
    String::~String() {
        free(_data);
    }

    void String::Clear() {
        if (_capacity == DELTA_CAPACITY && _size == 0 && _data[0] == '\0') {
            return;
        }

        free(_data);
        _data = static_cast<char*>(malloc(1));
        _data[0] = '\0';
        _size = 0;
        _capacity = DELTA_CAPACITY;
    }

    void String::ClearByMove() {
        if (_capacity == DELTA_CAPACITY && _size == 0 && _data[0] == '\0') {
            return;
        }

        _size = 0;
        _capacity = DELTA_CAPACITY;
        _data = static_cast<char*>(malloc(_capacity + 1));
        _data[_size] = '\0';
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
        
    String::String(String&& other) noexcept 
        : _size(other._size),
        _capacity(other._capacity),
        _data(other._data)
    {
        other.ClearByMove();
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

        other.ClearByMove();

        return *this;
    }

    String& String::operator=(const char* cStr) {
        free(_data);

        _size = strlen(cStr);
        _capacity = _size + DELTA_CAPACITY;

        _data = static_cast<char*>(malloc(_capacity + 1));
        memcpy(_data, cStr, _size + 1);

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

    String& String::operator+=(const String& other) {
        size_t newSize = _size + other._size;

        if (newSize > _capacity - 1) {
            _capacity = newSize + DELTA_CAPACITY;
            char* newData = static_cast<char*>(malloc(_capacity + 1));
            memcpy(newData, _data, _size + 1);

            free(_data);
            _data = newData;
        }

        memcpy(_data + _size, other.GetData(), other.Size() + 1);
        _size = newSize;

        return *this;
    }

    String& String::operator+=(const char* cStr) {
        size_t strLen = strlen(cStr);
        size_t newSize = _size + strLen;

        if (newSize > _capacity - 1) {
            _capacity = newSize + DELTA_CAPACITY;
            char* newData = static_cast<char*>(malloc(_capacity + 1));
            memcpy(newData, _data, _size + 1);

            free(_data);
            _data = newData;
        }

        memcpy(_data + _size, cStr, strLen + 1);
        _size = newSize;

        return *this;
    }
    
    String& String::operator+(const char* cStr) {
        size_t strLen = strlen(cStr);
        size_t newSize = _size + strLen;

        if (newSize > _capacity - 1) {
            _capacity = newSize + DELTA_CAPACITY;
            char* newData = static_cast<char*>(malloc(_capacity + 1));
            memcpy(newData, _data, _size + 1);

            free(_data);
            _data = newData;
        }

        memcpy(_data + _size, cStr, strLen + 1);
        _size = newSize;

        return *this;
    }
    
    bool String::operator<(const String& other) const {
        return std::strcmp(_data, other._data) < 0;
    }
    
    bool String::operator>(const String& other) const {
        return std::strcmp(_data, other._data) > 0;
    }


    std::ostream& operator<<(std::ostream& os, const String& str)
    {
        os << str.GetData();
        return os;
    }

    std::istream& operator>>(std::istream& is, String& str) {
        const size_t MAX_LEN = 1024;
        char buffer[MAX_LEN];

        is >> buffer;

        size_t length = strlen(buffer);

        if (length >= MAX_LEN) {
            throw std::runtime_error("Input Error: Buffer overflow detected.");
        }

        char* data = new char[MAX_LEN + 1];

        strncpy(data, buffer, length);
        data[length] = '\0';

        str = data;

        free(data);

        return is;
    } 
    
    ai::String operator+(const String& s1, const String& s2) {
        size_t capacity = max(s1.Capacity(), s2.Capacity());
        size_t newSize = s1.Size() + s2.Size();
        if (newSize > capacity - 1) {
            capacity = newSize + s1.DeltaCapacity();
        }

        String res;
        res.Reserve(capacity);

        res += s1;
        res += s2;

        return res;
    }

    void String::DebugPrint() const {
#ifdef DEBUG_BUILD
        std::cout << "Data: " << _data << "\nsize: " << _size << "\ncapacity: " << _capacity << "\n\n";
#endif // DEBUG_BUILD
    }
} // ai
