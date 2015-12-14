/*
 * SBinNode.h
 *	Simple binary tree node
 *  Created on: Dec 14, 2015
 *      Author: erolh
 */

#ifndef SBINNODE_H_
#define SBINNODE_H_

#include"BinTreeNode.h"

template<typename Key,typename Elem>
class SBinNode {
	Key key;
	Elem value;
	SBinNode* leftChild;
	SBinNode* rigthChild;
public:
	SBinNode(Key key,Elem value,SBinNode<Key,Elem>* leftChild = nullptr,
			SBinNode<Key,Elem>* rigthChild = nullptr);

	~SBinNode() {}

	Key& getKey();
	void setKey(const Key& key);

	Elem& getVal();
	void setVal(const Elem&);

	SBinNode* left() const{
		return leftChild;
	}
	void setLeft(SBinNode<Key,Elem>* node){
		leftChild = node;
	}

	SBinNode* right() const{
		return rigthChild;
	}
	void setRight(SBinNode<Key,Elem>* node){
		rigthChild = node;
	}

	bool isLeaf(){
		return (rigthChild == nullptr && leftChild == nullptr);
	}
};

template<typename Key, typename Elem>
inline SBinNode<Key, Elem>::SBinNode(Key key, Elem value,
		SBinNode<Key, Elem>* leftChild, SBinNode<Key, Elem>* rigthChild)
		:key(key),value(value),leftChild(leftChild),rigthChild(rigthChild){}

template<typename Key, typename Elem>
inline Key& SBinNode<Key, Elem>::getKey() {
	return key;
}

template<typename Key, typename Elem>
inline void SBinNode<Key, Elem>::setKey(const Key& key) {
	this->key = key;
}

template<typename Key, typename Elem>
inline Elem& SBinNode<Key, Elem>::getVal() {
	return value;
}

template<typename Key, typename Elem>
inline void SBinNode<Key, Elem>::setVal(const Elem& val) {
	value = val;
}


#endif /* SBINNODE_H_ */
