/*
 * HuffmanTree.h
 *
 *  Created on: Dec 27, 2015
 *      Author: erolh
 */

#ifndef HUFFMANTREE_H_
#define HUFFMANTREE_H_

#include<string>
#include<bitset>
#include<queue>
#include<iostream>
#include"HuffmanNodes.h"
#include"FrequencyTable.h"
#include"CodingTable.h"

using namespace std;

class HuffmanTree {
	HuffmanNode* root;
	HuffmanNode* buildHuffmanTree(const FrequencyTable& freqTable);
	CodingTable codingTable;
public:
	HuffmanTree(const FrequencyTable&);
	void encode(const string&) const;
	string& decode(const string&) const;

	friend ostream& operator<<(ostream&, const HuffmanTree&);
};

#endif /* HUFFMANTREE_H_ */
