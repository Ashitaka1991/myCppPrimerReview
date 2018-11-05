#include <iostream>
#include <iterator>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

void displayDeque(const string& str , deque<int>& deq);

int main()
{
	const int N = 10;
	deque<int> d_1;
	for(int i = 0 ; i < N ;++i){
		d_1.push_front(i);
		d_1.push_back(i);
	}
	displayDeque("Test" , d_1);
	
	d_1.pop_front();
	d_1.pop_back();
	displayDeque("After pop" , d_1);
	
	cout << "Size of deque before resize : " << d_1.size() << endl;
	d_1.resize(2*N,0);
	cout << "Size of deque after resize :  " << d_1.size() << endl;
	displayDeque("After resize",d_1);
	
	//front and back return reference type
	int& f_e = d_1.front();
	int& b_e = d_1.back();
	cout << "Front element : " << f_e << " Back element : " << b_e << endl;
	
	ostream_iterator<int> out(cout," ");
	cout << "Reverse Iter : ";
	copy(d_1.rbegin(),d_1.rend(),out);
	cout << endl;
	
	//operation
	cout << "iterate by index : ";
	for(int i = 0 ; i < d_1.size() ; ++i){
		cout << d_1[i] << " ";
	}
	cout << endl;
	
	cout << "iterate by at : ";
	for(int i = 0 ; i < d_1.size() ; ++i){
		cout << d_1.at(i) << " ";
	}
	cout << endl;
	
	//assign
	deque<int> d_2(2*N,0);
	displayDeque("Initial d_2",d_2);
	d_2.assign(++d_1.begin(),d_1.end());
	displayDeque("d_2 after assign",d_2);
	cout << "Size of d_2 : " << d_2.size() << endl;
	cout << "Size of d_1 : " << d_1.size() << endl;
	
	d_2.assign(8,1);
	displayDeque("d_2 after assign",d_2);
	cout << "Size of d_2 : " << d_2.size() << endl;
	
	//swap
	cout << "Before swap!" << endl;
	displayDeque("d_1",d_1);
	displayDeque("d_2",d_2);
	
	cout << "After Swap!" << endl;
	d_1.swap(d_2);
	displayDeque("d_1",d_1);
	displayDeque("d_2",d_2);
	
	cout << "After swap algorithm!" << endl;
	swap(d_1,d_2);
	displayDeque("d_1",d_1);
	displayDeque("d_2",d_2);
	
	//template operation
	if(d_1 == d_2){
		cout << "The deques are equal!" << endl; 
	}
	else{
		cout << "The deques are not euqal!" << endl;
	}
	
	if(d_1 > d_2){
		cout << "d_1 is greater than d_2!" << endl;
	}
	else{
		cout << "d_1 is not greater than d_2!" << endl;
	}
		
	return 0;
}

void displayDeque(const string& str , deque<int>& deq)
{
	//the header of iterator is necessary
	ostream_iterator<int> out(cout," ");
	cout << str << " : ";
	copy(deq.begin(),deq.end(),out);
	cout << endl;
}
