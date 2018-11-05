#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	string str = "This is a Exmaple";
	for(string::iterator iter = str.begin() ; iter != str.end() ; ++iter){
		if(isupper(*iter)){
			iter = str.erase(iter);
			--iter;
		}
	}
	
	cout <<  str;
	
	return 0;
}
