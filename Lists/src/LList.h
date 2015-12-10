/*
 * LList.h
 *
 *  Created on: Dec 9, 2015
 *      Author: erolh
 */

#ifndef LLIST_H_
#define LLIST_H_

#include "List.h"
#include <iostream>
using namespace std;

template<typename Elem>
class Node {
public:
	Elem value;
	Node<Elem>* next;

	Node(Elem value, Node<Elem>* next) :
			value(value), next(next) {
	}
};

template<typename Elem>
class LList: public List<Elem> {		//	Singly linked list
	Node<Elem>* head;		// List header
	Node<Elem>* tail;		// Last element in list
	Node<Elem>* fence;  	// Element on the left side of the fence
	int lenBefore;			// before fence
	int lenAfter;			// after fence

	void init();			// Helpers
	void removeAll();
public:
	LList() {
		init();
	}
	~LList() {
		removeAll();
	}

	void clear();
	bool insert(const Elem&);
	bool append(const Elem&);
	Elem getValue() const;
	Elem remove();

	void moveToStart();
	void moveToEnd();
	void moveToPos(int pos);
	void next();
	void prev();

	int length() const;
	int lengthBefore() const;
	int lengthAfter() const;
};

template<typename Elem>
ostream& operator<<(ostream& os,LList<Elem>& list){
	list.moveToStart();
	for(int iter = 0;iter < list.length();iter++){
		os<<list.getValue()<<" ";
		list.next();
	}
	return os<<endl;
}

template<typename Elem>
inline void LList<Elem>::init() {
	lenAfter = lenBefore = 0;
	head = tail = fence = new Node<Elem>(0, nullptr);
}

template<typename Elem>
inline void LList<Elem>::removeAll() {
	while (head != nullptr) {
		fence = head;
		head = head->next;
		delete fence;
	}
}

template<typename Elem>
inline Elem LList<Elem>::getValue() const {
	return fence->next->value;
}

template<typename Elem>
inline void LList<Elem>::next() {
	if (lenAfter <= 1) {
		return;
	}
	fence = fence->next;
	lenAfter--;
	lenBefore++;
}

template<typename Elem>
inline bool LList<Elem>::append(const Elem& newElem) {
	tail = tail->next = new Node<Elem>(newElem, nullptr);
	lenAfter++;
	return true;
}

template<typename Elem>
inline bool LList<Elem>::insert(const Elem& newElem) {
	fence->next = new Node<Elem>(newElem, fence->next);
	lenAfter++;
	if (tail == fence)
		tail = fence->next;
	return true;
}

template<typename Elem>
inline void LList<Elem>::moveToStart() {
	fence = head;
	lenAfter += lenBefore;
	lenBefore = 0;
}

template<typename Elem>
inline void LList<Elem>::moveToEnd() {
	head = tail;
	lenBefore += lenAfter;
	lenAfter = 0;
}

template<typename Elem>
inline void LList<Elem>::moveToPos(int pos) {
	if (pos < 0 || pos > lenAfter + lenBefore) {
		return;
	}
	moveToStart();
	for (int i = 0; i < pos; i++) {
		fence = fence->next;
	}
	lenAfter += lenBefore - pos;
	lenBefore = pos;
}

template<typename Elem>
inline void LList<Elem>::prev() {
	if (fence == head) {
		return;
	}
	Node<Elem>* temp = head;
	while (temp->next != fence) {
		temp = temp->next;
	}
	fence = temp;
	lenAfter++;
	lenBefore--;
}

template<typename Elem>
inline int LList<Elem>::length() const {
	return lenAfter + lenBefore;
}

template<typename Elem>
inline int LList<Elem>::lengthBefore() const {
	return lenBefore;
}

template<typename Elem>
inline void LList<Elem>::clear() {
	removeAll();
	init();
}

template<typename Elem>
inline Elem LList<Elem>::remove() {
	if( fence == tail){
		return Elem();
	}
	Node<Elem>* toDel = fence->next;
	Elem val = toDel->value;
	fence->next = fence->next->next;
	lenAfter--;
	delete toDel;
	return val;
}

template<typename Elem>
inline int LList<Elem>::lengthAfter() const {
	return lenAfter;
}

#endif /* LLIST_H_ */
