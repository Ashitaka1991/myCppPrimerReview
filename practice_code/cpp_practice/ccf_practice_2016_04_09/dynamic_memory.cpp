#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//fstream in_file("p2.txt");

int main()
{
	int row = 0;
	int line = 0;
	int *line_p = 0;
	
	vector<int*> rows;
	
//	in_file >> line >> row;
	cin >> line >> row;
		
	int i = 0;
	int j = 0;
	for(;i < line;++i){
		rows.push_back(new int[row]());
	}
	
	for(i = 0 ; i < line ; ++i){
		for(j = 0 ; j < row ; ++j){
			//in_file >> rows[i][j];
			cin >> rows[i][j];
		}
	}
	
	for(i = 0 ; i < line ; ++i){
		for(j = 0 ; j < row ; ++j){
			cout << rows[i][j] << ' ';
		}
		cout << endl;
	}
	
	for(i = 0 ; i < line ; ++i){
		delete [] rows[i];
		rows[i] = 0;
	}
	
	return 0;
}
