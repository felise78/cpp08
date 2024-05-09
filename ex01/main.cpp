#include "Span.hpp"
#include <cstdlib>
#include <ctime>

# define PURPLE 		"\033[0;38;2;80;80;220m"
# define ITALIC 		"\033[3m"
# define DIM    		"\033[2m"
# define RESET			"\033[0m"


int main(int ac, char **av) {

    if (ac == 1)
    {
        // message to inform that the prog can be run with an arg 
        std::cout << ITALIC "\n*** Usage : run executable with an argument\nto test the program with random numbers ***\n" RESET << std::endl;
        try {

            Span span(10);
            // testing addNumber()
            span.addNumber(6);
            span.addNumber(3);
            span.addNumber(17);
            span.addNumber(9);
            span.addNumber(11);
            // printing span
            std::cout << DIM "span after addNumber() calls:" RESET << std::endl;
            std::cout << PURPLE "span : " RESET;
            span.printSpan();
            // test des fonction membres 
            std::cout << DIM "testing shortestSpan():" RESET << std::endl;
            std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
            std::cout << DIM "testing longestSpan():" RESET << std::endl;
            std::cout << "Longest span: " << span.longestSpan() << std::endl;
            // test de la copie profonde
            std::cout << DIM "testing the copy constructor - span2(span) :" RESET << std::endl;
            std::cout << PURPLE "span2 : " RESET;
            Span span2(span);
            span2.printSpan();
            // testing addRange()
            std::vector<int> range;
            range.push_back(7);
            range.push_back(2);
            range.push_back(8);
            range.push_back(12);
            range.push_back(1);
            std::cout << DIM "testing addRange():" RESET << std::endl;
            span.addRange(range.begin(), range.end());
            std::cout << PURPLE "span2 : " RESET;
            span.printSpan();
            // trying to add an 11th number, throw an error cuz span is size 10
            std::cout << DIM "trying to add an 11th number in span2 (which size is 10):" RESET << std::endl;
            span.addNumber(13); 

        } catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        try {
            std::cout << DIM "testing shortestSpan() on a span size 0 should throw an error:" RESET << std::endl;
            Span span(0);
            span.shortestSpan();
        }
        catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        try {
            std::cout << DIM "testing longestSpan() on a span size 1 should throw an error:" RESET << std::endl;
            Span span(1);
            span.longestSpan();
        }
        catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
    else if (ac == 2) // generate av[1] random numbers
    {
        try {
            int size = std::atoi(av[1]);
            if (size <= 0)
                throw std::invalid_argument("Invalid parameter");
            Span span(size);
            std::srand(std::time(0));
            for (int i = 0; i < size; ++i) {
                span.addNumber(std::rand() % 1000000 + 1);
            }
            span.printSpan();
            std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
            std::cout << "Longest span: " << span.longestSpan() << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
    return 0;
}

// main in the subject : 

// int main()
// {
// 	Span sp = Span(5);

// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

// 	return 0;
// }