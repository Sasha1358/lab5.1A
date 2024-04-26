#include "pch.h"
#include "CppUnitTest.h"
#include "../lab5.1A/Line.h"
#include "../lab5.1A/Line.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest51А
{
	TEST_CLASS(UnitTest51А)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Line line;

			// Act
			std::istringstream input("5.5 10.0");
			input >> line;

			// Assert
			Assert::AreEqual(5.5, line.GetFirst());
			Assert::AreEqual(10.0, line.GetSecond());
		}
	};
}
