#ifdef DEBUG_BUILD

#pragma once

namespace ai
{
    class Test
    {
    public:
        void TestDefaultConstructor() const;
        void TestCStringConstructor() const;
        void TestCopyConstructor() const;
        void TestMoveConstructor() const;

        void TestCopyAssignOperator() const;
        void TestMoveAssignOperator() const;

        void TestSum() const;
        void TestConcatenateString() const;

        void TestClear() const;
    };
} // ai

#endif // DEBUG_BUILD
