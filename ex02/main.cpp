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

    // testing all the member functions of std::stack
    std::cout << DIM "Is stack empty ? " RESET << (mstack.empty() ? "Yes" : "No") << std::endl;
    //std::cout << DIM ITALIC "- Push '5' to stack ------" RESET << std::endl;
    mstack.push(5);
    //std::cout << DIM ITALIC "- Push '17' to stack -----" RESET << std::endl;
    mstack.push(17);
    std::cout << DIM "top of the stack : " RESET << mstack.top() << std::endl;
    //std::cout << DIM ITALIC "- Using pop() on mstack --" RESET << std::endl;
    mstack.pop();
    std::cout << DIM "size of the stack : " RESET << mstack.size() << std::endl;
    std::cout << DIM "Is stack empty ? " RESET << (mstack.empty() ? "Yes" : "No") << std::endl;
    //std::cout << DIM ITALIC "- Push '3' to stack ------" RESET << std::endl;
    mstack.push(3);
   // std::cout << DIM ITALIC "- Push '5' to stack ------" RESET << std::endl;
    mstack.push(5);
   // std::cout << DIM ITALIC "- Push '737' to stack ----" RESET << std::endl;
    mstack.push(737);
   // std::cout << DIM ITALIC "- Push '0' to stack ------" RESET << std::endl;
    mstack.push(0);

    // printing the stack //
    
    std::cout << DIM ITALIC "- Using iterators to print" RESET << std::endl;
    std::cout << PURPLE "iterator :" RESET << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Parcours de la pile avec un itérateur inverse standard
    std::cout << PURPLE "reverse iterator :" RESET << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // Parcours de la pile avec un itérateur constant
    std::cout << PURPLE "const iterator :" RESET << std::endl;
    for (MutantStack<int>::const_iterator cit = mstack.begin(); cit != mstack.end(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;

    // Parcours de la pile avec un itérateur inverse constant
    std::cout << PURPLE "const reverse iterator :" RESET << std::endl;
    for (MutantStack<int>::const_reverse_iterator crit = mstack.rbegin(); crit != mstack.rend(); ++crit) {
        std::cout << *crit << " ";
    }
    std::cout << std::endl;

    // testing copy constructor
    std::cout << DIM ITALIC "- Using copy constructor -" RESET << std::endl;
    std::stack<int> s(mstack);
    std::cout << PURPLE "copied stack :" RESET << std::endl;
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl ;

    // maintenant je peux utiliser des algorithmes qui prennent des iterators
    std::cout << DIM ITALIC "-~-~-~-~-~-~-~-~-~-~-~-~-~" RESET << std::endl;
    std::cout << DIM ITALIC "- Now I can use algorithms" RESET << std::endl;
    std::cout << DIM ITALIC "that use iterators -~-~-~-" RESET << std::endl;
    std::cout << DIM ITALIC "-~-~-~-~-~-~-~-~-~-~-~-~-~" RESET << std::endl;
    MutantStack<int> output;
    for(size_t i = 0; i < mstack.size(); ++i)
        output.push(0);
    std::transform(mstack.begin(), mstack.end(), output.begin(), doubleValue);
    MutantStack<int>::iterator it2 = output.begin();
    MutantStack<int>::iterator it3 = output.end();
    std::cout << PURPLE "output stack :" RESET << std::endl;
    while (it2 != it3)
    {
        std::cout << *it2 << " ";
        ++it2;
    }
    std::cout << std::endl << std::endl;

    // ------------------------------------------------------------------------------------- //
    // --------------------------- MutantStack using std::list ----------------------------- //
    // ------------------------------------------------------------------------------------- //

    std::cout << PURPLE "//////////////////////////" RESET << std::endl;
    std::cout << PURPLE "/ " RESET "MutantStack with List " PURPLE " /" RESET << std::endl;
    std::cout << PURPLE "//////////////////////////" RESET << std::endl;
    
    MutantStack<int, std::list<int> > lst;

    lst.push(5);
    lst.push(17);
    std::cout << DIM "back of the list : " RESET << lst.top() << std::endl;
    lst.pop();
    std::cout << DIM "size of the list : " RESET << lst.size() << std::endl;
    lst.push(3);
    lst.push(5);
    lst.push(737);
    lst.push(0);
    // printing MutantList : 
    MutantStack<int, std::list<int> >::iterator it_f = lst.begin();
    MutantStack<int, std::list<int> >::iterator it_b = lst.end();
    std::cout << PURPLE "MutantList :" RESET << std::endl;
    while (it_f != it_b)
    {
        std::cout << *it_f << " ";
        ++it_f;
    }
    std::cout << std::endl;

    // testing copy constructor
    std::cout << DIM ITALIC "- Using copy constructor -" RESET << std::endl;
    MutantStack<int, std::list<int> > cpy(lst);
    std::cout << PURPLE "copied MutantList :" RESET  << std::endl;
    while (!cpy.empty()) {
        std::cout << cpy.top() << " ";
        cpy.pop();
    }
    std::cout << std::endl << std::endl;
    
    // ------------------------------------------------------------------------------------- //
    // ---------------------------------- LIST CONTAINER  ---------------------------------- //
    // ------------------------------------------------------------------------------------- //

    std::cout << PURPLE "//////////////////////////" RESET << std::endl;
    std::cout << PURPLE "///// " RESET "LIST CONTAINER " PURPLE "/////" RESET << std::endl;
    std::cout << PURPLE "//////////////////////////" RESET << std::endl;
    
    std::list<int> lst2;
    
    lst2.push_back(5);
    lst2.push_back(17);
    std::cout << DIM "back of the list : " RESET << lst2.back() << std::endl;
    lst2.pop_back();
    std::cout << DIM "size of the list : " RESET << lst2.size() << std::endl;
    lst2.push_back(3);
    lst2.push_back(5);
    lst2.push_back(737);
    lst2.push_back(0);
    
    // printing the list
    std::list<int>::iterator it_fr = lst2.begin();
    std::list<int>::iterator it_ba = lst2.end();
    std::cout << PURPLE "list :" RESET << std::endl;
    while (it_fr != it_ba)
    {
        std::cout << *it_fr << " ";
        ++it_fr;
    }
    std::cout << std::endl;

    // testing copy constructor
    std::cout << DIM ITALIC "- Using copy constructor -" RESET << std::endl;
    std::list<int> cpy2(lst2);
    std::cout << PURPLE "copied list :" RESET  << std::endl;
    while (!cpy2.empty()) {
        std::cout << cpy2.back() << " ";
        cpy2.pop_back();
    }
    std::cout << std::endl;

    return 0;
}
