#ifndef SPAN_HPP
 #define SPAN_HPP

	#include <vector>
	#include <stdexcept>
	#include <iostream>

	class Span {

		private:
		unsigned int _N;
		std::vector<int> _numbers;

		public:
		// canonical form
		Span(unsigned int N);
		Span(const Span& cpy);
		Span &operator=(const Span& src);
		~Span();

		// member functions
		void addNumber(int nb);
		int shortestSpan();
		int longestSpan();
		void printSpan(); // not in the subject but for my tests

		template<typename Iterator>
		void addRange(Iterator begin, Iterator end) {
			unsigned int remainingSpace = _N - _numbers.size();
			unsigned int rangeSize = std::distance(begin, end);
			if (rangeSize > remainingSpace) {
				throw std::length_error("Not enough space in the Span");
			}
			_numbers.insert(_numbers.end(), begin, end);
		}

	};

#endif