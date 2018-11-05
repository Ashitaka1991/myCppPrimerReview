#include <iostream>
#include <iterator>
#include <algorithm>
#include <deque>
#include <time.h>

#include <numeric>

using namespace std;

void displayDeque(const string& str , deque<int>& dq);

int main()
{
	const int N = 16;
	deque<int> d_1;
	for(int i = 0 ; i < N ; ++i){
		d_1.push_back(i);
	}
	displayDeque("Test",d_1);
	
	int sum = 0;
	
	//accumulate
	sum = accumulate(d_1.begin(),d_1.end(),0);
	cout << "Sum of d_1 : " << sum << endl;
	
	sum = accumulate(d_1.begin(),d_1.end(),2);
	cout << "Sum of d_1 with 2: " << sum << endl;
	
	
	//partial_sum
	deque<int> d_2(d_1.size());
	displayDeque("d_2",d_2);
	partial_sum(d_1.begin(),d_1.end(),d_2.begin());
	displayDeque("d_2 after partial sum",d_2);
	
//	partial_sum(d_1.begin(),d_1.end(),d_2.begin(),multiplies<int>());
//	displayDeque("d_2 after partial sum",d_2);

	//inner_product
	sum = inner_product(d_1.begin(),d_1.end(),d_2.begin(),0);
	cout << "Inner product of d_1 and d_2 is : " << sum << endl;
	
	//adjacent_difference
	adjacent_difference(d_1.begin(),d_1.end(),d_2.begin());
	displayDeque("Adjacent difference",d_2);
	
	random_shuffle(d_1.begin(),d_1.end());
	displayDeque("d_1",d_1); 
	adjacent_difference(d_1.begin(),d_1.end(),d_2.begin());
	displayDeque("Adjacent difference",d_2);
		
	return 0;
}

void displayDeque(const string& str , deque<int>& dq)
{
	ostream_iterator<int> out(cout," ");
	cout << str << " : ";
	copy(dq.begin(),dq.end(),out);
	cout << endl;
}
