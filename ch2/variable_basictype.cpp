#include "variable_basictype.h"
#include "extern_demo.h"
#include <iostream>

using namespace std;

int main(){
	cout << "Hello Cpp" << endl;
	
	//pointer literal nullptr?
	int* pLiteral;
	cout << "Pointer Literal? " << pLiteral << endl;
	
	
	//C++11 list initialization using curly brackets
	int iniA = 1;
	int iniB(2);
	int iniC{3};
	cout << "Initialization Methods: " << iniA << ends << iniB << ends << iniC << endl;
	//forbid distortion
	double dValue = 3.14;
	//int iValue{dValue};		//There is a warning here.
	
	
	//declaration         *fuzzy
	extern int AnExternVar;
	cout << "value of Extern Var: " << AnExternVar << endl;
	
	
	//inference(can't initialize by literal ; can't initialize by expression ; type must match)
	int iVal = 11;
	int &inference1 = iVal;
//	int &inference2 = 12;
//  int &inference3 = iVal*2;
//	cout << "Value of inference: " << inference2 << endl;
	cout << "Value of inference: " << inference1 << endl;
	
	
	//pointer(it can be used as the state of if statement)
	int *p1 = nullptr;
	int *p2 = 0;
	int *p3 = 0;
	int tValue = 123;
	p3 = &tValue;
	if(p1){
		cout << "Pointer1 is not 0" << endl;
	}
	else{
		cout << "Pointer1 is 0" << endl;
	}
	if(p2){
		cout << "Pointer2 is not 0" << endl;
	}
	else{
		cout << "Pointer2 is 0" << endl;
	}
	if(p3){
		cout << "Pointer3 is not 0 , is " << *p3 << endl;
	}
	else{	
		cout << "Pointer3 is 0" << endl;
	}
	
	
	//inference of pointer
	int *tp;
	int *&pi = tp;
	
	
	//const(file scope/extern const)
	
	//const inference will generate a temporary const variable which is bound by inference
	int ciValue = 42;
	double cidValue = 3.14;
	const int &constInference1 = 234;//right
	const int &constInference2 = ciValue*2;//right
	const int &constInference3 = cidValue;
	cout << "Const Inference: " << constInference1 << ends << constInference2 << ends << constInference3 << endl;
	
	//pointer to const(low-level const)
	
	//const pointer(top-level const)
	int errNumb = 0;
	int *const curErr = &errNumb; 
	
	
	//const expression
	//int staff_size = 27;//not a const exp
	//const int sz = get_size();//not a const exp
	
	
	//C++11 constexpr variable
	constexpr int mf = 20;
	const int *p = nullptr;
	constexpr int *q = nullptr;
	
	
	//type alias
	//typedef
	typedef double *p;  //(see * as dereference)
	const p cstr = 0;//this is a const pointer,not a pointer to const
	
	//C++11 alias declaration
	//using SI = Sales_item;
	
	//C++11 auto(must initialize)
	//this will peel off the top-level const of the type
	
	//C++11 decltype(analyze type of expression without execute)
	//decltype(f()) sum = x;
	//int i = 42, *p = &i;
	//decltype(*p) c = i; //c is reference of int
	
	
	//class
	//in-class initializer using '{}' or '='
	
}
