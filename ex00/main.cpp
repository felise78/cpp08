#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

# define PURPLE 		"\033[0;38;2;80;80;220m"
# define ITALIC 		"\033[3m"
# define DIM    		"\033[2m"
# define RESET			"\033[0m"

int main ()
{
	// --------------------------   test with LIST container ------------------------------- //

	std::cout << PURPLE "Test with " ITALIC "list " PURPLE "container : " RESET << std::endl;
	std::list<int> lst;
	lst.push_back(12);
	lst.push_back(78);
	lst.push_back(65);
	lst.push_back(31);
	lst.push_back(4);

	// printing list
	std::cout << PURPLE << "lst : " RESET;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

	// tests
	try {
		std::cout << DIM "Trying to find number (" RESET  "78" DIM ") : " RESET;
		easyfind(lst, 78);
		std::cout << "Number was found in container list" << std::endl;
		std::cout << DIM "Trying to find number (" RESET  "5" DIM ") : " RESET;
		easyfind(lst, 5);
		std::cout << "Number was found in container list" << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	// --------------------------   test with VECTOR container -------------------------- //
	
	std::cout << PURPLE "\nTest with " ITALIC "vector " PURPLE "container : " RESET << std::endl;
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(12);
	vec.push_back(43);
	vec.push_back(85);
	vec.push_back(9);

	// printing vector
	std::cout << PURPLE << "vec : " RESET;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

	// tests
	try {
		std::cout << DIM "Trying to find number (" RESET  "5" DIM ") : " RESET;
		easyfind(vec, 5);
		std::cout << "Number was found in container vector" << std::endl;
		std::cout << DIM "Trying to find number (" RESET  "78" DIM ") : " RESET;
		easyfind(vec, 78);
		std::cout << "Number was found in container vector" << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	return 0;
}