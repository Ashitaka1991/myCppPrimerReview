#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>

#define WORD
//#define LINE 

using namespace std;

const string p1_file = "p1.txt";
fstream in_file(p1_file.c_str());

int main()
{
	string word;
	string line;
	vector<string> words;
	vector<string> lines;

#ifdef WORD	
//	while(in_file >> word){

	while(cin >> word){
		words.push_back(word);
	}
	
	vector<string>::iterator iter = words.begin();
	for(;iter != words.end();++iter){
		cout << *iter << endl;
	} 
#endif

#ifdef LINE
//	while(getline(in_file,line)){

	while(getline(cin,line)){
		lines.push_back(line);
	}
	
	vector<string>::iterator iter = lines.begin();
	for(;iter != lines.end();++iter){
		cout << *iter << endl;
	}
#endif
	
	return 0;
}
