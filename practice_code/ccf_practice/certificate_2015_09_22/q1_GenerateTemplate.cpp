#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

//#define INF

using namespace std;

void splitValueLine(int,vector<string>&,map<string,string>&);
void replaceVariable(int,vector<string>&,map<string,string>&);

int main()
{
	int nl,nv;
	int i,j;
	vector<string> lines;
	vector<string> value_lines;
	map<string,string> value_map;
	string line;
	string word;
	
#ifdef INF
	fstream in_file("q3.txt");
	
	in_file >> nl >> nv;
	getline(in_file,line);
	for(i = 0 ; i < nl ; ++i){
		getline(in_file,line);
		lines.push_back(line);
	}
	for(i = 0 ; i < nv ; ++i){
		getline(in_file,line);
		value_lines.push_back(line);
	}
#endif
	
#ifndef INF
	cin >> nl >> nv;
	getline(cin,line);
	for(i = 0 ; i < nl ;++i){
		getline(cin,line);
		lines.push_back(line);
	}
	for(i = 0 ; i < nv ; ++i){
		getline(cin,line);
		value_lines.push_back(line);
	}
#endif
	//operation
	splitValueLine(nv,value_lines,value_map);
	replaceVariable(nl,lines,value_map);
	
	//display
	for(i = 0 ; i < nl ; ++i){
		cout << lines[i] << endl;
	}
	
	return 0;
}


void splitValueLine(int vn,vector<string>& v_lines,map<string,string>& v_map)
{
	string v_name;
	string v_value;
	string t_line;
	int i;
	string::size_type spos,epos;
	
	for(i = 0 ; i < vn ; ++i){
		t_line = v_lines[i];
		
		//split
		spos = 0;
		epos = t_line.find_first_of(" ");
		v_name = t_line.substr(spos,epos);
		//cout << v_name << endl;
		spos = t_line.find_first_of("\"");
		spos += 1;
		epos = t_line.rfind("\"");
		v_value = t_line.substr(spos,epos-spos);
		//cout << v_value << endl;
		v_map[v_name] = v_value;
	}
	
	return;
}


void replaceVariable(int ln,vector<string>& n_lines,map<string,string>& v_map)
{
	int i;
	string pre_v("{{ ");
	string post_v(" }}");
	string t_val;
	string::size_type spos,epos,wpos,ewpos;
	
	for(i = 0 ; i < ln ; ++i){
		string& c_line = n_lines[i];
		spos = epos = wpos = 0;
		//find
//		while((spos = c_line.find(pre_v,epos)) != string::npos){
//			wpos = c_line.find_first_not_of(pre_v,spos);
//			epos = c_line.find(post_v,spos);
//			
//			t_val = c_line.substr(wpos,(epos-wpos));
//			cout << "variable : " << t_val << endl;
//		}
		//reverse repalce
		epos = c_line.size();
		while((spos = c_line.rfind(pre_v,epos)) != string::npos){
			wpos = c_line.find_first_not_of(pre_v,spos);
			epos = c_line.find(post_v,spos);
			ewpos = c_line.find_first_not_of(post_v,epos);
			
			t_val = c_line.substr(wpos,(epos-wpos));
			//cout << "variable : " << t_val << endl;
			
			string::iterator bit,eit;
			bit = c_line.begin();
			eit = bit + ewpos;
			bit += spos;
			
			c_line.replace(bit,eit,v_map[t_val]);
		}
		
		
	}
	
	return;
}
