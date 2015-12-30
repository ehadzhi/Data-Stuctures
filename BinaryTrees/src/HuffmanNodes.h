/*
 * HuffmanNode.h
 *
 *  Created on: Dec 26, 2015
 *      Author: erolh
 */

#ifndef HUFFMANNODES_H_
#define HUFFMANNODES_H_

#include<src/KeyValPair.h>

class HuffmanNode {
public:
	virtual ~HuffmanNode() {
	}
	virtual int getWeight()const = 0;				 // Return frequency
	virtual bool isLeaf() const = 0;			 // Determine type
	virtual HuffmanNode* getLeft() const = 0; 	 // Get left
	virtual void setLeft(HuffmanNode*) = 0; 	 // Set left
	virtual HuffmanNode* getRight() const = 0; 	 // Get right
	virtual void setRight(HuffmanNode*) = 0;	 // Set right
	virtual char getValue() const = 0;			 // get value if it has such
};

class LeafNode: public HuffmanNode {
	KeyValPair<int, char>* leaf;
public:
	LeafNode(int frequency, char value) {
		leaf = new KeyValPair<int, char>(frequency, value);
	}

	~LeafNode() {
		delete leaf;
	}

	int getWeight()const{
		return leaf->getKey();
	}
	bool isLeaf() const {
		return true;
	}
	HuffmanNode* getLeft() const {
		return nullptr;
	}
	void setLeft(HuffmanNode*) {
	}
	HuffmanNode* getRight() const {
		return nullptr;
	}
	void setRight(HuffmanNode*) {
	}

	char getValue() const {
		return leaf->getElem();
	}
};

class InternalNode: public HuffmanNode {
	HuffmanNode* left;
	HuffmanNode* right;
	int weight;
public:
	InternalNode(HuffmanNode* left, HuffmanNode* right) {
		if (left != nullptr && right != nullptr) {
			weight = left->getWeight() + right->getWeight();
			this->left = left;
			this->right = right;
		}
	}

	int getWeight()const {
		return weight;
	}
	bool isLeaf() const{
		return false;
	}
	HuffmanNode* getLeft() const{
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

	char getValue() const {
		return -1;
	}
};

#endif /* HUFFMANNODE_H_ */
