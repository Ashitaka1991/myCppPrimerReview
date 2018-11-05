#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n,times;
	int num,mov;
	list<int> sqc;
	vector<pair<int,int> > oprs;
	
	cin >> n;
	cin >> times;
	
	for(int i = 1 ; i <= n ; ++i){
		sqc.push_back(i);
	}
	
	for(int i = 0 ; i < times ; ++i){
		cin >> num >> mov;
		oprs.push_back(make_pair(num,mov));
		
	}
	
	vector<pair<int,int> >::iterator iter;
	list<int>::iterator liter,oliter;
	for(iter = oprs.begin() ; iter != oprs.end() ; ++iter){
		num = iter->first;
		mov = iter->second;
		
		liter = find(sqc.begin(),sqc.end(),num);
		oliter = sqc.erase(liter);
		if(mov < 0){
			for(int i = 0 ; i > mov ; --i){
				--oliter;
			}
		}
		else if(mov > 0){
			for(int i = 0 ; i < mov ; ++i){
				++oliter;
			}
		}
		
		sqc.insert(oliter,num);
	}
	
	for(liter = sqc.begin() ; liter != sqc.end() ; ++liter){
		cout << *liter << " ";
	}
	
	return 0;
}
