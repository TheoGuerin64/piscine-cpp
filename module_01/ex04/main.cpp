#include <iostream>
#include <string>
#include <fstream>

static std::string getFileContent(std::ifstream& file)
{
	std::string content;
	std::string line;
	while (std::getline(file, line))
		content += line + "\n";
	return content;
}

void replace(std::string& str, const std::string& from, const std::string& to)
{
	if (from == to || from == "")
		return;

	size_t index;
	while (true)
	{
		index = str.find(from, 0);
		if (index == std::string::npos)
			break;
		str.erase(index, from.length());
		str.insert(index, to);
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "3 arguments required!" << std::endl;
		return 1;
	}

	std::ifstream inFile(argv[1]);
	if (!inFile.is_open())
	{
		std::cout << "File reading error!" << std::endl;
		return 2;
	}
	std::string content = getFileContent(inFile);
	content.find(argv[2]);
	inFile.close();

	replace(content, argv[2], argv[3]);

	std::string outPath(argv[1]);
	outPath += ".replace";

	std::ofstream outFile(outPath.c_str());
	if (!outFile.is_open())
	{
		std::cout << "File writing error!" << std::endl;
		return 2;
	}
	outFile.write(content.c_str(), content.size());
	outFile.close();

	return 0;
}
