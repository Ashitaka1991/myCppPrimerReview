#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

//#define INF

using namespace std;

class PointT{
public:
	int x;
	int y;
};

void drawLine(PointT sp,PointT ep,vector<char*>& canvas);
void paddingCharactor(PointT sp,char pc,int rn,vector<char*>& canvas);
bool isOutside(PointT sp,int rn,int ln);


int main()
{
	int rn,ln,on;
	int i,j,opr;
	vector<char*> canvas;
	char *t_p;
	PointT spt,ept;
	char padding_c;
	
#ifdef INF
	fstream in_file("q3.txt");
	in_file >> rn >> ln >> on;
#else
	cin >> rn >> ln >> on;
#endif
	
	
	
	//initial canvas
	for(i = 0 ; i < ln ; ++i){
		t_p = new char[rn];
		canvas.push_back(t_p);
	}
	//panding canvas
	for(i = 0 ; i < ln ; ++i){
		for(j = 0 ; j < rn ; ++j){
			canvas[i][j] = '.'; 
		}
	}
	
	//handle operation
#ifdef INF
	for(i = 0 ; i < on ; ++i){
		in_file >> opr;
		if(opr == 0){
			in_file >> spt.y >> spt.x >> ept.y >> ept.x;
			drawLine(spt,ept,canvas);
		}
		else if(opr == 1){
			in_file >> spt.y >> spt.x >> padding_c;
			paddingCharactor(spt,padding_c,rn,canvas);
		}
	}
#else
	for(i = 0 ; i < on ; ++i){
		cin >> opr;
		if(opr == 0){
			cin >> spt.y >> spt.x >> ept.y >> ept.x;
			drawLine(spt,ept,canvas);
		}
		else if(opr == 1){
			cin >> spt.y >> spt.x >> padding_c;
			paddingCharactor(spt,padding_c,rn,canvas);
		}
	}
#endif
	
	for(i = 0 ; i < ln ; ++i){
		for(j = 0 ; j < rn ; ++j){
			cout << canvas[i][j];
		}
		cout << endl;
	}
	
	//release memory
	for(i = 0 ; i < ln ; ++i){
		t_p = canvas[i];
		delete [] t_p;
	}
	
	return 0;
}


void drawLine(PointT sp,PointT ep,vector<char*>& canvas)
{
	int sc,ec,conc;
	int i,j;
	
	if(sp.x == ep.x){
		conc = sp.x;
		if(sp.y < ep.y){
			sc = sp.y;
			ec = ep.y;
		}
		else{
			sc = ep.y;
			ec = sp.y;
		}
		
		for(i = sc ; i <= ec ; ++i){
			if(canvas[conc][i] == '|'){
				canvas[conc][i] = '+';
			}
			else{
				canvas[conc][i] = '-';
			}
		}
	}
	else{
		conc = sp.y;
		if(sp.x < ep.x){
			sc = sp.x;
			ec = ep.x;
		}
		else{
			sc = ep.x;
			ec = sp.x;
		}
		
		for(i = sc ; i <= ec ; ++i){
			if(canvas[i][conc] == '-'){
				canvas[i][conc] = '+';
			}
			else{
				canvas[i][conc] = '|';
			}
		}
	}
	
}


void paddingCharactor(PointT sp,char pc,int rn,vector<char*>& canvas)
{
	//cout << "Padding char " << sp.x << "  " << sp.y << endl;
	
	int xc,yc;
	int ern;
	char cch;
	
	
	if(isOutside(sp,rn,canvas.size())){
		return;
	}
	else{
		xc = sp.x;
		yc = sp.y;
		ern = rn - 1;
		cch = canvas[xc][yc];
	}
	
	if( (cch == pc) || (cch == '-') || (cch == '|') || (cch == '+') ){
		//cout << "not pand and return" << endl;
		return;
	}
	else{
			canvas[xc][yc] = pc;
		
			sp.x = xc - 1;
			paddingCharactor(sp,pc,rn,canvas);		
			
			sp.x = xc + 1;
			paddingCharactor(sp,pc,rn,canvas);		
			
			sp.x = xc;
			sp.y = yc - 1;
			paddingCharactor(sp,pc,rn,canvas);		
			
			sp.x = xc;
			sp.y = yc + 1;
			paddingCharactor(sp,pc,rn,canvas);		
		}
		
	return;
}


bool isOutside(PointT sp,int rn,int ln){
	if((sp.x<0) || (sp.x >= ln) || (sp.y<0) || (sp.y>=rn)){
		//cout << "outside" << endl;
		return true;
	}
	else{
		return false;
	}
}
