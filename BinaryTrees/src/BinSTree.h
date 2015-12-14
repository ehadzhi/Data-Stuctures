/*
 * BinSTree.h
 *
 *  Created on: Dec 14, 2015
 *      Author: erolh
 */

#ifndef BINSTREE_H_
#define BINSTREE_H_

#include"SBinNode.h"
#include <src/Dictionary.h>
#include<iostream>
using namespace std;

template<typename Key, typename Elem>
class BinSTree {
	SBinNode<Key, Elem>* root;
	int nodeCount;
	// helpers for use of recursion
	void clearHelper(SBinNode<Key, Elem>* current);
	SBinNode<Key, Elem>* insertHelper(SBinNode<Key, Elem>*, const Key&,
			const Elem&);
	bool findHelper(SBinNode<Key, Elem>*, const Key&, const Elem&);
	SBinNode<Key, Elem>* deleteMin(SBinNode<Key, Elem>* current,
			SBinNode<Key, Elem>* min);
	SBinNode<Key, Elem>* removeHelper(SBinNode<Key, Elem>* curr, const Key& key,
			SBinNode<Key, Elem>* toRem);
	void printHelper(SBinNode<Key,Elem>* current);

public:
	BinSTree();
	~BinSTree();

	void clear();
	void insert(const Key& k, const Elem& elem);
	bool remove(const Key& k, Elem& e);
	Elem removeAny();
	bool find(const Key& key, Elem& elem) const;
	int size();
	void print();
};

template<typename Key, typename Elem>
inline SBinNode<Key, Elem>* BinSTree<Key, Elem>::insertHelper(
		SBinNode<Key, Elem>* sBinNode, const Key& key, const Elem& elem) {
	if (sBinNode == nullptr)
		return new SBinNode<Key, Elem>(key, elem);
	if (elem >= sBinNode->getVal()) {
		sBinNode->setRight(insertHelper(sBinNode->right(), key, elem));
	} else {
		sBinNode->setLeft(insertHelper(sBinNode->left(), key, elem));
	}
	return sBinNode;
}

template<typename Key, typename Elem>
inline void BinSTree<Key, Elem>::insert(const Key& key, const Elem& elem) {
	root = insertHelper(root, key, elem);
	nodeCount++;
}

template<typename Key, typename Elem>
inline bool BinSTree<Key, Elem>::find(const Key& key, Elem& elem) const {
	return findHelper(root, key, elem);
}

template<typename Key, typename Elem>
inline bool BinSTree<Key, Elem>::findHelper(SBinNode<Key, Elem>* sBinNode,
		const Key& key, const Elem& elem) {
	if (sBinNode == nullptr)
		return false;
	if (sBinNode->getKey() > key)
		return findHelper(sBinNode->right(), key, elem);
	else if (sBinNode->getKey() < key)
		return findHelper(sBinNode->left(), key, elem);
	elem = sBinNode->getVal();
	return true;
}

template<typename Key, typename Elem>
inline BinSTree<Key, Elem>::BinSTree() {
	root = nullptr;
	nodeCount = 0;
}

template<typename Key, typename Elem>
inline void BinSTree<Key, Elem>::clearHelper(SBinNode<Key, Elem>* current) {
	if (current != nullptr) {
		clearHelper(current->left());
		clearHelper(current->right());
		delete current;
	}
}

template<typename Key, typename Elem>
inline BinSTree<Key, Elem>::~BinSTree() {
	clearHelper(root);
}

template<typename Key, typename Elem>
inline void BinSTree<Key, Elem>::clear() {
	clearHelper(root);
	root = nullptr;
	nodeCount = 0;
}

template<typename Key, typename Elem>
inline SBinNode<Key, Elem>* BinSTree<Key, Elem>::deleteMin(
		SBinNode<Key, Elem>* current, SBinNode<Key, Elem>* min) {
	if (current->left() == nullptr) {
		min = current;
		return current->right();
	}
	current->setLeft(deleteMin(current->left(), min));
	return current;
}

template<typename Key, typename Elem>
inline bool BinSTree<Key, Elem>::remove(const Key& key, Elem& elem) {
	SBinNode<Key, Elem>* toRem = nullptr;
	root = removeHelper(root, key, toRem);
	if (toRem == nullptr)
		return false;
	elem = toRem->getVal();
	delete toRem;
	return true;
}

template<typename Key, typename Elem>
inline Elem BinSTree<Key, Elem>::removeAny() {
	if (root == nullptr) {
		cout << "The tree is empty";
	}
	SBinNode<Key, Elem>* min;
	root = deleteMin(root, min);
	Elem val = min->getVal();
	delete min;
	return val;
}

template<typename Key, typename Elem>
inline SBinNode<Key, Elem>* BinSTree<Key, Elem>::removeHelper(
		SBinNode<Key, Elem>* curr, const Key& key, SBinNode<Key, Elem>* toRem) {
	if (key > curr->getKey()) {
		curr->setRight(removeHelper(curr->right(), key, toRem));
		return curr;
	} else if (key < curr->getKey()) {
		curr->setLeft(removeHelper(curr->left(), key, toRem));
		return curr;
	}
	toRem = curr;
	if (curr->left() == nullptr) {
		return curr->right();
	} else if (curr->right() == nullptr) {
		return curr->left();
	}
	else{
		SBinNode<Key,Elem>* min;
		curr->setRight(deleteMin(curr,min));

		Elem val = curr->getVal();
		curr->setVal(min->getVal());
		min->setVal( val);
		toRem = min;
	}
	return curr;
}

template<typename Key, typename Elem>
inline int BinSTree<Key, Elem>::size() {
	return nodeCount;
}

template<typename Key, typename Elem>
inline void BinSTree<Key, Elem>::printHelper(SBinNode<Key, Elem>* current) {
	if( current != nullptr){
		printHelper(current->left());
		cout<<current->getVal()<<" ";
		printHelper(current->right());
	}
}

template<typename Key, typename Elem>
inline void BinSTree<Key, Elem>::print() {
	if( root == nullptr ){
		cout<<"Tree is empty."<<endl;
		return;
	}
	printHelper(root);
	cout<<endl;
}

#endif /* BINSTREE_H_ */
