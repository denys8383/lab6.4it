#include "pch.h"
#include "CppUnitTest.h"
#include "../Project6.4/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64
{
	TEST_CLASS(UnitTest64)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double Array[] = { 1, -2, 3, -4 };
			double result = Sum(Array, 5);
			Assert::AreEqual(1, 1);

		}
	};
}
