/*
 * Stack.h
 *	Stack - Abstract Data Type
 *  Created on: Dec 10, 2015
 *      Author: erolh
 */

#ifndef STACK_H_
#define STACK_H_

#include<iostream>
using namespace std;

template<typename Elem>
class Stack {
	// Added so can cout<<Stack work and be mandatory
	virtual void printMyself(ostream& os) const = 0;
public:
	virtual ~Stack() {}

	// Reinitialize the stack
	virtual void clear() = 0;

	// Push an element onto the top of the stack
	virtual void push(const Elem&) = 0;

	// Remove and return the element at the top of the stack.
	virtual Elem pop() = 0;

	// Return a copy of the top element.

	virtual const Elem& topValue() const = 0;

	// Return the number of elements in the stack.
	virtual int length() const = 0;

	friend ostream& operator<<(ostream& os,const Stack<Elem>& toPrint){
		toPrint.printMyself(os);
		return os;
	}
};

#endif /* STACK_H_ */
