#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Assignment03\MaxSubarray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestA03
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestEmpty)
		{
			std::vector<int> a;
			RangeBlock rb = MaxSubArray(a);
			Assert::AreEqual(rb.sum, 0);
			Assert::AreEqual(rb.start, -1);
			Assert::AreEqual(rb.end, -1);
		}
		TEST_METHOD(TestAllNegative)
		{
			std::vector<int> a = { -1,-5,-8,-10,-6,-40,-1630,-5 };
			RangeBlock rb = MaxSubArray(a);
			Assert::AreEqual(rb.sum, 0);
			Assert::AreEqual(rb.start, -1);
			Assert::AreEqual(rb.end, -1);
		}
		TEST_METHOD(TestAllZero)
		{
			std::vector<int> a(10, 0);
			RangeBlock rb = MaxSubArray(a);
			Assert::AreEqual(rb.sum, 0);
			Assert::AreEqual(rb.start, 0);
			Assert::AreEqual(rb.end, 9);
		}
		TEST_METHOD(TestInhaling) // S4ºÍS5
		{
			std::vector<int> a = { 1, 3,-2,-3,0,0,-6,-10 };
			RangeBlock rb = MaxSubArray(a);
			Assert::AreEqual(rb.sum, 4);
			Assert::AreEqual(rb.start, 0);
			Assert::AreEqual(rb.end, 1);
		}
		TEST_METHOD(TestNormal)
		{
			std::vector<int> a = { 1,3,2,-4,0,5,8,-1,-10 };
			RangeBlock rb = MaxSubArray(a);
			Assert::AreEqual(rb.sum, 15);
			Assert::AreEqual(rb.start, 0);
			Assert::AreEqual(rb.end, 6);
		}
		TEST_METHOD(TestOscillating)
		{
			std::vector<int> a = {0, 1,-2,3,-4,5,-6,7 };
			RangeBlock rb = MaxSubArray(a);
			Assert::AreEqual(rb.sum, 7);
			Assert::AreEqual(rb.start, 7);
			Assert::AreEqual(rb.end, 7);
		}
	};
}