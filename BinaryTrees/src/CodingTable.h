/*
 * CodingTable.h
 *
 *  Created on: Jan 4, 2016
 *      Author: erolh
 */

#ifndef CODINGTABLE_H_
#define CODINGTABLE_H_

#include"HuffmanNodes.h"
#include<iostream>
#include<string>
#include<bitset>
#include<vector>
using namespace std;

class CodingTable {
	static const int ASCII_SIZE = 128;
	int table[ASCII_SIZE];
	void codingTableHelper(const HuffmanNode& root,vector<bool>& currentCode);
public:
	CodingTable(){}
	CodingTable(const HuffmanNode& root);



	friend ostream& operator<<(ostream& os,const CodingTable& toPrint);
};

#endif /* CODINGTABLE_H_ */
