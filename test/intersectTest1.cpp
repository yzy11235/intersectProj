#include "pch.h"
#include "CppUnitTest.h"
#include "../Intersect/Graph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace intersectTest1
{
	TEST_CLASS(intersectTest1)
	{
	public:
		
		TEST_METHOD(TestMethodRadio1) {
			// basic test;
			// chech Radio() & gcd;
			Radio a(4,2);
			Assert::AreEqual(a.getNum(), 2);
			Assert::AreEqual(a.getDen(), 1);
			Radio b(100, 50);
			// check equal
			Assert::AreEqual(a.equal(b), true);
			Radio c(99, 99);
			Assert::AreEqual(c.getNum(), 1);
			Assert::AreEqual(c.getDen(), 1);
			Radio zero(0, 1);
			Assert::AreEqual(zero.equal(Radio(0, 100)), true);
			// minus
			Radio d(100, -100);
			Assert::AreEqual(d.getNum(), 1);
			Assert::AreEqual(d.getDen(), -1);
			Radio e(-600, 600);
			Assert::AreEqual(d.equal(e), true);
			Assert::AreNotEqual(c.equal(e), true);
		}

		TEST_METHOD(TestMethodRadio2) {
			// basic algorithm
			Radio a(4, 2);	// 2
			Radio b(100, 50);	//2
			Radio c(100000, 100000);	// 1
			Radio d(100000, -100000);	// -1
			Radio e(-1, 2);		// -1/2
			Radio zero(0, 1000);
			Assert::AreEqual(c.add(d).equal(zero), true);
			Assert::AreEqual(a.sub(b).equal(zero), true);
			Assert::AreEqual(a.mul(e).equal(d), true);
			Assert::AreEqual(c.mul(d).equal(d), true);
			Assert::AreEqual(a.div(e).div(a).div(b).equal(d), true);
		}

		TEST_METHOD(TestMethoddRadio3) {
			Radio a(4, 7);
			Radio b(2, 3);
			Assert::AreEqual(a.add(b).equal(Radio(26, 21)), true);
			Assert::AreEqual(a.sub(b).equal(Radio(2, -21)), true);
			Assert::AreEqual(a.mul(b).equal(Radio(8, 21)), true);
			Assert::AreEqual(a.div(b).equal(Radio(6, 7)), true);
		}

		TEST_METHOD(TestMethodPoint1) {
			Radio x(1, 2);
			Radio y(9, 3);
			Point p(x, y);
			Assert::AreEqual(p.getX().equal(Radio(1, 2)), true);
			Assert::AreEqual(p.getY().equal(Radio(27, 9)), true);
			Point q(Radio(1, 2), Radio(30, 10));
			Assert::AreEqual(p.equal(q), true);
			Point m(Radio(1, 2), Radio(-30, 10));
			Assert::AreNotEqual(p.equal(m), true);
		}

		TEST_METHOD(TestMethodLine1) {
			Line l1(0, 0, 1, 1);
			Line l2(0, 2, 1, 0);
			Line l3(0, -45, 45, 0);
			Line lr(1, 0, 5, 0);
			Line bt(1, 1, 1, 10);
			Assert::AreEqual(l2.getA().equal(Radio(-2, 1)), true);
			Assert::AreEqual(l2.getB().equal(Radio(-1, 1)), true);
			Assert::AreEqual(l2.getC().equal(Radio(2, 1)), true);
			Assert::AreEqual(l2.getslope().equal(Radio(-2, 1)), true);
			// parallel
			Assert::AreEqual(l1.isParallel(l3), true);
			Assert::AreEqual(lr.isParallel(bt), false);
			// containsPoint
			Point e(Radio(1, 2), Radio(1, 1));
			Point base(Radio(0, 1), Radio(0, 1));
			Assert::AreEqual(l2.containsPoint(e), true);
			Assert::AreNotEqual(l1.containsPoint(e), true);
			Assert::AreEqual(l1.containsPoint(base), true);
			// get intersect
			Point inter12(Radio(2, 3), Radio(2, 3));
			Assert::AreEqual(l1.getIntersect(l2).equal(inter12), true);
			Point inter3lr(Radio(45, 1), Radio(0, 1));
			Point inter3tb(Radio(1, 1), Radio(-44, 1));
			Assert::AreEqual(l3.getIntersect(lr).equal(inter3lr), true);
			// equal
			Assert::AreEqual(l1.equal(l2), false);

		}
	};
}
