#include "pch.h"
#include "CppUnitTest.h"
#include "../PR8.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(TestCheckFirstCharacter_ValidInput)
        {
            string input = "Hello World";
            size_t firstSpacePos;
            CheckFirstCharacter(input, firstSpacePos);
            Assert::AreEqual((size_t)5, firstSpacePos); // Перевіряємо, що позиція пробілу правильна
        }

        TEST_METHOD(TestCheckFirstCharacter_EmptyString)
        {
            string input = "";
            size_t firstSpacePos;
            CheckFirstCharacter(input, firstSpacePos);
            Assert::AreEqual((size_t)string::npos, firstSpacePos); // Позиція пробілу має бути npos
        }

        TEST_METHOD(TestCheckFirstCharacter_FirstCharacterSpace)
        {
            string input = " Hello World";
            size_t firstSpacePos;
            CheckFirstCharacter(input, firstSpacePos);
            Assert::AreEqual((size_t)string::npos, firstSpacePos); // Позиція пробілу має бути npos
        }

        TEST_METHOD(TestConvertToUpper)
        {
            string input = "hello world";
            size_t firstSpacePos = 5; // Позиція пробілу
            ConvertToUpper(input, firstSpacePos);
            Assert::AreEqual(string("HELLO world"), input); // Перевіряємо результат
        }

        TEST_METHOD(TestConvertToUpper_NoLowerCase)
        {
            string input = "HELLO WORLD";
            size_t firstSpacePos = 5; // Позиція пробілу
            ConvertToUpper(input, firstSpacePos);
            Assert::AreEqual(string("HELLO WORLD"), input); // Перевіряємо, що рядок не змінився
        }

        TEST_METHOD(TestConvertToUpper_EmptyString)
        {
            string input = "";
            size_t firstSpacePos = 0; // Позиція пробілу
            ConvertToUpper(input, firstSpacePos);
            Assert::AreEqual(string(""), input); // Рядок залишається пустим
        }
    };
}
