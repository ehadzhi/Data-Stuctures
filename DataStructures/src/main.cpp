/*
 * main.cpp
 *
 *  Created on: Dec 7, 2015
 *      Author: erolh
 */

#include "AList.h"
#include<iostream>
using namespace std;

void testAList();

int main(){
	testAList();
	return 0;
}

void testAList(){
	AList<int> list1,list2(7);

	for(int i = 0;i < 40;i++){
		list1.append(i);
	}
	cout<<list1;
	cout<<list1.getValue()<<endl;

	list1.moveToPos(14);
	list1.insert(500);
	cout<<list1;

	list1.moveToPos(14);
	list1.remove();
	cout<<list1;

	list1.clear();
	cout<<list1;
}
