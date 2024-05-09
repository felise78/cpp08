#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <algorithm>

# define PURPLE 		"\033[0;38;2;80;80;220m"
# define ITALIC 		"\033[3m"
# define DIM    		"\033[2m"
# define RESET			"\033[0m"

int doubleValue(int x) {
    return x * 2;
}

int main()
{
    // ------------------------------------------------------------------------------------- //
    // ----------------------------------- MutantStack ------------------------------------- //
    // ------------------------------------------------------------------------------------- //
 
    std::cout << PURPLE "//////////////////////////" RESET << std::endl;
    std::cout << PURPLE "////// " RESET "MUTANT STACK" PURPLE " //////" RESET << std::endl;
    std::cout << PURPLE "//////////////////////////" RESET << std::endl;
    std::cout << DIM ITALIC "- Creating mstack --------" RESET << std::endl;

    MutantStack<int> mstack;

    std::cout << DIM "Is stack empty ? " RESET << (mstack.empty() ? "Yes" : "No") << std::endl;
    
    std::cout << DIM ITALIC "- Push '5' to stack ------" RESET << std::endl;
    mstack.push(5);
    std::cout << DIM ITALIC "- Push '17' to stack -----" RESET << std::endl;
    mstack.push(17);
    
    std::cout << DIM "top of the stack : " RESET << mstack.top() << std::endl;
    
    std::cout << DIM ITALIC "- Using pop() on mstack --" RESET << std::endl;
    mstack.pop();
    
    std::cout << DIM "size of the stack : " RESET << mstack.size() << std::endl;
    
    std::cout << DIM "Is stack empty ? " RESET << (mstack.empty() ? "Yes" : "No") << std::endl;
    
    std::cout << DIM ITALIC "- Push '3' to stack ------" RESET << std::endl;
    mstack.push(3);
    std::cout << DIM ITALIC "- Push '5' to stack ------" RESET << std::endl;
    mstack.push(5);
    std::cout << DIM ITALIC "- Push '737' to stack ----" RESET << std::endl;
    mstack.push(737);
    std::cout << DIM ITALIC "- Push '0' to stack ------" RESET << std::endl;
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    std::cout << DIM ITALIC "- Using iterators to print" RESET << std::endl;
    std::cout << PURPLE "stack :" RESET << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    // testing copy constructor
    std::cout << DIM ITALIC "- Using copy constructor -" RESET << std::endl;
    std::stack<int> s(mstack);
    std::cout << PURPLE "copied stack :" RESET << std::endl;
    while (!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }
    // maintenant je peux utiliser des algorithmes qui prennent des iterators
    std::cout << DIM ITALIC "- Now I can use algorithms -" RESET << std::endl;
    
    MutantStack<int> output;
    for(size_t i = 0; i < mstack.size(); ++i)
        output.push(0);
    std::transform(mstack.begin(), mstack.end(), output.begin(), doubleValue);
    MutantStack<int>::iterator it2 = output.begin();
    MutantStack<int>::iterator it3 = output.end();
    std::cout << PURPLE "output stack :" RESET << std::endl;
    while (it2 != it3)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    std::cout << PURPLE "//////////////////////////" RESET << std::endl;

    //--------------------------- tests avec std::list ------------------------------------- //
    
    std::cout << PURPLE "///// " RESET "LIST CONTAINER " PURPLE "/////" RESET << std::endl;
    std::cout << PURPLE "//////////////////////////" RESET << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << DIM "back of the list : " RESET << lst.back() << std::endl;
    lst.pop_back();
    std::cout << DIM "size of the list : " RESET << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::list<int>::iterator it_f = lst.begin();
    std::list<int>::iterator it_b = lst.end();
    std::cout << PURPLE "list :" RESET << std::endl;
    while (it_f != it_b)
    {
        std::cout << *it_f << std::endl;
        ++it_f;
    }
    // testing copy constructor
    std::cout << DIM ITALIC "- Using copy constructor -" RESET << std::endl;
    std::list<int> cpy(lst);
    std::cout << PURPLE "copied list :" RESET  << std::endl;
    while (!cpy.empty()) {
        std::cout << cpy.back() << std::endl;
        cpy.pop_back();
    }
    std::cout << PURPLE "//////////////////////////" RESET << std::endl;

    return 0;
}
