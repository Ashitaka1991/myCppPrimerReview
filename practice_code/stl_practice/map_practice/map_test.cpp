#include <iostream>
#include <iterator>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

void displayMap(const string& str , map<int,int>& mp);

int main()
{
	//set and map are constructed as balanced binary tree
	const int N = 10;
	map<int,int> m_1;
	typedef pair<int,int> IntP;
	
	for(int i = 0 ; i < N ; ++i){
		m_1.insert(IntP(i,i*N));
	}
	displayMap("Test",m_1);
	
	return 0;
}


void displayMap(const string& str , map<int,int>& mp)
{
	cout << str << " : ";
	
	map<int,int>::iterator iter = mp.begin();
	for(;iter != mp.end() ; ++iter){
		cout << (*iter).first << " " << (*iter).second << "  ";
	}
	cout << endl;
}
