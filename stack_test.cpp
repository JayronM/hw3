#include <iostream>
#include "stack.h"

using namespace std;

int main(){
	Stack<int> stack;

	cout<<"checking for stack empty"<< (stack.empty())<< endl;

	stack.push(12);
	stack.push(234);
	stack.push(120);

	cout<<"size: "<< stack.size()<<endl;
	cout<<"Top: "<<stack.top()<<endl;

	stack.pop();
	cout<< "New top: "<< stack.top()<<endl;

	stack.pop();
	stack.pop();

	//popping from empty
	try{
		stack.pop();

	} catch(const std::underflow_error& err){
		cout<<"what was caught: "<<err.what()<<endl;
	}
	 
	 return 0;
}