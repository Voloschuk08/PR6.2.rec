#include "pch.h"
#include "CppUnitTest.h"

#include "../PR6.2/PR6.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62
{
	TEST_CLASS(UnitTest62)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			int a[]= { 10, -20, 15, 30, 0 };
			int i = 0;
			int n = 0;
			int  minIdx = -3;
			int find = findMinInd(a, n, i, minIdx);
			Assert::AreEqual(find, -3);
		}
	};
}
