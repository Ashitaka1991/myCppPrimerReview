#include <iostream>
#include <vector>
#include <list>

using namespace std;

void eraseElements(vector<int>& ivec,list<int>& ilist);

int main()
{
	int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
	vector<int> ivec(ia,ia+11);
	list<int> ilist(ia,ia+11);
	
	eraseElements(ivec,ilist);
	
	cout << "Odd numbers : ";
	for(vector<int>::iterator iter = ivec.begin() ; iter != ivec.end() ; ++iter){
		cout << *iter << "  ";
	}
	cout << endl;
	
	cout << "Even numbers : ";
	for(list<int>::iterator iter = ilist.begin() ; iter != ilist.end() ; ++iter){
		cout << *iter << "  ";
	}
	cout << endl;
	
	return 0;
}


void eraseElements(vector<int>& ivec,list<int>& ilist)
{
	for(vector<int>::iterator iter = ivec.begin() ; iter != ivec.end() ; ++iter){
		if(*iter % 2 == 0){
			iter = ivec.erase(iter);
			--iter;
		}
	}
	
	for(list<int>::iterator iter = ilist.begin() ; iter != ilist.end() ; ++iter){
		if(*iter % 2 != 0){
			iter = ilist.erase(iter);
			--iter;
		}
	}
	
	return;
}
