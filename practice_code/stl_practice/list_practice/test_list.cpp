#include <iostream>
#include <iterator>
#include <list>

using namespace std;

void displayList(const string& str , list<int> lst);

int main()
{
	const int N  = 10;
	list<int> l_1;
	for(int i = 0 ; i < N ; ++i){
		l_1.push_front(i);
		l_1.push_back(i);
	}
	displayList("Test",l_1);
	
	l_1.pop_front();
	l_1.pop_back();
	displayList("Pop from double ends",l_1);
	
	cout << "Front ele : " << l_1.front() << "   Back ele: " << l_1.back() << endl;
	
	l_1.pop_back();
	l_1.pop_back();
	l_1.pop_back();
	l_1.pop_back();
	displayList("Pop 4 eles",l_1);
	
	l_1.reverse();
	displayList("After reverse",l_1);
	
	l_1.resize(2*N);
	displayList("After resize",l_1);
	
	//reverse iterator for double ended structure
	
	
	//swap
	list<int> l_2;
	l_2.assign(10,1);
	displayList("l_2",l_2);
	
	cout << "After swap!" << endl;
	l_1.swap(l_2);
	displayList("l_1",l_1);
	displayList("l_2",l_2);
	
	//available for most logical operator
	
	
	//special functions
	//merge
	l_2.merge(l_1);
	displayList("Merged List",l_2);
	
	//sort
	l_2.sort(greater<int>());
	displayList("Sorted List",l_2);
	
	//remove
	l_2.remove(1);
	displayList("l_2 after removing 1",l_2);
	
	//lambda for remove_if
	l_2.remove_if([](int& t){
		return t%2 == 0;
	});
	displayList("l_2 after removing even",l_2);
	
	//splice
	
	//unique
	cout << "Size of l_1 : " << l_1.size() << endl;
	for(int i = 0 ; i < N ; ++i){
		l_1.push_front(i);
		l_1.push_back(i);
	}
	displayList("l_1",l_1);
	
	l_1.unique();
	displayList("After unique",l_1);
	
	return 0;
}


void displayList(const string& str , list<int> lst)
{
	ostream_iterator<int> out(cout , " ");
	cout << str << " : ";
	copy(lst.begin(),lst.end(),out);
	cout << endl;
}
