#ifndef TEST_HPP_
#define TEST_HPP_

#include <string>

#define TEST_FILE_CONTENT "Lorem ipsum dolor sit amet, consectetur adipiscing e\
lit. Integer congue, sapien eu semper placerat, elit enim eleifend ante, non ul\
lamcorper dui quam in purus. Nullam consectetur quam lacus, eget ultrices velit\
 blandit ac. Duis quis magna a eros interdum sagittis. Duis ac tellus finibus, \
aliquet massa quis, varius leo. Nullam at velit eu nulla auctor sagittis. Mauri\
s finibus eros elit, ut porta urna commodo vel. Fusce dignissim nec lectus vest\
ibulum dapibus. Aliquam et ante faucibus, facilisis lectus eu, commodo turpis. \
Vestibulum tristique, urna sit amet maximus iaculis, nibh velit tristique nisl,\
 vel consequat nibh justo vitae libero. Nulla leo enim, mollis nec erat consect\
etur, lobortis hendrerit dolor. Nulla lobortis lectus porttitor erat facilisis,\
 a facilisis ligula vehicula."

class Test
{
	public:
		Test(void);
		~Test();

		void test(bool (*cmp)(const std::string &, const std::string &),
			const char *arg1, const char *arg2, const char *arg3);


	private:
		char *_path;

		int execReplace(char **argv);
};

#endif  // TEST_HPP_
