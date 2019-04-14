#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Assignments02\Vec.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestA02
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestConstruct)
		{
			Vector2 v0;
			Vector2 v1(3, 4);
			Assert::AreEqual(v0.x, 0.0f, FLT_EPSILON);
			Assert::AreEqual(v1.x, 3.0f, FLT_EPSILON);
			Assert::AreEqual(v1.y, 4.0f, FLT_EPSILON);
		}

		TEST_METHOD(TestMemberFunc)
		{
			Vector2 v;
			float realdir = NAN;
			Assert::IsTrue(v.IsZero());
			Assert::IsTrue(isnan(v.DirRad()));
			Assert::AreEqual(v.Length(), 0.0f, FLT_EPSILON);
			Assert::IsFalse(v.Unit().IsValid());
			v = { 3,4 };
			realdir = atan2(4, 3);
			Assert::IsFalse(v.IsZero());
			Assert::AreEqual(v.Length(), 5.0f, FLT_EPSILON);
			Assert::IsTrue(v.IsValid());
			Assert::AreEqual(v.DirRad(), atan2f(4,3), FLT_EPSILON);
			Assert::AreEqual(v.Unit().x, 3.0f / 3.0f*cosf(atan2f(4, 3)), FLT_EPSILON);
			Assert::AreEqual(v.Unit().y, 4.0f / 4.0f*sinf(atan2f(4, 3)), FLT_EPSILON);
			Assert::IsFalse(v.IsNormalized());
			v.Normalize();
			Assert::IsTrue(v.IsValid());
			Assert::AreEqual(v.DirRad(), realdir, FLT_EPSILON);
			Assert::IsTrue(v.IsNormalized());
			Assert::AreEqual(v.x, v.Unit().x, FLT_EPSILON);
			Assert::AreEqual(v.y, v.Unit().y, FLT_EPSILON);
		}

		TEST_METHOD(TestOperation)
		{
			Vector2 v0(2.0f, 4.0f);
			Vector2 v1(-5.0f, 7.0f);
			Vector2 vres;
			float fres = 0.0f;
			vres = v0 + v1;
			Assert::AreEqual(vres.x, v0.x + v1.x, FLT_EPSILON);
			Assert::AreEqual(vres.y, v0.y + v1.y, FLT_EPSILON);
			vres = v0 - v1;
			Assert::AreEqual(vres.x, v0.x - v1.x, FLT_EPSILON);
			Assert::AreEqual(vres.y, v0.y - v1.y, FLT_EPSILON);
			vres = v0 * 2;
			Assert::AreEqual(vres.x, 4.0f, FLT_EPSILON);
			Assert::AreEqual(vres.y, 8.0f, FLT_EPSILON);
			vres = v0 / 2;
			Assert::AreEqual(vres.x, 1.0f, FLT_EPSILON);
			Assert::AreEqual(vres.y, 2.0f, FLT_EPSILON);
			fres = DotProd(v0, v1);
			Assert::AreEqual(fres, 18.0f, FLT_EPSILON);
			fres = v0 ^ v1;
		}

	};
}