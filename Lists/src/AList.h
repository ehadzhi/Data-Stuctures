/*
 * AList.h
 *
 *  Created on: Dec 8, 2015
 *      Author: erolh
 */

#include<iostream>
using namespace std;
#include "List.h"

#ifndef ALIST_H_
#define ALIST_H_

template<typename Elem>
class AList: public List<Elem> {				// Array based list
	Elem* container;
	int containerSize;
	int numElements;
	int currentPosition;
	void resize();						// Gets a bigger container
	bool isFull();					// Container can't take any more elements
public:
	AList();
	AList(int contSize);
	//AList(const AList&);
	//AList operator=(const AList);
	~AList();

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
ostream& operator<<(ostream& os,AList<Elem>& list){
	list.moveToStart();
	for(int iter = 0;iter < list.length();iter++){
		os<<list.getValue()<<" ";
		list.next();
	}
	return os<<endl;
}


template<typename Elem>
inline AList<Elem>::AList(int contSize) :
		containerSize(contSize), numElements(0), currentPosition(0) {
	container = new Elem[contSize];
}

template<typename Elem>
inline void AList<Elem>::resize() {
	containerSize *= 1.5;
	Elem* newContainer = new Elem[containerSize];
	for (int index = 0; index < numElements; index++) {
		*(newContainer + index) = *(container + index);
	}
	delete[] container;
	container = newContainer;
}

template<typename Elem>
inline AList<Elem>::~AList() {
	delete[] container;
}

template<typename Elem>
inline void AList<Elem>::moveToStart() {
	currentPosition = 0;
}

template<typename Elem>
inline void AList<Elem>::moveToEnd() {
	currentPosition = numElements - 1;
}

template<typename Elem>
inline void AList<Elem>::moveToPos(int pos) {
	if (pos < 0 || pos >= numElements)
		return;
	currentPosition = pos;
}

template<typename Elem>
inline void AList<Elem>::next() {
	if (currentPosition >= numElements - 1)
		return;
	currentPosition++;
}

template<typename Elem>
inline void AList<Elem>::prev() {
	if (currentPosition <= 0)
		return;
	currentPosition--;
}

template<typename Elem>
inline Elem AList<Elem>::getValue() const {
	return *(container + currentPosition);
}

template<typename Elem>
inline int AList<Elem>::length() const {
	return numElements;
}

template<typename Elem>
inline int AList<Elem>::lengthBefore() const {
	return currentPosition;
}

template<typename Elem>
inline bool AList<Elem>::isFull() {
	return numElements == containerSize;
}

template<typename Elem>
inline void AList<Elem>::clear() {
	numElements = 0;
}

template<typename Elem>
inline bool AList<Elem>::insert(const Elem& insElement) {
	if (this->isFull()) {
		resize();
	}
	for (int index = numElements - 1; index >= currentPosition; index--) {
		*(container + index + 1) = *(container + index);
	}
	*(container + currentPosition) = insElement;
	numElements++;
	return true;
}

template<typename Elem>
inline bool AList<Elem>::append(const Elem& appndElement) {
	if( isFull() ){
		resize();
	}
	*(container + numElements) = appndElement;
	numElements++;
	return true;
}

template<typename Elem>
inline Elem AList<Elem>::remove() {
	Elem toReturn = *(container + currentPosition);
	for(int index = currentPosition;index < numElements -1;index++){
		*(container + index) = *(container + index + 1);
	}
	numElements--;
	return toReturn;
}

template<typename Elem>
inline AList<Elem>::AList() : AList(4) {
}

template<typename Elem>
inline int AList<Elem>::lengthAfter() const {
	return numElements - currentPosition - 1;
}

#endif /* ALIST_H_ */
