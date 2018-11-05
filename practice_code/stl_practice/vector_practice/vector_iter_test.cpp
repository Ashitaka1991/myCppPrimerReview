#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> t_v;
	for(int i = 1 ; i < 101 ; ++i){
		t_v.push_back(i);
	}
	
	vector<int>::iterator iter;
	iter = t_v.begin();
	cout << "begin iter : " << *iter << endl;
	
	--iter;
	++iter;
	cout << "--++  iter : " << *iter << endl;
	
	--iter;
	cout << "--begin iter : " << *iter << endl;
	
	return 0;
}
