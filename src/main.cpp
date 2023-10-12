#include "pch.h"

#include "ai/String.h"
#include "Test.h"

void TestString();

int main()
{
    TestString();

    return 0;
}

void TestString() {
#ifdef DEBUG_BUILD
    ai::Test test;

    test.TestDefaultConstructor();
    test.TestCStringConstructor();
    test.TestCopyConstructor();
    test.TestMoveConstructor();

    test.TestCopyAssignOperator();
    test.TestMoveAssignOperator();

    test.TestSum();
    test.TestConcatenateString();

    test.TestClear();
#endif
}
