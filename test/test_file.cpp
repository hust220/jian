#include <jntest/UnitTest.hpp>
#include <jian/utils/file.hpp>

BEGIN_JN

TEST_CASE(file_test)
{
    char filename[] = "jian-test-file.txt";

	STD_ ofstream ofile(filename);
	ofile << "hi" << STD_ endl;
	ofile << "hello";
	ofile.close();

    List<Str> ls;
	for (auto &&it : JN_ FileLines(filename)) {
        ls.push_back(it.line);
	}
    TEST_CHECK(size(ls) == 2);

    std::remove(filename);
}

END_JN


