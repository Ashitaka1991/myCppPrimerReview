#include <iostream>
#include <vector>
#include <list>

using namespace std;

bool isIdenticalContainer(vector<int>& iv , list<int>& il);

int main(){
	
	vector<int> ivec;
	list<int> ilist;
	int t_num;
	
	cout << "Input numbers to append to vector : ";
	while(cin >> t_num){
		ivec.push_back(t_num);
	}
	cin.clear();
	
	cout << "Input numbers to append to list : ";
	while(cin >> t_num){
		ilist.push_back(t_num);
	}
	
	if(isIdenticalContainer(ivec,ilist)){
		cout << "Identical" << endl;
	}
	else{
		cout << "Different" << endl;
	}
	
	return 0;
}


bool isIdenticalContainer(vector<int>& iv , list<int>& il)
{
	vector<int>::iterator v_it = iv.begin();
	list<int>::iterator l_it = il.begin();
	
	while((v_it != iv.end()) && (l_it != il.end())){
		if(*v_it != *l_it){
			return false;
		}
		++v_it;
		++l_it;
	}
	
	if((v_it == iv.end()) && (l_it == il.end())){
		return true;
	}
	else{
		return false;
	}
}
