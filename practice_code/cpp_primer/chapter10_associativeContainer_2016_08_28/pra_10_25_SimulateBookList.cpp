#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	vector<string> books;
	set<string> readedBooks;
	string name;
	
	cout << "Enter names for books you'd like to read : " << endl;
	while(cin >> name){
		books.push_back(name);
	}
	cin.clear();
	
	bool timeOver = false;
	string answer,bookName;
	srand((unsigned)time(NULL));
	
	while(!timeOver && !books.empty()){
		cout << "Would you like to read a book?(Y/N)" << endl;
		cin >> answer;
		
		if(answer[0] == 'y' || answer[0] == 'Y'){
			int i = rand()%books.size();
			bookName = books[i];
			cout << "You can read this book : " << bookName << endl;
			readedBooks.insert(bookName);
			books.erase(books.begin() + i);
			
			cout << "Did you read it?(Y/N)" << endl;
			cin >> answer;
			if(answer[0] == 'n' || answer[0] == 'N'){
				readedBooks.erase(bookName);
				books.push_back(bookName);
			}
		}
		
		cout << "Time over?(Y/N)" << endl;
		cin >> answer;
		if(answer[0] == 'y' || answer[0] == 'Y'){
			timeOver = true;
		}
	}
	
	if(timeOver){
		cout << "books read : " << endl;
		for(set<string>::iterator sit = readedBooks.begin() ; sit != readedBooks.end() ; ++sit){
			cout << *sit << endl;
		}
		cout << endl;
		cout << "books not read : " << endl;
		for(vector<string>::iterator vit = books.begin() ; vit != books.end() ; ++vit){
			cout << *vit << endl;
		}
	}
	else{
		cout << "Congratulations! You have read all these books." << endl;
	}
	
	return 0;
}
