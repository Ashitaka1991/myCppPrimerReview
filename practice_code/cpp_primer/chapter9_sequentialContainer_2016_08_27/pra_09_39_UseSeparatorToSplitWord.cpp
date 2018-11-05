#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string line1 = "We were her pride of 10 she named us: ";
	string line2 = "Benjamin, Phoenix, the Prodigal";
	string line3 = "and perspicacious pacific Suzanne";
	string sentence = line1 + ' ' + line2 + ' ' + line3;
	
	string separators(" \t:,\v\r\n\f");
	string word;
	
	string::size_type maxLen,minLen,wordLen,count=0;
	vector<string> longestWords,shortestWords;
	string::size_type startPos = 0,endPos = 0;
	
	while((startPos = sentence.find_first_not_of(separators,endPos)) != string::npos){
		++count;
		
		endPos = sentence.find_first_of(separators,startPos);
		
		if(endPos == string::npos){
			wordLen = sentence.size() - startPos;
		}
		else{
			wordLen = endPos - startPos;
		}
		
		word.clear();
		word.assign(sentence.begin() + startPos , sentence.begin() + startPos + wordLen);
		
		//startPos = sentence.find_first_not_of(separators,endPos);
		
		cout << word << endl;
		
		//find minmax word
		if(count == 1){
			maxLen = minLen = wordLen;
			longestWords.push_back(word);
			shortestWords.push_back(word);
		}
		else{
			if(wordLen > maxLen){
				longestWords.clear();
				longestWords.push_back(word);
			}
			else if(wordLen == maxLen){
				longestWords.push_back(word);
			}
			else if(wordLen < minLen){
				shortestWords.clear();
				shortestWords.push_back(word);
			}
			else if(wordLen == minLen){
				shortestWords.push_back(word);
			}
			else{
				;
			}
		}
		
	}
	
	//display data
	cout << endl << endl;
	cout << "word amount : " << count << endl << endl;
	
	cout << "longest word(s) : ";
	for(vector<string>::iterator iter = longestWords.begin() ; iter != longestWords.end() ; ++iter){
		cout << *iter << " ";
	}
	cout << endl << endl;
	
	cout << "shortest word(s) : ";
	for(vector<string>::iterator iter = shortestWords.begin() ; iter != shortestWords.end() ; ++iter){
		cout << *iter << " ";
	}
	cout << endl;
	
	return 0;
}
