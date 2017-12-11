#include "tokenizer.hh"
#include "statistics.hh"

#include "../v0/dictionary.hh"
#include "../string_view.hh"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <locale>
#include <algorithm>


std::vector<std::string> load_dictionary(const char* path)
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

int main(int argc, char** argv)
{
	if (argc < 3)
		throw std::runtime_error("Usage: spellchecker DICTIONARY INPUT");

	// Load dictionary
	std::vector<std::string> words = load_dictionary(argv[1]);
	v0::Dictionary dict(words);
	Statistics stats;

	// Parse input file
	std::ifstream input(argv[2]);
	std::string line;
	std::string lower;
	while(std::getline(input, line))
	{
		auto tokenizer = Tokenizer{line.data(), line.data() + line.size()};
		for(string_view word = tokenizer.get_next(); !word.empty(); word = tokenizer.get_next())
		{
			if (!dict.in_dictionary(word))
			{
				// convert to lower-case and re-check
				lower.resize(word.size());
				std::transform(word.begin(), word.end(), lower.begin(), [](char c) { return std::tolower(c); });
				if (!dict.in_dictionary(lower))
				{
					stats.add_error(word);
				}
			}
		}
	}
	stats.print_stats();
}
 
