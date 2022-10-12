#include "pch.h"
#include "../Tick-tack-toe/TickTackToe.cpp"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TDD
{
	TEST_CLASS(TDD)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string out = game("2 2 1 1 3 2 1 2 1 3 3 1 2 1 2 3 3 3");
			string need = "...\n...\n...\n...\n.X.\n...\nO..\n.X.\n...\nO..\n.X.\n.X.\nOO.\n.X.\n.X.\nOOX\n.X.\n.X.\nOOX\n.X.\nOX.\nOOX\nXX.\nOX.\nOOX\nXXO\nOX.\nOOX\nXXO\nOXX\nTIE";
			Assert::AreEqual(out, need);
		}
		TEST_METHOD(TestMethod2)
		{
			string out = game("2 2 1 1 3 2 2 1 1 2");
			string need = "...\n"\
				"...\n"\
				"...\n"\
				"...\n"\
				".X.\n"\
				"...\n"\
				"O..\n"\
				".X.\n"\
				"...\n"\
				"O..\n"\
				".X.\n"\
				".X.\n"\
				"O..\n"\
				"OX.\n"\
				".X.\n"\
				"P2 WINS";
			Assert::AreEqual(out, need);
		}
		TEST_METHOD(TestMethod3)
		{
			string out = game("ssss");
			string need = "...\n"\
				"...\n"\
				"...\n"\
				"INVALID INPUT TRY AGAIN";
			Assert::AreEqual(out, need);
		}
	};
}
