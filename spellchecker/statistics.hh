#pragma once

#include "../string_view.hh"

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>

// Collects statistics on spelling errors
class Statistics
{
public:

	void add_error(string_view error)
	{
		_errors[std::string(error)] ++;
		_num_errors++;
	}

	void print_stats()
	{
		// sort order errors by frequenecy
		std::vector<std::pair<std::string, int>> errors_by_freq(_errors.begin(), _errors.end());
		std::sort(
			errors_by_freq.begin(), errors_by_freq.end(),
			[](auto& a, auto &b) { return a.second > b.second; });

		std::cout << "Errors found: " << _num_errors << std::endl;
		std::cout << "Top 10 errors: " << std::endl;
		auto it = errors_by_freq.begin();
		for(int i = 0; i < std::min<int>(10, errors_by_freq.size()); i++, it++)
		{
			std::cout << it->second << "\t: " << it->first << std::endl;
		}
	}

private:

	std::size_t _num_errors = 0;
	std::unordered_map<std::string, int> _errors;
};
