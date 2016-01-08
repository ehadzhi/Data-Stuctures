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
#include"CodingTable.h"

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
	string allAsciiTest;
	for(int i = 0;i < 128;i++){
		allAsciiTest+=i;
	}
	FrequencyTable table(" plsvnmlskdvnsd");
	HuffmanTree tree(table);

	cout<<tree;
	return 0;
}


