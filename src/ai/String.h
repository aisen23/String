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
        String& operator=(const char* cStr);

        String& operator+=(const String& other);
        String& operator+=(const char* cStr);
        String& operator+(const char* cStr);

        bool operator<(const String& r) const;
        bool operator>(const String& r) const;

        friend String operator+(const String& s1, const String& s2);

        friend std::ostream& operator<<(std::ostream& os, const String& str);
        friend std::istream& operator>>(std::istream& is, String& str);

        void Reserve(size_t size);
        void Resize(size_t size);
        void Clear();

        char* GetData() const { return _data; }
        size_t Size() const { return _size; }
        size_t Capacity() const { return _capacity; }
        size_t DeltaCapacity() const { return DELTA_CAPACITY; }

        // Debug function.
        void DebugPrint() const;

    private:
        void ClearByMove();

    private:
        const size_t DELTA_CAPACITY = 20;

        char* _data;
        size_t _capacity = 15;
        size_t _size = 0;
    };
} // ai
