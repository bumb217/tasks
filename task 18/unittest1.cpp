#include "stdafx.h"
#include "CppUnitTest.h"
#define protected public

#include "Strategy.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1{

	TEST_CLASS(UnitTest1){
	public:
		
		TEST_METHOD(OrcTest){
			Unit orc("Orc", new CanWalk, new NotFly);
			Assert::IsTrue(orc.name == "Orc");
			Assert::IsTrue(orc.flyStrategy() == "This unit can't fly\n");
			Assert::IsTrue(orc.walkStrategy() == "This unit can walk\n");
		}

		TEST_METHOD(PegasTest){
			Unit pegas("Pegas", new CanWalk, new CanFly);
			Assert::IsTrue(pegas.name == "Pegas");
			Assert::IsTrue(pegas.flyStrategy() == "This unit can fly\n");
			Assert::IsTrue(pegas.walkStrategy() == "This unit can walk\n");
		}

		TEST_METHOD(ElfTest){
			Unit elf("Elf", new CanWalk, new MagicFly);
			Assert::IsTrue(elf.name == "Elf");
			Assert::IsTrue(elf.flyStrategy() == "This unit can fly with magic\n");
			Assert::IsTrue(elf.walkStrategy() == "This unit can walk\n");
		}

		TEST_METHOD(DragonTest){
			Unit dragon("Dragon", new NotWalk, new CanFly);
			Assert::IsTrue(dragon.name == "Dragon");
			Assert::IsTrue(dragon.flyStrategy() == "This unit can fly\n");
			Assert::IsTrue(dragon.walkStrategy() == "This unit can't walk\n");
		}

	};
}
