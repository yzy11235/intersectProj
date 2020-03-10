#include "pch.h"
#include "CppUnitTest.h"
#include "../Intersect/Graph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace intersectTest1
{
	TEST_CLASS(intersectTest1)
	{
	public:

		TEST_METHOD(TestMethodPoint1) {
			Point p(0.5, 3);
			Assert::AreEqual(p.getX()== 0.5, true);
			Assert::AreEqual(p.getY()==3, true);
			Point m(0.5, -3);
			Assert::AreNotEqual(p.equal(m), true);
		}

		TEST_METHOD(TestMethodLine1) {
			Line l1(0, 0, 1, 1);
			Line l2(0, 2, 1, 0);
			Line l3(0, -45, 45, 0);
			Line lr(1, 0, 5, 0);
			Line bt(1, 1, 1, 10);
			Assert::AreEqual(l2.getA()== -2, true);
			Assert::AreEqual(l2.getB()== -1, true);
			Assert::AreEqual(l2.getC()==2, true);
			Assert::AreEqual(l2.getslope()==-2, true);
			// parallel
			Assert::AreEqual(l1.isParallel(l3), true);
			Assert::AreEqual(lr.isParallel(bt), false);
			// containsPoint
			Point e(0.5,1);
			Point base(0,0);
			Assert::AreEqual(l2.containsPoint(e), true);
			Assert::AreNotEqual(l1.containsPoint(e), true);
			Assert::AreEqual(l1.containsPoint(base), true);
			// get intersect
			Point inter12((float)2/3,(float)2/3);
			Assert::AreEqual(l1.getIntersect(l2).equal(inter12), true);
			Point inter3lr(45, 0);
			Point inter3tb(1, -44);
			Assert::AreEqual(l3.getIntersect(lr).equal(inter3lr), true);
			// equal
			Assert::AreEqual(l1.equal(l2), false);

		}
	};
}
