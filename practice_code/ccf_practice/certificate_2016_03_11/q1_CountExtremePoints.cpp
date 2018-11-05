#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n_num;
	int t_num;
	int count_exps;
	vector<int> pts;
	
	cin >> n_num;
	for(int i = 0 ; i < n_num ; i++){
		cin >> t_num;
		pts.push_back(t_num);
	}
	
	n_num -= 1;
	count_exps = 0;
	for(int i = 1 ; i < n_num ; i++){
		if((pts[i] < pts[i-1]) && (pts[i] < pts[i+1])){
			++count_exps;
		}
		else if((pts[i] > pts[i-1]) && (pts[i] > pts[i+1])){
			++count_exps;
		}
		else{
			;
		}
	}
	
	cout << count_exps;
	
	return 0;
}
