/*
 * DLList.h
 *
 *  Created on: Dec 10, 2015
 *      Author: erolh
 */

#ifndef DLLIST_H_
#define DLLIST_H_

#include<iostream>
using namespace std;
#include "List.h"

template<typename Elem>
class DNode {
public:
	Elem value;
	DNode* prev;
	DNode* next;
	DNode() : DNode(0) {
	}
	DNode(Elem val, DNode<Elem>* prev = nullptr, DNode<Elem>* next = nullptr) :
			value(val), prev(prev), next(next) {
		if (next != nullptr)
			next->prev = this;
		if (prev != nullptr) {
			prev->next = this;
		}
	}
};

template<typename Elem>
class DLList: public List<Elem> {
	DNode<Elem>* head;
	DNode<Elem>* current;
	DNode<Elem>* tail;
	int befLength;
	int aftLength;

	void init();
	void removeAll();
public:
	DLList() {
		init();
	}
	~DLList() {
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
ostream& operator<<(ostream& os,DLList<Elem>& list){
	list.moveToStart();
	for(int iter = 0;iter < list.length();iter++){
		os<<list.getValue()<<" ";
		list.next();
	}
	return os<<endl;
}

template<typename Elem>
inline void DLList<Elem>::init() {
	head = current = new DNode<Elem>();
	tail = new DNode<Elem>(0, head, nullptr);
	befLength = aftLength = 0;
}

template<typename Elem>
inline void DLList<Elem>::removeAll() {
	while (head != nullptr) {
		current = head;
		head = head->next;
		delete current;
	}
	befLength = aftLength = 0;
}

template<typename Elem>
inline void DLList<Elem>::clear() {
	removeAll();
	init();
}

template<typename Elem>
inline bool DLList<Elem>::insert(const Elem& val) {
	new DNode<Elem>(val,current->prev,current);
	aftLength++;
	return true;
}

template<typename Elem>
inline bool DLList<Elem>::append(const Elem& val) {
	tail->prev = new DNode<Elem>(val,tail->prev,tail);
	if(tail->prev == head){
		befLength++;
	}
	aftLength++;
	return true;
}

template<typename Elem>
inline Elem DLList<Elem>::getValue() const {
	return current->value;
}

template<typename Elem>
inline Elem DLList<Elem>::remove() {
	DNode<Elem>* toDel = current;
	Elem toRet = toDel->value;
	toDel->next->prev = toDel->prev;
	toDel->prev->next = toDel->next;
	current = current->prev;
	befLength--;
	delete toDel;
	return toRet;
}

template<typename Elem>
inline void DLList<Elem>::moveToStart() {
	current = (head->next == tail)?head:head->next;
	aftLength += befLength;
	befLength = 0;
}

template<typename Elem>
inline void DLList<Elem>::moveToEnd() {
	current = tail->prev;
	befLength += aftLength;
	aftLength++;
}

template<typename Elem>
inline void DLList<Elem>::moveToPos(int pos) {
	if( pos > befLength+aftLength){
		return;
	}
	moveToStart();
	while( pos > 0){
		current = current->next;
		pos--;
	}
	aftLength += befLength - pos;
	befLength = pos;
}

template<typename Elem>
inline void DLList<Elem>::next() {
	if( current->next == tail){
		return;
	}
	current = current->next;
	befLength++;
	aftLength--;
}

template<typename Elem>
inline void DLList<Elem>::prev() {
	if( current == head && current->prev == head){
		return;
	}
	current = current->prev;
	befLength--;
	aftLength++;
}

template<typename Elem>
inline int DLList<Elem>::length() const {
	return aftLength + befLength;
}

template<typename Elem>
inline int DLList<Elem>::lengthBefore() const {
	return befLength;
}

template<typename Elem>
inline int DLList<Elem>::lengthAfter() const {
	return aftLength;
}

#endif /* DLLIST_H_ */
