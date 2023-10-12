#ifdef DEBUG_BUILD

#include "pch.h"

#include "Test.h"

#include "ai/String.h"

namespace ai
{
    void Test::TestDefaultConstructor() const {
        std::cout << "Test default constructor: " << std::endl;

        String str;
        str.DebugPrint();

        std::cout << "\n\n";
    }
    
    void Test::TestCStringConstructor() const {
        std::cout << "Test c string constructor: " << std::endl;

        String str1("Hello! I am c-string!");
        str1.DebugPrint();

        String str2("Hello! I am long c-string! Bla-bla-bla-bla-bla-bla-bla-bla-bla-bla-bla-bla-bla-bla-bla-bla-bla-bla-bla-bla-bla-bla-bla-bla-bla");
        str2.DebugPrint();

        std::cout << "\n\n";
    }

    void Test::TestCopyConstructor() const {
        std::cout << "Test copy constructor: " << std::endl;

        String src("The source string!");
        std::cout << "Source string before copy:\n";
        src.DebugPrint();

        String copy = src;
        std::cout << "Source string after copy:\n";
        src.DebugPrint();

        std::cout << "Copy of string:\n";
        copy.DebugPrint();

        std::cout << "\n\n";
    }

    void Test::TestMoveConstructor() const {
        std::cout << "Test move constructor: " << std::endl;

        std::cout << "Move temp string:\n";
        {
            String copy = "Long temp string, long temp string, long temp string, long temp string, long temp string";
            std::cout << "Copy of string:\n";
            copy.DebugPrint();
        }

        std::cout << "Move source string:\n";
        {
            String src = "Another string. Another string. Another string. Another string. Another string.. Another string.. Another string.";
            std::cout << "Source string before moving:\n";
            src.DebugPrint();

            String copy = std::move(src);
            std::cout << "Source string after moving:\n";
            src.DebugPrint();

            std::cout << "Copy of string:\n";
            copy.DebugPrint();
        }

        std::cout << "\n\n";
    }

    void Test::TestCopyAssignOperator() const {
        std::cout << "Test copy assign operator: " << std::endl;

        String src("The long source string. The long source string. The long source string. The long source string. The long source string.");
        std::cout << "Source string before copy:\n";
        src.DebugPrint();

        String copy;
        copy = src;
        std::cout << "Source string after copy:\n";
        src.DebugPrint();

        std::cout << "Copy of string:\n";
        copy.DebugPrint();


        src = "The source string!";
        std::cout << "Source string before copy:\n";
        src.DebugPrint();

        copy = src;
        std::cout << "Source string before copy:\n";
        src.DebugPrint();

        std::cout << "Copy of string:\n";
        copy.DebugPrint();

        std::cout << "\n\n";
    }

    void Test::TestMoveAssignOperator() const {
        std::cout << "Test move assign operator: " << std::endl;

        String src("The long source string. The long source string. The long source string. The long source string. The long source string.");
        std::cout << "Source string before move:\n";
        src.DebugPrint();

        String moved("Hello!");
        std::cout << "Moved before move:\n";
        moved.DebugPrint();

        moved = std::move(src);
        std::cout << "Source string after move:\n";
        src.DebugPrint();

        std::cout << "Moved string:\n";
        moved.DebugPrint();


        src = "The source string!";
        std::cout << "New source string:\n";
        src.DebugPrint();

        moved = std::move(src);
        std::cout << "Source string after move:\n";
        src.DebugPrint();

        std::cout << "Moved string:\n";
        moved.DebugPrint();

        moved = "Temp string. Temp String. Temp String";
        std::cout << "Move temp string:\n";
        moved.DebugPrint();

        std::cout << "\n\n";
    }

    void Test::TestSum() const {
        //std::cout << "Test sum of two strings:\n";

        //String str1("The first string.");
        //std::cout << "1:\n";
        //str1.DebugPrint();

        //String str2("Hello!");
        //std::cout << "2:\n";
        //str2.DebugPrint();

        //auto sum = str1 + str2;
        //std::cout << "Sum:\n";
        //sum.DebugPrint();


        //str1.Clear();
        //std::cout << "1:\n";
        //str1.DebugPrint();

        ///*str2 = "Hello, Brooooooooooooooooooooooooooo!";
        //std::cout << "2:\n";
        //str2.DebugPrint();*/

        //sum = str1 + str2;
        //std::cout << "Sum:\n";
        //sum.DebugPrint();


        ///*str1 = "Hello, Bro!";
        //std::cout << "1:\n";
        //str1.DebugPrint();

        //str2 = "";
        //std::cout << "2:\n";
        //str2.DebugPrint();*/

        //sum = str1 + str2;
        //std::cout << "Sum:\n";
        //sum.DebugPrint();

        //std::cout << "\n\n";
    }
    
    void Test::TestConcatenateString() const {
       // std::cout << "Test sum of two strings:\n";

       // String str1("Hello, Broooo!");
       // std::cout << "Str1:\n";
       // str1.DebugPrint();

       // String str2(" Hello, Sister!");
       // std::cout << "Str2:\n";
       // str2.DebugPrint();

       ///* str1 += str2;
       // std::cout << "Str1 after concatenate:\n";
       // str1.DebugPrint();

       // str1 += " Hello, Daddy!";
       // std::cout << "Str1:\n";
       // str1.DebugPrint();*/

       // std::cout << "\n\n";
    }
} // ai

#endif // DEBUG_BUILD
