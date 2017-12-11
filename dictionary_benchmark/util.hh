#include <sstream>
#include <fstream>
#include <vector>
#include <string>

inline std::vector<std::string> read_lines(const char* path)
{
	std::vector<std::string> out;
	std::ifstream input(path);
	std::string line;
	while(std::getline(input, line))
	{
		out.push_back(line);
	}
	return out;
}

inline std::string read_full_file(const char* path)
{
	std::ifstream input(path);
	std::ostringstream os;
	os << input.rdbuf();
	return os.str();
}
