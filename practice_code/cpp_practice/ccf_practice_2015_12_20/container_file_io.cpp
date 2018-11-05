#include <iostream>
#include <string>
#include <list>

//#define WORDSVERSION
#define LINESVERSION

using namespace std;

int main()
{
	string a_word;
	string a_line;
	list<string> words_list;
	list<string> lines_list;
	
#ifdef WORDSVERSION	
	while(cin >> a_word){
		words_list.push_back(a_word);
	}
#endif

#ifdef LINESVERSION
	while(getline(cin,a_line)){
		lines_list.push_back(a_line);
	}
#endif
	
//	foreach(a_word,words_list){
//		cout << a_word;
//	}

#ifdef WORDSVERSION
	cout << "***************************************************************" << endl;
	for(list<string>::iterator iter = words_list.begin() ; iter != words_list.end() ; iter++){
		cout << *iter << endl;
	}
#endif
	
#ifdef LINESVERSION
	cout << "***************************************************************" << endl;
	for(list<string>::iterator iter = lines_list.begin() ; iter != lines_list.end() ; iter++){
		cout << *iter << endl;
	}
#endif


	
	return 0;
}
