/*
 * Heap.h
 *
 *  Created on: Dec 16, 2015
 *      Author: erolh
 */

#ifndef HEAP_H_
#define HEAP_H_

#include<iostream>
using namespace std;

const int DEFAULT_SIZE = 10;

template<typename Elem>
class Heap {
	Elem* container;
	int contSize;
	int numElements;
	void siftDown(int pos);
	void resize();
	bool full();
public:
	Heap() :
			contSize(DEFAULT_SIZE), numElements(0) {
		container = new Elem[contSize];
	}
	Heap(Elem* cont, int contSize, int numElements) :
			contSize(contSize), numElements(numElements), container(cont) {
		this->buildHeap();
	}

	void buildHeap();
	void insert(const Elem& elem);
	Elem removeTop() {
		if (numElements <= 0) {
			cout << "Heap is empty";
			return Elem();
		}
		swap(*(container), *(container + numElements - 1));
		numElements--;
		siftDown(0);
		return *(container + numElements);
	}

	int size() const {
		return this->numElements;
	}

	bool isLeaf(int pos) const {
		return (pos < numElements && pos >= numElements / 2);
	}

	int leftChild(int pos) const {
		if (pos < numElements) {
			return pos * 2 + 1;
		}
		return -1;
	}

	int rigthChild(int pos) const {
		if (pos < numElements) {
			return pos * 2 + 2;
		}
		return -1;
	}

	int parent(int pos) const {
		if (pos > 0 && pos < numElements) {
			return (pos - 1) / 2;
		}
		return -1;
	}
};

template<typename Elem>
inline void Heap<Elem>::siftDown(int pos) {
	if (pos < numElements && pos >= 0 && !isLeaf(pos)) {
		while (!isLeaf(pos)) {
			int max;
			if (rigthChild(pos) >= numElements) {
				max = leftChild(pos);
			} else {
				max = (*(container + leftChild(pos))
						> *(container + rigthChild(pos))) ?
						leftChild(pos) : rigthChild(pos);
			}
			if (*(container + pos) < *(container + max)) {
				swap(*(container + pos), *(container + max));
				pos = max;
			} else {
				break;
			}

		}
	}
}

template<typename Elem>
inline void Heap<Elem>::buildHeap() {
	if (numElements <= 1)
		return;
	for (int pos = numElements; pos >= 0; pos--) {
		siftDown(pos);
	}
}

template<typename Elem>
inline bool Heap<Elem>::full() {
	return contSize == numElements;
}

template<typename Elem>
inline void Heap<Elem>::resize() {
	int newSize = 2 * contSize;
	Elem* newCont = new Elem[newSize];

	for (int i = 0; i < contSize; i++) {
		*(newCont + i) = *(container + i);
	}

	delete[] container;

	container = newCont;
	contSize = newSize;
}

template<typename Elem>
inline void Heap<Elem>::insert(const Elem& elem) {
	if (full())
		resize();

	*(container + numElements) = elem;
	int pos = numElements;
	numElements++;
	while (parent(pos) >= 0 && elem > *(container + parent(pos))) {
		swap(*(container + pos), *(container + parent(pos)));
		pos = parent(pos);
	}
}

#endif /* HEAP_H_ */
