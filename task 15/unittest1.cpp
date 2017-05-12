#include "stdafx.h"
#include "CppUnitTest.h"

#include "Builder.h"
#include "additional.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(checkTest)
		{
			Assert::AreEqual(check(""), 0);
			Assert::AreEqual(check("a"), 97);
			Assert::AreEqual(check("a "), 129);
		}

		TEST_METHOD(elementTest)
		{
			Element el("article");
			Assert::IsTrue(el.toString() == "<article>\n</article>\n");
			Element el1("title", "text in title");
			Assert::IsTrue(el1.toString() == "<title>\n    text in title\n</title>\n");
		}

		TEST_METHOD(xmlTest)
		{
			toXml("file");
			ifstream f1("file.xml");
			string s;
			getline(f1, s);
			Assert::IsTrue(s == "<article>");
			getline(f1, s);
			Assert::IsTrue(s == "    <title>");
			getline(f1, s);
			Assert::IsTrue(s == "        Title");
			getline(f1, s);
			Assert::IsTrue(s == "    </title>");
			getline(f1, s);
			Assert::IsTrue(s == "    <author>");
			getline(f1, s);
			Assert::IsTrue(s == "        Surname");
			getline(f1, s);
			Assert::IsTrue(s == "    </author>");
			getline(f1, s);
			Assert::IsTrue(s == "    <body>");
			getline(f1, s);
			Assert::IsTrue(s == "        Article text");
			getline(f1, s);
			Assert::IsTrue(s == "    </body>");
			getline(f1, s);
			Assert::IsTrue(s == "    <hash>");
			getline(f1, s);
			Assert::IsTrue(s == "        1193");
			getline(f1, s);
			Assert::IsTrue(s == "    </hash>");
			getline(f1, s);
			Assert::IsTrue(s == "</article>");
			f1.close();
		}

	};
}
