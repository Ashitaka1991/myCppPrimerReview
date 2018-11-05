#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

void displaySet(const string& str , set<int>& st);

int main()
{
	const int N = 15;
	set<int> s_1;
	for(int i = 0 ; i < N ; ++i){
		s_1.insert(i);
	}
	displaySet("Test",s_1);
	
	//it also has reverse iterator
	
	//insert in specific position
	s_1.insert(--s_1.end(),15);
	displaySet("Insert",s_1);
	
	//the type of return value is a pair , pair<set<int>::iterator,bool>
	s_1.erase(5);
	displaySet("Erase 5",s_1);
	
	//functions of set
	cout << "Num of 5 in s_1 : " << s_1.count(5) << "   Num of 15 in s_1 : " << s_1.count(15) << endl;
	
	//find
	set<int>::iterator iter = s_1.find(5);
	if(iter == s_1.end()){
		cout << "Can not find 5 in s_1!" << endl;
	}
	else{
		cout << "Find 5 in s_1!" << endl;
	}
	
	//equal_range returns a pair of iterator for multiset
	
	//lower_bound returns the same iter of the key
	
	//upper_bound returns the following iter of the key
	
	
	//compare
	//need to review
	
	return 0;
}


void displaySet(const string& str , set<int>& st)
{
	ostream_iterator<int> out(cout," ");
	cout << str << " : ";
	copy(st.begin(),st.end(),out);
	cout << endl;
}
