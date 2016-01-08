/*
 * CodingTable.cpp
 *
 *  Created on: Jan 4, 2016
 *      Author: erolh
 */

#include "CodingTable.h"

int toInt(const vector<bool>& toConvert) {
	int toReturn = 0;
	for (int power = 1, index = toConvert.size() - 1; index >= 0;
			index--, power *= 10) {
		toReturn += toConvert[index] * power;
		if (index == 0) {
			toReturn += 1 * power * 10;
		}
	}

	return toReturn;
}

void CodingTable::codingTableHelper(const HuffmanNode& root,
		vector<bool>& currentCode) {

	if (root.isLeaf()) {
		this->table[(int) root.getValue()] = toInt(currentCode);
	} else {

		currentCode.push_back(0);
		codingTableHelper(*(root.getLeft()), currentCode);
		currentCode.pop_back();

		currentCode.push_back(1);
		codingTableHelper(*(root.getRight()), currentCode);
		currentCode.pop_back();
	}
}

CodingTable::CodingTable(const HuffmanNode& root) {
	for (int i = 0; i < ASCII_SIZE; i++) {
		this->table[i] = -1;
	}
	vector<bool> workCode;
	codingTableHelper(root, workCode);
}

ostream& operator<<(ostream& os, const CodingTable& toPrint) {
	for (int i = 0; i < toPrint.ASCII_SIZE; i++) {
		if (toPrint.table[i] != -1)
			os << (char) i << " - " << toPrint.table[i] << endl;
	}
	return os;
}
