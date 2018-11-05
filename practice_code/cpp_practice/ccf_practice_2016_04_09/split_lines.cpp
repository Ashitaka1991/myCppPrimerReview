#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

fstream in_file("p1.txt");

int main()
{
	string line;
	string word;
	vector<string> lines;
	vector<string> words;
	
	while(getline(in_file,line)){
		lines.push_back(line);
	}
	
	vector<string>::iterator iter = lines.begin();
	for(;iter != lines.end();++iter){
		istringstream sline(*iter);
		
		while(sline >> word){
			cout << word << endl;
		}
		cout << endl << endl << endl;
	}
	
	
	return 0;
}
