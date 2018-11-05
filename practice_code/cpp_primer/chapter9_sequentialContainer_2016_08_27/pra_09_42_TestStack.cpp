#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	stack<string> sstack;
	string word;
	
	cout << "enter some words : ";
	while(cin >> word){
		sstack.push(word);
	}
	
	cout << "Pop the words : " << endl;
	while(!sstack.empty()){
		cout << sstack.top() << endl;
		sstack.pop();
	}
	
	return 0;
}
