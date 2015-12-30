/*
 * FrequencyTable.h
 *
 *  Created on: Dec 25, 2015
 *      Author: erolh
 */

#ifndef FREQUENCYTABLE_H_
#define FREQUENCYTABLE_H_

#include <iostream>
#include <string>
#include <vector>
#include "HuffmanNodes.h"

using namespace std;

class FrequencyTable {
private:
	static const int ASCII_SIZE = 128;
	vector<HuffmanNode*> nodes;
public:
	FrequencyTable(const string& toAnalyze);
	friend ostream& operator <<(ostream&,const FrequencyTable&);
	vector<HuffmanNode*> getNodes() const;
};

#endif /* FREQUENCYTABLE_H_ */
