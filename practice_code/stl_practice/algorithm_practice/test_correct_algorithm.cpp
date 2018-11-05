#include <iostream>
#include <iterator>
#include <algorithm>
#include <deque>
#include <time.h>

using namespace std;

void displayDeque(const string& str , deque<int>& dq);

int main()
{
	const int N = 10;
	deque<int> d_1;
	deque<int> d_3;
	for(int i = 0 ; i < N ; ++i)
	{
		d_1.push_front(i);
		d_1.push_back(i);
		d_3.push_back(i);
	}
	displayDeque("Test",d_1);
	
	//copy
	deque<int> d_2(10,0);
	displayDeque("d_2",d_2);
	copy(d_1.begin(),d_1.end(),d_2.begin());
	//it doesn't change the size of the container
	displayDeque("d_2 after copy",d_2);
	
	//copy_backward
	d_2.assign(10,0);
	displayDeque("d_2",d_2);
	displayDeque("d_3",d_3);
	//the direction is backward from the dest iter
	copy_backward(d_3.begin(),d_3.end(),d_2.end());
	displayDeque("d_2 copybackwark",d_2);
	
	//fill
	fill(d_2.begin(),d_2.end(),1);
	displayDeque("Fill d_2 with 1",d_2);
	//fill_n
	fill_n(d_2.begin(),5,2);
	displayDeque("Fill d_2 with 5 '2'",d_2);
	
	srand((unsigned)time(0));
	//generate
	generate(d_2.begin(),d_2.end(),rand);
	displayDeque("Generate d_2",d_2);
	
	//generate_
	generate_n(d_2.begin(),5,rand);
	displayDeque("Generate 5 element int d_2",d_2);
	
	
	//make container several parts
	d_2.assign(d_3.begin(),d_3.end());
	random_shuffle(d_2.begin(),d_2.end());
	displayDeque("Random shuffle",d_2);
	//partition
	partition(d_2.begin(),d_2.end(),[](int& t){
		return (t%2);
	});
	displayDeque("Partition even and odds",d_2);
	
	//remove
	remove(d_2.begin(),d_2.end(),5);
	displayDeque("Remove 5",d_2);
	
	//replace
	replace(d_2.begin(),d_2.end(),8,99);
	displayDeque("Replace 8",d_2);
	
	//rotate
	d_2.assign(d_3.begin(),d_3.end());
	displayDeque("d_2",d_2);
	auto r_iter = find(d_2.begin(),d_2.end(),5);
	rotate(d_2.begin(),r_iter,d_2.end());
	displayDeque("Rotate around 5",d_2);
	
	//reverse
	reverse(d_2.begin(),d_2.end());
	displayDeque("Reverse",d_2);
	
	//swap
	swap(d_2,d_3);
	displayDeque("d_2",d_2);
	displayDeque("d_3",d_3);
	
	//swap_ranges
	
	//transform
	transform(d_2.begin(),d_2.end(),d_2.begin(),[](int& t){
		return t*2;
	});
	displayDeque("Transform d_2",d_2);
	
	transform(d_2.begin(),d_2.end(),d_3.begin(),[](int& t){
		return t*5;
	});
	displayDeque("Transform d_2 to d_3",d_3);
	
	//unique
	
	return 0;
}



void displayDeque(const string& str , deque<int>& dq)
{
	ostream_iterator<int> out(cout," ");
	cout << str << " : ";
	copy(dq.begin(),dq.end(),out);
	cout << endl;
}
