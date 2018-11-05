#include <iostream>
#include <list>

using namespace std;

const int STU = 100;
const int OUT = 9;

void printFallingOutOrder();

int main()
{
	printFallingOutOrder();
	
	return 0;
}

void printFallingOutOrder()
{
	list<int> stu_list;
	
	for(int i = 1 ; i <= STU ; ++i){
		stu_list.push_back(i);
	}
	
	list<int>::iterator c_iter = stu_list.begin();
	int c_num = 1;
	while(!stu_list.empty()){
		
		//connect tail to head manually
		if(c_iter == stu_list.end()){
			c_iter = stu_list.begin();
		}
		
		//check falling out order
		//if c_num compares to 9 , then print the number and erase the element
		if((c_num % OUT) == 0){
			cout << *c_iter << endl;
			c_iter = stu_list.erase(c_iter);
			--c_iter;
			c_num = 0;
		}
		++c_num;
		++c_iter;
		
	}
	
	return;
}
