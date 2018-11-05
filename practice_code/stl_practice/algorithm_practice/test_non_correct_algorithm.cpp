#include <iostream>
#include <iterator>
#include <algorithm>
#include <deque>

using namespace std;

void displayDeque(const string& str , deque<int>& dq);

int main()
{
	deque<int> d_1;
	const int N = 10;
	
	for(int i = 0 ; i < N ; ++i){
		d_1.push_front(i);
		d_1.push_back(i);
	}
	
	cout << "Test : " ;
	for_each(d_1.begin(),d_1.end(),[](int& t){
		cout << t << " ";
	});
	cout << endl;
	
	displayDeque("Test Again",d_1);
	
	//adjacent_find
	auto a_iter = adjacent_find(d_1.begin(),d_1.end());
	if(a_iter == d_1.end()){
		cout << "Can not find adjacent element!" << endl;
	}
	else{
		cout << "Value of adjacent elements : " << *a_iter << endl;
	}
	
	//count
	cout << "Count 0 : " << count(d_1.begin(),d_1.end(),0) << endl;
	
	//equal
	deque<int> d_2(d_1);
	displayDeque("d_1",d_1);
	displayDeque("d_2",d_2);
	if(equal(d_1.begin(),d_1.end(),d_2.begin())){
		cout << "d_1 is equal to d_2!" << endl;
	}
	else{
		cout << "d_1 is not equal to d_2!" << endl;
	}
	
	unique(d_2.begin(),d_2.end());
	displayDeque("d_1",d_1);
	displayDeque("d_2",d_2);
	if(equal(d_1.begin(),d_1.end(),d_2.begin())){
		cout << "d_1 is equal to d_2!" << endl;
	}
	else{
		cout << "d_1 is not equal to d_2!" << endl;
	}
	
	//find_first_of() find_last() are used for matching subsequence
	d_2.clear();
	for(int i = 1 ; i < (N -2) ; ++i){
		d_2.push_back(i);
	}
	auto f_iter = find_end(d_1.begin(),d_1.end(),d_2.begin(),d_2.end());
	if(f_iter == d_1.end()){
		cout << "Can not find subsequence" << endl;
	}
	else{
		cout << "Find subsequence at position : " << (f_iter - d_1.begin()) << endl;
	}
	
	f_iter = find_first_of(d_1.begin(),d_1.end(),d_2.begin(),d_2.end());
	if(f_iter == d_1.end()){
		cout << "Can not find subsequence" << endl;
	}
	else{
		cout << "Find subsequence at position : " << (f_iter - d_1.begin()) << endl;
		//amazing! The reverse sequence is also concluded!!!
	}
	
	//mismatch
	d_2.clear();
	for(int i = 0 ; i < N ; ++i){
		d_2.push_front(i);
	}
	d_2.pop_back();
	d_2.push_back(8);
	
	auto m_iter = mismatch(d_1.begin(),d_1.end(),d_2.begin());
	//m_iter is a pair
	if(m_iter.first != d_1.end()){
		cout << "Mismatch at position : " << (m_iter.first - d_1.begin()) << "   The value is : " << *(m_iter.first) << endl;
		
	}
	else{
		cout << "Matched!" << endl;
	}
	
	//search
	d_2.pop_back();
	auto s_iter = search(d_1.begin(),d_1.end(),d_2.begin(),d_2.end());
	if(s_iter == d_1.end()){
		cout << "No sequence searched!" << endl;
	} 
	else{
		cout << "d_2 contains sequence of d_2" << endl;
	}
	
	return 0;
}


void displayDeque(const string& str , deque<int>& dq)
{
	ostream_iterator<int> out(cout," ");
	cout << str << " : ";
	copy(dq.begin(),dq.end(),out);
	cout << endl;
}
