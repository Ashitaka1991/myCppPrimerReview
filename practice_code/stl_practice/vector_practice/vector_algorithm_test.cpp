#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void PrintIt(int& s) {cout << s << " ";}


int main()
{
	vector<int> tv;
	ostream_iterator<int> out(cout," ");
	
	for(int i = 0 ; i < 10 ; ++i)
		tv.push_back(i);
	
	cout << "Using copy algorithm : " << endl;
	copy(tv.begin(),tv.end(),out);	
	cout << endl << endl;
	
	cout << "Using for_each algorithm : " << endl;
	for_each(tv.begin(),tv.end(),PrintIt);
	cout << endl << endl;
	
	cout << "push_back : " << endl;
	tv.push_back(100);
	for_each(tv.begin(),tv.end(),PrintIt);
	cout << endl << endl;
	
	cout << "pop_back : " << endl;
	tv.pop_back();
	for_each(tv.begin(),tv.end(),PrintIt);
	cout << endl << endl;
	
	cout << "find and insert : " << endl;
	vector<int>::iterator iter;
	iter = find(tv.begin(),tv.end(),5);
	iter = tv.insert(iter,-1);
	cout << "current iter : " << *iter << endl;
	for_each(tv.begin(),tv.end(),PrintIt);
	cout << endl;
	iter = find(tv.begin(),tv.end(),5);
	iter = tv.insert(++iter,-2);
	cout << "current iter : " << *iter << endl;
	for_each(tv.begin(),tv.end(),PrintIt);
	cout << endl << endl;
	
	cout << "find -1 and erase : " << endl;
	iter = find(tv.begin(),tv.end(),-1);
	iter = tv.erase(iter);
	cout << "current iter : " << *iter << endl;
	for_each(tv.begin(),tv.end(),PrintIt);
	cout << endl << endl;
	
	cout << "remove 5 : " << endl;
	iter = remove(tv.begin(),tv.end(),5);
	cout << "new end : " << endl;
	for_each(tv.begin(),iter,PrintIt);
	cout << endl;
	cout << "real end : " << endl;
	for_each(tv.begin(),tv.end(),PrintIt);
	cout << endl << endl;
	
	vector<int> sv;
	sv.reserve(5);
	cout << "only reserve : " << endl;
	for_each(sv.begin(),sv.end(),PrintIt);
	cout << endl;
	cout << "use end index : " << endl;
	sv[0] = 99;
	sv[4] = 99;
	sv.push_back(-1);//wow!It takes the postion of sv[0]
	for_each(sv.begin(),sv.end(),PrintIt);
	cout << endl << endl;
	
	cout << "using swap : " << endl;
	sv.push_back(-2);
	sv.push_back(-3);
	cout << "before swap : " << endl;
	for_each(sv.begin(),sv.end(),PrintIt);
	cout << endl;
	for_each(tv.begin(),tv.end(),PrintIt);
	cout << endl;
	
	cout << "after swap : " << endl;
	swap(sv,tv);
	for_each(sv.begin(),sv.end(),PrintIt);
	cout << endl;
	for_each(tv.begin(),tv.end(),PrintIt);
	cout << endl;
	
	
	return 0;
}
