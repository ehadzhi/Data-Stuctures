/*
 * AStack.h
 *
 *  Created on: Dec 10, 2015
 *      Author: erolh
 */

#ifndef ASTACK_H_
#define ASTACK_H_

#include <iostream>
using namespace std;
#include "Stack.h"

template<typename Elem>
class AStack: public Stack<Elem> {
	int top;						// Top is the index of the first free cell
	Elem* container;
	int containerSize;
	bool full() const;
	void resize();
	void printMyself(ostream&) const;
public:
	AStack() :
			top(0), containerSize(5) {
		container = new Elem[containerSize];
	}
	AStack(const AStack<Elem>& toCopy) :
			top(toCopy.top), containerSize(toCopy.containerSize) {
		container = new Elem[containerSize];
		for (int i = 0; i < top; i++) {
			*(container + i) = *(toCopy.container + i);
		}
	}
	AStack& operator=(const AStack<Elem>& toCopy) {
		if (this != toCopy) {
			delete[] container;
			containerSize = toCopy.containerSize;
			top = toCopy.top;
			container = new Elem[containerSize];
			for (int i = 0; i < top; i++) {
				*(container + i) = *(toCopy.container + i);
			}
		}
		return *this;
	}
	~AStack() {
		delete[] container;
	}
	void clear() {
		top = 0;
	}
	void push(const Elem& val) {
		if (full())
			resize();
		*(container + top) = val;
		top++;
	}
	Elem pop() {
		if (top >= 0) {
			top--;
			return *(container + top);
		}
		cout << "Popped from an empty stack";
		return Elem();
	}
	const Elem& topValue() const {
		return *(container + top);
	}
	int length() const {
		return top;
	}
};

template<typename Elem>
inline bool AStack<Elem>::full() const{
	return top >= containerSize;
}

template<typename Elem>
inline void AStack<Elem>::resize() {
	containerSize *= 1.5;
	Elem* newCont = new Elem[containerSize];
	for (int i = 0; i < top; i++) {
		*(newCont + i) = *(container + i);
	}
	container = newCont;
}

template<typename Elem>
inline void AStack<Elem>::printMyself(ostream& os) const{
	AStack<Elem> toPrint(*this);

	while(toPrint.length() != 0){
		os<<toPrint.pop()<<" ";
	}
}

#endif /* ASTACK_H_ */
