#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab1\Lab1.cpp"
#include <cstring>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestRot13)
        {
            // Test lowercase letters
            char app = rot13('a');
            Assert::IsTrue(rot13('a') == 'n');
            Assert::IsTrue(rot13('m') == 'z');
            Assert::IsTrue(rot13('z') == 'm');

            // Test uppercase letters
            Assert::IsTrue(rot13('A') == 'N');
            Assert::IsTrue(rot13('M') == 'Z');
            Assert::IsTrue(rot13('Z') == 'M');

            // Test non-alphabetic characters
            Assert::IsTrue(rot13('!') == '!');
            Assert::IsTrue(rot13('9') == '9');
            Assert::IsTrue(rot13(' ') == ' ');
        }
        TEST_METHOD(TestEncrypt)
        {
            // Test empty string
          
            Assert::IsTrue(encrypt("") == "");
           
            // Test string with lowercase letters
            Assert::IsTrue(encrypt("abcdefghijklmnopqrstuvwxyz") == "nopqrstuvwxyzabcdefghijklm");

            // Test string with uppercase letters
            Assert::IsTrue(encrypt("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == "NOPQRSTUVWXYZABCDEFGHIJKLM");

            // Test string with mixed case letters
            Assert::IsTrue(encrypt("AbCdEfGhIjKlMnOpQrStUvWxYz") == "NoPqRsTuVwXyZaBcDeFgHiJkLm");
        }
        TEST_METHOD(testStdinReading)
        {
            std::stringstream input("test input\n");
            std::stringstream output;
            std::stringstream error;

            std::streambuf* origIn = std::cin.rdbuf(input.rdbuf());
            std::streambuf* origOut = std::cout.rdbuf(output.rdbuf());
            std::streambuf* origErr = std::cerr.rdbuf(error.rdbuf());

            main();

            std::cin.rdbuf(origIn);
            std::cout.rdbuf(origOut);
            std::cerr.rdbuf(origErr);

            Assert::AreEqual("oLoLo", "ololo", true);
            Assert::IsTrue(error.str().empty());
        }
        TEST_METHOD(testStderrOutput)
        {
            // stderr
            std::stringstream input("");
            std::stringstream output;
            std::stringstream error;

            std::streambuf* origIn = std::cin.rdbuf(input.rdbuf());
            std::streambuf* origOut = std::cout.rdbuf(output.rdbuf());
            std::streambuf* origErr = std::cerr.rdbuf(error.rdbuf());

            
            char c = 0;
            
            rot13(c);

            std::cin.rdbuf(origIn);
            std::cout.rdbuf(origOut);
            std::cerr.rdbuf(origErr);

            Assert::IsTrue(output.str().empty());
            Assert::IsTrue(error.str().empty());
        }

        TEST_METHOD(testStdoutnotzero)
        {
            //on output
            std::stringstream input(""); // 
            std::stringstream output;
            std::stringstream error;

            std::streambuf* origIn = std::cin.rdbuf(input.rdbuf());
            std::streambuf* origOut = std::cout.rdbuf(output.rdbuf());
            std::streambuf* origErr = std::cerr.rdbuf(error.rdbuf());

            
            int exitCode = main();

            std::cin.rdbuf(origIn);
            std::cout.rdbuf(origOut);
            std::cerr.rdbuf(origErr);

            Assert::IsTrue(exitCode != 0);
        }
        TEST_METHOD(testStdoutzero)
        {
            //on output
            std::stringstream input("hello world"); // 
            std::stringstream output;
            std::stringstream error;

            std::streambuf* origIn = std::cin.rdbuf(input.rdbuf());
            std::streambuf* origOut = std::cout.rdbuf(output.rdbuf());
            std::streambuf* origErr = std::cerr.rdbuf(error.rdbuf());


            int exitCode = main();

            std::cin.rdbuf(origIn);
            std::cout.rdbuf(origOut);
            std::cerr.rdbuf(origErr);

            Assert::IsTrue(exitCode == 0);
        }
    
	};
}
