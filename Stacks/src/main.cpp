/*
 * main.cpp
 *
 *  Created on: Dec 10, 2015
 *      Author: erolh
 */

#include "AStack.h"

#include<iostream>
using namespace std;

void testStack(Stack<int>* stack){
	for(int i = 0;i < 30;i++){
		stack->push(i);
	}
	cout<<"After push:"<<endl
		<<*stack<<endl;
}

int main(){
	AStack<int> stack1;

	testStack(&stack1);
	return 0;
}


