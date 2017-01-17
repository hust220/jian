#include <jntest/UnitTest.hpp>
#include <jian/utils/file.hpp>

BEGIN_JN

TEST_CASE(file_test)
{
	STD_ ofstream ofile("file-test.txt");
	ofile << "hi" << STD_ endl;
	ofile << "hello";
	ofile.close();

    List<Str> ls;
	for (auto &&it : JN_ FileLines("file-test.txt")) {
        ls.push_back(it.line);
	}
    TEST_CHECK(size(ls) == 2);
}

END_JN


