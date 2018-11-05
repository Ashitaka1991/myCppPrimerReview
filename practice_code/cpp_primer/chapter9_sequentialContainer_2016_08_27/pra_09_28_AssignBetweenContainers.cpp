#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

void assignBetweenContainers(list<const char*>& strl,vector<const char*>& strv);

int main()
{
	const char* sa[] = {"Mary","Tom","Bob","Alice"};
	list<const char*> strl(sa,sa+4);
	vector<const char*> strv;
	
	assignBetweenContainers(strl,strv);
	
	for(vector<const char*>::iterator iter = strv.begin() ; iter != strv.end() ; ++iter){
		cout << *iter << endl;
	}
	
	return 0;
}


void assignBetweenContainers(list<const char*>& strl,vector<const char*>& strv)
{
	strv.assign(strl.begin(),strl.end());
	
	return;
}
