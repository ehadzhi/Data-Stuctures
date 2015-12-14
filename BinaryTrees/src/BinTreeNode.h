/*
 * BinTreeNode.h
 *
 *  Created on: Dec 13, 2015
 *      Author: erolh
 */

#ifndef BINTREENODE_H_
#define BINTREENODE_H_

// Binary tree node abstract class
template<typename Elem>
class BinTreeNode {
public:
	virtual ~BinTreeNode() {
	}
	virtual Elem& getVal() const = 0;
	virtual void setVal(const Elem&) = 0;

	virtual BinTreeNode* left() const = 0;
	virtual void setLeft(BinTreeNode*) = 0;

	virtual BinTreeNode* right() const = 0;
	virtual void setRight(BinTreeNode*) = 0;

	virtual bool isLeaf() = 0;
};

#endif /* BINTREENODE_H_ */
