#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <cstdio>
#include "../Project6/FileName.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestProcessNegativeSums)
        {
            const char* inFile = "test_input.txt";
            const char* outFile = "test_output.txt";

            {
                std::ofstream fout(inFile);
                fout << 5 << " " << -2 << " " << 3 << " " << -4 << " " << -1;
            }

            processNegativeSums(inFile, outFile);

            std::ifstream fin(outFile);
            int results[3];
            for (int i = 0; i < 3; ++i)
            {
                fin >> results[i];
            }

            int expected[] = { -2, -6, -7 };

            for (int i = 0; i < 3; ++i)
            {
                Assert::AreEqual(expected[i], results[i], L"Mismatch at index");
            }

            std::remove(inFile);
            std::remove(outFile);
        }
    };
}
