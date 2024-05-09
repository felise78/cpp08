#ifndef EASYFIND_HPP
 #define EASYFIND_HPP

	#include <stdexcept>
	#include <algorithm> // for std::find

	template <typename T>
	typename T::iterator easyfind(T& container, int value)
	{
		typename T::iterator it = std::find(container.begin(), container.end(), value);
		if (it != container.end()) {
			return it;
		} else {
			throw std::invalid_argument("Not found in container");
		}
	}

#endif