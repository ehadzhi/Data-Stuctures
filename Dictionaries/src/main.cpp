/*
 * main.cpp
 *
 *  Created on: Dec 13, 2015
 *      Author: erolh
 */

#include"UALDictionary.h"
#include<string>
#include<iostream>
using namespace std;

int main() {
	UALDictionary<int, string> dict;

		dict.insert(0,"zero");
		dict.insert(1,"one");
		dict.insert(2,"two");
		dict.insert(3,"three");
		dict.insert(4,"four");
		dict.insert(5,"five");
		dict.insert(6,"six");
		dict.insert(7,"seven");
		dict.insert(8,"eight");
	while (dict.size() > 7) {
		cout << dict.removeAny()<< " ";
	}

	string value;
	dict.find(5,value);
	cout<<endl<<value;
	return 0;
}

