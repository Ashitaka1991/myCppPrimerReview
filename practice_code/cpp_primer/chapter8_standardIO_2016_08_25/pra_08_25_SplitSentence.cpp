#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool fileToVector(string f_name,vector<string>& lines_v);
void splitWords(vector<string>& lines_v);

int main()
{
	string file_name;
	vector<string> lines_vec;
	
	cout << "Please input file name : ";
	cin >> file_name;
	
	fileToVector(file_name,lines_vec);
	splitWords(lines_vec);
	
	return 0;
}


bool fileToVector(string f_name,vector<string>& lines_v)
{
	ifstream in_file(f_name.c_str());
	string t_line;
	
	if(!in_file){
		return false;
	}
	
	while(getline(in_file,t_line)){
		lines_v.push_back(t_line);
	}
	
	in_file.close();
	
	return true;
}


void splitWords(vector<string>& lines_v)
{
	istringstream isstream;
	string word;
	
	for(vector<string>::iterator iter = lines_v.begin();
			iter != lines_v.end();++iter){
		
		isstream.str(*iter);//bind string
		while(isstream >> word){
			cout << word << endl;
		}
		isstream.clear();		
	}
	
	return;
}
