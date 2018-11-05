#include <iostream>
#include <vector>

#define LINE 15
#define ROW 10
#define BLOCK 4

using namespace std;

int findStartRow(vector<int*>& block);
int findLines(vector<int*>& block);
int findAttachingLine(int s_row,vector<int*>& map , vector<int*>& block);
void pendingBlock(int p_line,int p_row,vector<int*>& map , vector<int*>& block);

int main()
{
	vector<int*> map;
	vector<int*> block;
	int *t_p;
	int start_row;
	
	for(int i = 0 ; i < LINE ; ++i){
		t_p = new int[ROW];
		for(int j = 0 ; j < ROW ; ++j){
			cin >> t_p[j];
		}
		map.push_back(t_p);
	}
	
	for(int i = 0 ; i < BLOCK ; ++i){
		t_p = new int[BLOCK];
		for(int j = 0 ; j < BLOCK ; j++){
			cin >> t_p[j];
		}
		block.push_back(t_p);
	}
	
	cin >> start_row;
	
	
	//operation
	int sp_line = findAttachingLine(start_row,map,block);
	pendingBlock(sp_line,start_row,map ,block);
//	cout << "Start Line : " << start_line << endl;
//	cout << "Start Row  : " << start_row << endl;
 	
	for(int i = 0 ; i < LINE ; ++i){
		for(int j = 0 ; j < ROW ; ++j){
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
	
//	for(int i = 0 ; i < BLOCK ; ++i){
//		for(int j = 0 ; j < BLOCK ; ++j){
//			cout << block[i][j] << ' ';
//		}
//		cout << endl;
//	}
	
	for(int i = 0 ; i < LINE ; i++){
		delete [] map[i];
	}
	for(int i = 0 ; i < BLOCK ; ++i){
		delete [] block[i];
	}
	
	return 0;
}

int findStartRow(vector<int*>& block)
{
	for(int i = 0 ; i < BLOCK ; ++i){
		for(int j = 0 ; j < BLOCK ; ++j){
			if(block[j][i] == 1){
				return i;
			}
		}
	}
	
	return BLOCK;
}
int findLines(vector<int*>& block)
{
	for(int i = 0 ; i < BLOCK ; ++i){
		for(int j = 0 ; j < BLOCK ; ++j){
			if(block[BLOCK-1-i][j] == 1){
				return (BLOCK - i);
			}
		}
	}
	
	return 0;
}



int findAttachingLine(int s_row,vector<int*>& map , vector<int*>& block)
{
	int end_line = LINE - findLines(block);
	int rend_line = findLines(block);
	int start_r = findStartRow(block);
	
	for(int i = 0 ; i < end_line ; ++i){
		for(int j = 0 ; j < rend_line ; ++j){
			for(int k = 0 ; k < BLOCK - start_r ; ++k){
				if(block[j][k] == 1 && map[i+j][s_row+k] == 1)
					return (i - 1);
			}
		}
	}
	
	return (end_line - 1);
}

void pendingBlock(int p_line,int p_row,vector<int*>& map , vector<int*>& block)
{
	int rend_line = findLines(block);
	int start_r = findStartRow(block);
	
	for(int i = 0 ; i < rend_line ; ++i){
		for(int j = 0 ; j < BLOCK - start_r ; ++j){
			if(block[i][j] == 1 &&  map[p_line+i][p_row+j] == 0){
				map[p_line+i][p_row+j] = 1;
			}
		}
	}
	
	return;
}
