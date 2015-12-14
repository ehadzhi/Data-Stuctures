/*
 * main.cpp
 *
 *  Created on: Dec 12, 2015
 *      Author: erolh
 */

#include<iostream>
using namespace std;
#include"SBinNode.h"

int main(){
	int x = 5,y = 2;
	int* a = &x;
	SBinNode<int,int> node(5,6);

	cout<<node.getKey();

	return 0;
}


