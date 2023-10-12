#include "pch.h"

#include "ai/String.h"
#include "Test.h"

int main()
{
    ai::Test test;

    test.TestDefaultConstructor();
    test.TestCStringConstructor();
    test.TestCopyConstructor();
    test.TestMoveConstructor();

    test.TestCopyAssignOperator();
    test.TestMoveAssignOperator();

    test.TestSum();
    test.TestConcatenateString();

    return 0;
}
