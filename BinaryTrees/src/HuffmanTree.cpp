/*
 * HuffmanTree.cpp
 *
 *  Created on: Dec 27, 2015
 *      Author: erolh
 */

#include "HuffmanTree.h"
#include<algorithm>

bool compareNodes(HuffmanNode* first,HuffmanNode* second){
	return first->getWeight() > second->getWeight();
}

HuffmanNode* popHeap(vector<HuffmanNode*> &heap){
	pop_heap(heap.begin(),heap.end(),compareNodes);
	HuffmanNode* temp = heap.back();
	heap.pop_back();
	return temp;
}

void pushHeap(vector<HuffmanNode*> &heap,HuffmanNode* toPush){
	heap.push_back(toPush);
	push_heap(heap.begin(),heap.end(),compareNodes);
}

HuffmanNode* HuffmanTree::buildHuffmanTree(const FrequencyTable& freqTable) {
	auto nodes = freqTable.getNodes();
	make_heap(nodes.begin(),nodes.end(),compareNodes);

	HuffmanNode *temp1, *temp2, *temp3;

	while( nodes.size() > 1){
		temp1 = popHeap(nodes);
		temp2 = popHeap(nodes);
		temp3 = new InternalNode(temp1,temp2);

		pushHeap(nodes,temp3);
	}
	return temp3; // root of our Huffman tree
}

HuffmanTree::HuffmanTree(const FrequencyTable& freqTable) {
	root = buildHuffmanTree(freqTable);
}

ostream& operator<<(ostream& os, const HuffmanTree& tree){

}
