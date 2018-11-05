#include <iostream>

using namespace std;

int main()
{
	int n = 100;
	int m = 9;
	int s = 0;
	
	for(int i = 2 ; i <= n ; ++i)
		s = (s+m)%i;
	
	cout << s+1 << endl;
	
	return 0;
}
