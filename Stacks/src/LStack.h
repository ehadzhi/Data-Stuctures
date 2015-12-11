/*
 * LStack.h
 *	List based stack
 *  Created on: Dec 11, 2015
 *      Author: erolh
 */

#ifndef LSTACK_H_
#define LSTACK_H_

#include "Stack.h"
#include<iostream>
using namespace std;

template<typename Elem>
class StackNode {
public:
	Elem value;
	StackNode* next;
	StackNode(StackNode* next = nullptr, Elem value = 0) :
			next(next), value(value) {
	}
};

template<typename Elem>
class LStack: public Stack<Elem> {
	StackNode<Elem>* head;
	int numElements;
	void printMyself(ostream& os) const;
public:
	LStack();
	LStack(const LStack<Elem>&);
	LStack& operator=(const LStack<Elem>&);
	~LStack();
	void clear();
	void push(const Elem&);
	Elem pop();
	const Elem& topValue() const;
	int length() const;
};

template<typename Elem>
inline LStack<Elem>::LStack() :
		numElements(0) {
	head = new StackNode<Elem>(nullptr,34);
}

template<typename Elem>
inline LStack<Elem>::LStack(const LStack<Elem>& other) :
		numElements(other.numElements) {
	*this = other;
}

template<typename Elem>
LStack<Elem>& LStack<Elem>::operator=(const LStack<Elem>& other) {
	if (this != &other) {
		StackNode<Elem> *iter1 = other.head, *iter2;
		head = iter2 = new StackNode<Elem>(nullptr, other.head->value);
		while (iter1->next != nullptr) {
			iter1 = iter1->next;
			iter2->next = (new StackNode<Elem>(nullptr, iter1->value));
			iter2 = iter2->next;
		}
	}
	return *this;
}

template<typename Elem>
inline LStack<Elem>::~LStack() {
	StackNode<Elem> *toDel;
	while (head == nullptr) {
		toDel = head;
		head = head->next;
		delete toDel;
	}
}

template<typename Elem>
inline void LStack<Elem>::clear() {
	StackNode<Elem> *toDel;
	while (head->next == nullptr) {
		toDel = head;
		head = head->next;
		delete toDel;
	}
}

template<typename Elem>
inline void LStack<Elem>::push(const Elem& val) {
	head = new StackNode<Elem>(head, val);
	numElements++;
}

template<typename Elem>
inline void LStack<Elem>::printMyself(ostream& os) const {
	LStack toPrint(*this);

	while( toPrint.length() > 0){
		os<<toPrint.pop()<<" ";
	}
}

template<typename Elem>
inline Elem LStack<Elem>::pop() {
	if (head->next != nullptr) {
		StackNode<Elem> *toDel;
		toDel = head;
		Elem val = toDel->value;
		head = head->next;
		delete toDel;
		numElements--;
		return val;
	}
	else{
		cout<<"Popping from an empty stack";
	}
}

template<typename Elem>
inline const Elem& LStack<Elem>::topValue() const {
	if( head->next == nullptr){
		cout<<"Stack is empty";
	}
	return head->value;
}

template<typename Elem>
inline int LStack<Elem>::length() const {
	return numElements;
}

#endif /* LSTACK_H_ */
