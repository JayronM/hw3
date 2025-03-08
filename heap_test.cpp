#include<iostream>
#include "heap.h"

using namespace std;

int main(){
	Heap<int> testingHeap;

	testingHeap.push(5);
	testingHeap.push(12);
	testingHeap.push(234);
	testingHeap.push(23);
	testingHeap.push(45);
	testingHeap.push(1);

	cout<< "heap's top: "<<  testingHeap.top()<< endl;

	testingHeap.pop();
	cout<<"Heap's top after: "<< testingHeap.top()<<endl;

	cout<< "Heap array:";
	for(size_t i =0 ;i< testingHeap.size(); i++){
		cout<< testingHeap.top()<< " ";
		testingHeap.pop();
	}
	cout<<endl;

	return 0;
}