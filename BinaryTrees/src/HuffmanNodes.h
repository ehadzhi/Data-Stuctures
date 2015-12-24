/*
 * HuffmanNode.h
 *
 *  Created on: Dec 24, 2015
 *      Author: erolh
 */

#ifndef HUFFMANNODES_H_
#define HUFFMANNODES_H_

#include<src/KeyValPair.h>

template<typename Elem>
class HuffmanNode {
public:
	virtual ~HuffmanNode() {
	}
	virtual int getWeight() = 0;				 // Return frequency
	virtual bool isLeaf() = 0;					 // Determine type
	virtual HuffmanNode* getLeft() const = 0; 	 // Get left
	virtual void setLeft(HuffmanNode*) = 0; 	 // Set left
	virtual HuffmanNode* getRight() const = 0; 	 // Get right
	virtual void setRight(HuffmanNode*) = 0;	 // Set right
};

template<typename Elem>
class LeafNode: public HuffmanNode<Elem> {
	KeyValPair<int, Elem>* leaf;
public:
	LeafNode(int frequency,const Elem& value){
		leaf = new KeyValPair<int,Elem>(frequency,value);
	}

	~LeafNode(){
		delete leaf;
	}

	int getWeight() {
		return leaf->key;
	}
	bool isLeaf() {
		return true;
	}
	HuffmanNode* getLeft() {
		return nullptr;
	}
	void setLeft(HuffmanNode*) {
	}
	HuffmanNode* getRight() const {
		return nullptr;
	}
	void setRight(HuffmanNode*) {
	}
};

template<typename Elem>
class InternalNode: public HuffmanNode<Elem> {
	HuffmanNode<Elem>* left;
	HuffmanNode<Elem>* right;
	int weight;
public:
	InternalNode(HuffmanNode<Elem>* left,HuffmanNode<Elem>* right){
		if( left != nullptr && right != nullptr){
			weight = left->getWeight() + right->getWeight();
			this->left = left;
			this->right = right;
		}
	}

	int getWeight() {
		return weight;
	}
	bool isLeaf() {
		return false;
	}
	HuffmanNode* getLeft() {
		return left;
	}
	void setLeft(HuffmanNode* toSet) {
		if (toSet != nullptr) {
			left = toSet;
		}
	}
	HuffmanNode* getRight() const {
		return right;
	}
	void setRight(HuffmanNode* toSet) {
		if (toSet != nullptr) {
			right = toSet;
		}
	}
};

#endif /* HUFFMANNODES_H_ */
