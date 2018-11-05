#include <iostream>
#include <string>

//#define GETLINE
#define CIN

using namespace std;

int main()
{
	string line;
	
#ifdef GETLINE
	while(getline(cin,line))
		cout << line << endl;
#endif

#ifdef CIN
	while(cin >> line)
		cout << line << endl;
#endif  
	return 0;	
}
