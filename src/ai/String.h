#pragma once

#include <iostream>

namespace ai
{
    class String
    {
    public:
        String();
        ~String();

        String(const char* cStr);
        String(const String& other);
        String(String&& other) noexcept;

        String& operator=(const String& other);
        String& operator=(String&& other) noexcept;

        friend String operator+(const String& s1, const String& s2) {};
        friend std::ostream& operator<<(std::ostream& os, const String& str);

        void Reserve(size_t size);
        void Resize(size_t size);
        void Clear();

        char* GetData() const { return _data; }

    private:
        const size_t DELTA_CAPACITY = 29;

        char* _data;
        size_t _capacity = 15;
        size_t _size = 0;
    };
} // ai
