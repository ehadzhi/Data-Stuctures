/*
 * main.cpp
 *
 *  Created on: Dec 12, 2015
 *      Author: erolh
 */

#include<iostream>
using namespace std;
#include "BinSTree.h"
#include "Heap.h"
#include"FrequencyTable.h"
#include"HuffmanTree.h"

void testTree() {
	BinSTree<int, char> tree;
	for (int i = 0; i < 60; i++) {
		tree.insert(i, (i + 'A'));
	}
	tree.print();
	tree.removeAny();
	tree.print();
	char toRem;
	tree.remove(7, toRem);
	tree.print();
}

int main(){
	FrequencyTable table("alabalatralalal");
	HuffmanTree tree(table);
	return 0;
}


