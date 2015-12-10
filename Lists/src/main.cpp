/*
 * main.cpp
 *
 *  Created on: Dec 7, 2015
 *      Author: erolh
 */

#include "AList.h"
#include "LList.h"
#include "DLList.h"
#include<iostream>
using namespace std;

void testAList();
void testLList();
void testDLList();

int main(){
	testLList();
	testAList();
	testDLList();
	return 0;
}

void testDLList(){
	DLList<int> list1;

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

void testLList(){
	LList<int> list1;

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
