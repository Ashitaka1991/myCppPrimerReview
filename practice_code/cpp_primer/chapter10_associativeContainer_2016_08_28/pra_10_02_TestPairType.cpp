#include <iostream>
#include <utility>
#include <string>
#include <vector>

using namespace std;

void initNewPair(vector< pair<string,int> >& pvec);
void changeMembersOfPair(vector< pair<string,int> >& pvec);
void useMakePair(vector< pair<string,int> >& pvec);
void displayPairVector(string title,vector< pair<string,int> >& pvec);

int main()
{
	vector< pair<string,int> > pvec;
	
	initNewPair(pvec);
	changeMembersOfPair(pvec);
	useMakePair(pvec);	
	
	return 0;
}


void initNewPair(vector< pair<string,int> >& pvec)
{
	int ival;
	string sval;
	
	cout << "Please input pair values : " << endl;
	
	while(cin >> sval >> ival){
		pair<string,int> sipr(sval,ival);
		pvec.push_back(sipr);
	}	
	cin.clear();
	
	string promote("Initial New Pair : ");
	displayPairVector(promote,pvec);
	
	pvec.clear();
	return;
}

void changeMembersOfPair(vector< pair<string,int> >& pvec)
{
	int ival;
	string sval;
	pair<string,int> sipr;
	
	cout << "Please input pair values : " << endl;
	
	while(cin >> sval >> ival){
		sipr.first = sval;
		sipr.second = ival;
		
		pvec.push_back(sipr);
	}	
	cin.clear();
	
	string promote("Change Pair Members : ");
	displayPairVector(promote,pvec);
	
	pvec.clear();
	return;
	
	
}
void useMakePair(vector< pair<string,int> >& pvec)
{
	int ival;
	string sval;
	pair<string,int> sipr;
	
	cout << "Please input pair values : " << endl;
	
	while(cin >> sval >> ival){
		sipr = make_pair(sval,ival);
		pvec.push_back(sipr);
	}	
	cin.clear();
	
	string promote("Use Make_Pair : ");
	displayPairVector(promote,pvec);
	
	pvec.clear();
	return;
	
	
}


void displayPairVector(string title,vector< pair<string,int> >& pvec)
{
	cout << title << endl;
	for(int i = 0 ; i < pvec.size() ; ++i){
		cout << pvec[i].first << "  " << pvec[i].second << endl;
	}
	cout << endl << endl;
	
	return;
}
