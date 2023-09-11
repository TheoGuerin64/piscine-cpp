#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <cstddef>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include "Test.hpp"

Test::Test(void)
{
	_path = realpath("./replace", NULL);
	if (access(_path, X_OK) != 0)
	{
		std::cout << "replace not found!" << std::endl;
		free(_path);
		exit(1);
	}

	std::string content(TEST_FILE_CONTENT);
	std::ofstream file(".test_file");
	file.write(content.c_str(), content.size());
	file.close();
	std::ofstream file2(".no_rights_file");
	file2.close();
	chmod(".no_rights_file", 0);
}

Test::~Test(void)
{
	remove(".test_file");
	remove(".test_file.replace");
	remove(".no_rights_file");

	free(_path);
}

int Test::execReplace(char **argv)
{
	pid_t pid = fork();
	if (pid < 0)
	{
		std::cout << "fork error" << std::endl;
		exit(1);
	}
	else if (pid == 0)
	{
		close(STDOUT_FILENO);
		execv(_path, argv);
		exit(1);
	}
	int status;
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return WEXITSTATUS(status);
	return 1;
}

static std::string getFileContent(const char *file_name)
{
	std::ifstream file(file_name);

	std::string content;
	std::string line;
	while (std::getline(file, line))
		content += line + "\n";

	file.close();
	return content;
}

static void show_result(bool isOk, const char *fileName, const char *from, const char *to)
{
	if (isOk)
		std::cout << "\033[0;32mOK\033[0m";
	else
		std::cout << "\033[0;31mKO\033[0m";
	std::cout << ": ";
	std::cout << "file_name='" << fileName << "' ";
	std::cout << "from='" << from << "' ";
	std::cout << "to='" << to << "'" << std::endl;
}

void Test::test(bool (*cmp)(const std::string &, const std::string &), const char *arg1, const char *arg2, const char *arg3)
{
	char *argv[5] = {
		(char *)"./replace",
		(char *)arg1,
		(char *)arg2,
		(char *)arg3,
		NULL
	};

	int status = execReplace(argv);
	if (status != 0)
	{
		show_result(std::string(arg1) != ".test_file", arg1, arg2, arg3);
		return;
	}

	std::string baseContent = getFileContent(".test_file");
	std::string replaceContent = getFileContent(".test_file.replace");
	show_result(cmp(baseContent, replaceContent), arg1, arg2, arg3);
}
