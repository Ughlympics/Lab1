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
            std::string a;
            Assert::IsTrue(encrypt("") == "");
            Assert::
            // Test string with lowercase letters
            Assert::IsTrue(encrypt("abcdefghijklmnopqrstuvwxyz") == "nopqrstuvwxyzabcdefghijklm");

            // Test string with uppercase letters
            Assert::IsTrue(encrypt("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == "NOPQRSTUVWXYZABCDEFGHIJKLM");

            // Test string with mixed case letters
            Assert::IsTrue(encrypt("AbCdEfGhIjKlMnOpQrStUvWxYz") == "NoPqRsTuVwXyZaBcDeFgHiJkLm");
        }
    
	};
}
