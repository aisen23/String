#include "pch.h"

#include "ai/String.h"
#include "Test.h"

void TestString();

struct CompareForExample {
    bool operator()(const ai::String& a, const ai::String& b) const;
};

int main()
{
    TestString();

    std::priority_queue<ai::String, std::vector<ai::String>, CompareForExample> sortedQueue;

    size_t N = 0;
    std::cout << "Enter number of strings: ";
    std::cin >> N;

    while (N == 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Enter a valid number more than 0: ";
        std::cin >> N;
    }

    std::cout << "\nEnter strings via new lines:\n";

    for (size_t i = 0; i < N; ++i) {
        ai::String str;

        try {
            std::cin >> str;
        }
        catch(std::exception e) {
            std::cerr << e.what() << std::endl;

            return EXIT_FAILURE;
        }
        sortedQueue.push(std::move(str));
    }

    std::cout << "\n\nDescending order of strings:\n";
    while (!sortedQueue.empty()) {
        auto str = std::move(sortedQueue.top());
        sortedQueue.pop();

        std::cout << str << "\n";
    }

    std::cout << "\n\n";

    system("pause");

    return EXIT_SUCCESS;
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

void ToLower(char& c) {
    if (isalpha(c)) {
        c = std::tolower(c);
    }
}

bool CompareForExample::operator()(const ai::String& a, const ai::String& b) const {
    size_t len1 = a.Size();
    size_t len2 = b.Size();

    char* str1 = new char[len1 + 1];
    memcpy(str1, a.GetData(), len1 + 1);

    char* str2 = new char[len2 + 1];
    memcpy(str2, b.GetData(), len2 + 1);

    while (*str1 != '\0' && *str2 != '\0') {
        ToLower(*str1);
        ToLower(*str2);

        if (*str1 != *str2) {
            int diff = *str1 - *str2;
            return diff < 0;
        }

        str1++;
        str2++;
    }

    ToLower(*str1);
    ToLower(*str2);

    int diff = *str1 - *str2;

    return diff < 0;
}
