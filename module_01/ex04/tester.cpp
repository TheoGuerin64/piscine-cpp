#include <iostream>
#include <string>

#include "Test.hpp"

bool same(const std::string &a, const std::string &b)
{
	return b == a;
}

bool empty(const std::string &a, const std::string &b)
{
	(void)a;
	return b == "\n";
}

bool error(const std::string &a, const std::string &b)
{
	return a == "" && b == "";
}

std::string replace(const std::string &str, const std::string &from, const std::string &to)
{
	if (from == to || from == "")
		return str;

	std::string result;
	size_t index;
	size_t prevIndex = 0;
	while (true)
	{
		index = str.find(from, prevIndex);
		if (index == std::string::npos)
			break;
		result += str.substr(prevIndex, index - prevIndex);
		result += to;
		prevIndex = index + from.size();
	}
	result += str.substr(prevIndex);
	return result;
}

bool spaceReplacedByAdd(const std::string &a, const std::string &b)
{
	return b == replace(a, " ", "+");
}

bool LoremIpsumReplacedByHelloWorld(const std::string &a, const std::string &b)
{
	return b == replace(a, "Lorem ipsum", "Hello World");
}

bool spaceCommaReplacedByDot(const std::string &a, const std::string &b)
{
	return b == replace(a, " ,", ".");
}

int main(void)
{
	Test test;

	test.test(error, "unknown_file", "", "");
	test.test(error, ".no_rights_file", "", "");
	test.test(same, ".test_file", "", "");
	test.test(same, ".test_file", "asd", "asd");
	test.test(spaceReplacedByAdd, ".test_file", " ", "+");
	test.test(same, ".test_file", "  ", "++");
	test.test(LoremIpsumReplacedByHelloWorld, ".test_file", "Lorem ipsum", "Hello World");
	test.test(spaceCommaReplacedByDot, ".test_file", " ,", ".");
	test.test(same, ".test_file", "", "asd");
	test.test(empty, ".test_file", TEST_FILE_CONTENT, "");

	return 0;
}
