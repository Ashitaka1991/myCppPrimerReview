#include <iostream>
#include <string>
#include <deque>
#include <vector>

using namespace std;

void handlePathFacade(vector<string>& ori_ps,vector<string>& abs_ps,deque<string>& path,string cur_path);
void checkRootPath(string& line,string cur_path,deque<string>& path);
void analyzePath(string& line,deque<string>& path,vector<string>& abs_ps);
void splitPath(string& line,deque<string>& path);

int main()
{
	int p_n;
	vector<string> ori_psv;
	vector<string> abs_psv;
	deque<string> path;
	string line;
	string cur_path;
	string sp("/");
	
	cin >> p_n;
	cin >> cur_path;
	for(int i = 0 ; i < p_n ; ++i){
		cin >> line;
		ori_psv.push_back(line);
	}
	
//	for(vector<string>::iterator iter = ori_psv.begin() ; iter != ori_psv.end() ; ++iter){
//		cout << *iter << endl;
//	}
	
	handlePathFacade(ori_psv,abs_psv,path,cur_path);

	//cout << endl;
	for(vector<string>::iterator iter = abs_psv.begin() ; iter != abs_psv.end() ; ++iter){
		cout << *iter << endl;
	}


	
	return 0;
}


void handlePathFacade(vector<string>& ori_ps,vector<string>& abs_ps,deque<string>& path,string cur_path)
{
	for(vector<string>::iterator iter = ori_ps.begin() ; iter != ori_ps.end() ; ++iter){
		path.clear();
		checkRootPath(*iter,cur_path,path);
		analyzePath(*iter,path,abs_ps);
	}
	
	return;
}


void checkRootPath(string& line,string cur_path,deque<string>& path)
{
	string sp("/");
	string::size_type f_pos;
	
	f_pos = line.find(sp);
	if(f_pos != 0 ){
		splitPath(cur_path,path);
	}
	else{
		;
	}
	
	return;
}


void splitPath(string& line,deque<string>& path)
{
	string::size_type s_pos = 0;
	string::size_type e_pos = 0;
	string::size_type len = 0;
	string sp("/");
	string cnode;
	
	while((s_pos = line.find_first_not_of(sp,e_pos)) != string::npos){
		e_pos = line.find_first_of(sp,s_pos);
		len = e_pos - s_pos;
		
		cnode = line.substr(s_pos,len);
		if(cnode == "."){
			;
		}
		else if(cnode == ".."){
			if(path.empty()){
				;
			}
			else{
				path.pop_back();
			}
			
		}
		else{
			path.push_back(cnode);
		}
		//cout << cnode << endl;
	}
	
	return;
}

void analyzePath(string& line,deque<string>& path,vector<string>& abs_ps)
{
	string abs_p;
	string sp("/");
	splitPath(line,path);
	
	for(deque<string>::iterator iter = path.begin() ; iter != path.end() ; ++iter){
		abs_p.append(sp);
		abs_p.append(*iter);
	}
	
	if(path.empty()){
		abs_p.append(sp);
	}
	
	abs_ps.push_back(abs_p);
	
	return;
}
