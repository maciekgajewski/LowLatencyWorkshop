#pragma once

#include "../string_view.hh"
#include <array>

static const std::array<bool, 256> is_dropped = []()
	{
		std::array<bool, 256> delimiters{false};
		const string_view DELIMITERS = " \t.,:;?!\"'[]{}|&*=+-_()#";
		for (const auto c: DELIMITERS)
			delimiters[c] = true;
		return delimiters;
	}();


class Tokenizer
{
public:
	using InputIterator = const char*;
	InputIterator next;
	const InputIterator end;

	string_view get_next()
	{
		for (; next != end && is_dropped[*next]; ++next)
		{ }

		const auto start = next;

		for (; next != end && !is_dropped[*next]; ++next)
		{ }

		return string_view(&(*start), next-start);
	}
};
