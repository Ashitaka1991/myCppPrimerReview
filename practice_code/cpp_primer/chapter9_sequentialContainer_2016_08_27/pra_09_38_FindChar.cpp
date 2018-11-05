#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = "ab2c3d7R4E6";
	string numerics("0123456789");
	string letters("abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	string::size_type pos = 0;
	
	while((pos = str.find_first_of(numerics,pos)) != string::npos){
		cout << "found number at index: " << pos
			 << " element is " << str[pos] << endl;
		++pos;
	}
	
	cout << endl;
	pos = 0;
	while((pos = str.find_first_of(letters,pos)) != string::npos){
		cout << "found letter at index: " << pos
			 << " element is " << str[pos] << endl;
		++pos;
	}
		
	return 0;
}
