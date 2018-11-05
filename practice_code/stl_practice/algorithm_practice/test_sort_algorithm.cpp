#include <iostream>
#include <iterator>
#include <algorithm>
#include <deque>
#include <time.h>

using namespace std;

void displayDeque(const string& str , deque<int>& dq);

int main()
{
	const int N = 15;
	deque<int> d_1;
	for(int i = 0 ; i < N ; ++i){
		d_1.push_back(i);
		
	}
	random_shuffle(d_1.begin(),d_1.end());
	displayDeque("Test",d_1);
	
	//sort
	sort(d_1.begin(),d_1.end());
	displayDeque("Default sort",d_1);
	sort(d_1.begin(),d_1.end(),greater<int>());
	displayDeque("Greater sort",d_1);
	
	//partial_sort
	random_shuffle(d_1.begin(),d_1.end());
	displayDeque("d_1",d_1);
	partial_sort(d_1.begin(),d_1.begin() + 8,d_1.end());
	//all the positions are changed
	displayDeque("Partial sort",d_1);
	
	//partial_sort_copy
	random_shuffle(d_1.begin(),d_1.end());
	deque<int> d_2(20,1);
	displayDeque("d_1",d_1);
	displayDeque("d_2",d_2);
	partial_sort_copy(d_1.begin() + 3 , d_1.begin() + 10 , 
					 d_2.begin() +  5 , d_2.begin() + 12);
	cout << "After partial sort copy : " << endl;
	displayDeque("d_1",d_1);
	displayDeque("d_2",d_2);
	
	//binary_search
	sort(d_1.begin(),d_1.end());
	displayDeque("d_1",d_1);
	//it requires sorted container
	if(binary_search(d_1.begin(),d_1.end(),8)){
		cout << "Find 8 in d_1!"<< endl;
	}
	else{
		cout << "Can not find 8 in d_1!" << endl;
	}
	cout << "After binary search" << endl;
	displayDeque("d_1",d_1);
	
	
	//equal range returns the range of the elements which are equal
	//also requires sorted container
	
	
	//lexicographical_compare
	
	
	//max
	//min
	//Not only does it receive value parameter , it also receive container parameter
	
	
	//max_element
	
	
	//merge 5 parameters
	
	//nth_element
	
	
	//make_heap()
	//push_heap()
	//pop_heap()
	
	return 0;
}


void displayDeque(const string& str , deque<int>& dq)
{
	ostream_iterator<int> out(cout," ");
	cout << str << " : ";
	copy(dq.begin(),dq.end(),out);
	cout << endl;
}
