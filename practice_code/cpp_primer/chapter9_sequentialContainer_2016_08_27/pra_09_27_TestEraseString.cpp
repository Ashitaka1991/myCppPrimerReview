#include <iostream>
#include <string>
#include <list>

using namespace std;

bool eraseCertainWord(list<string>& l_words,string k_word);

int main()
{
	string t_word;
	list<string> words;
	
	cout << "Please input some words : ";
	while(cin >> t_word){
		words.push_back(t_word);
	}
	cin.clear();
	
	cout << "Please input key word : ";
	cin >> t_word;
	
	if(eraseCertainWord(words,t_word))
	{
		for(list<string>::iterator iter = words.begin() ; iter != words.end() ; ++iter){
			cout << *iter << " ";
		}
	}
	else{
		cout << "Didn't find the key word!";
	}
	
	return 0;
}


bool eraseCertainWord(list<string>& l_words,string k_word)
{
	int count_erase = 0;
	
	for(list<string>::iterator iter = l_words.begin() ; iter != l_words.end() ; ++iter){
		if(*iter == k_word){
			iter = l_words.erase(iter);
			--iter;
			++count_erase;
		}
	}
	
	if(count_erase != 0){
		return true;
	}
	else{
		return false;
	}
}
