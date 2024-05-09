#include "Span.hpp"
#include <algorithm>
#include <climits>

// ------------------ FORME CANONIQUE --------------------- //

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span& cpy) { *this = cpy; }

Span &Span::operator=(const Span& src)
{
	if (this != &src)
	{
		_N = src._N;
		_numbers = src._numbers;
	}
	return (*this);
}

Span::~Span() {}

// ------------------ MEMBER FUNCTIONS --------------------- //

void Span::addNumber(int nb)
{
	if (_numbers.size() >= _N)
        throw std::out_of_range("Span is full");
    _numbers.push_back(nb);
}

int Span::shortestSpan() {

	if (_numbers.size() <= 1) {
		throw std::logic_error("Span need to have at least 2 numbers");
	}
	std::sort(_numbers.begin(), _numbers.end());
	int shortest = INT_MAX;
	for (size_t i = 1; i < _numbers.size(); ++i) {
		shortest = std::min(shortest, _numbers[i] - _numbers[i - 1]);
	}
	return shortest;
}

 int Span::longestSpan() {

	if (_numbers.size() <= 1) {
		throw std::logic_error("Span need to have at least 2 numbers");
	}
	return *std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end());
}

// ------------------------ PRINT SPAN ---------------------------//

void  Span::printSpan()
{
	std::vector<int>::iterator it;
	for (it = _numbers.begin(); it!= _numbers.end(); ++it)
	{
		std::cout << *it;
		if (it != _numbers.end() - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}