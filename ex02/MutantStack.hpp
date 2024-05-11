#ifndef MUTANTSTACK_HPP
 #define MUTANTSTACK_HPP

	#include <stack>

	template<typename T, typename C = std::deque<T> >
	class MutantStack : public std::stack<T, C> {

		public:
		typedef typename C::iterator iterator;
		typedef typename C::const_iterator const_iterator;
		typedef typename C::reverse_iterator reverse_iterator;
    	typedef typename C::const_reverse_iterator const_reverse_iterator;
		// to resolve dependent type names in template classes, you typically need 
		// to use the typename keyword to clarify that they represent types.

		// forme canonique //
		MutantStack(): std::stack<T, C>() {}
		MutantStack(const std::stack<T>& cpy) : std::stack<T>(cpy) { *this = cpy; }
		std::stack<T>& operator=(const std::stack<T>& src) {
			if (this != &src)
				std::stack<T>::operator=(src); //*this = src;
			return *this;
		}
		~MutantStack() {}

		// iterators
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }
		const_iterator begin() const { return this->c.cbegin(); }
    	const_iterator end() const { return this->c.cend(); }
		const_reverse_iterator rbegin() const { return this->c.crbegin(); }
		const_reverse_iterator rend() const { return this->c.crend(); }
		// c refers to the underlying container in std::stack
		// https://en.cppreference.com/w/cpp/container/stack
		
	};

#endif

// https://cplusplus.com/reference/stl/
/* 
stack, queue and priority_queue are implemented as container adaptors. 
Container adaptors are not full container classes, but classes that provide 
a specific interface relying on an object of one of the container classes 
(such as deque or list) to handle the elements. The underlying container 
is encapsulated in such a way that its elements are accessed by the members
of the container adaptor independently of the underlying container class used.
*/