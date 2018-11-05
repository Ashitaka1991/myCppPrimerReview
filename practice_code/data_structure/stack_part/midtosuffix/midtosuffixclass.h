#ifndef MIDTOSUFFIXCLASS_H
#define MIDTOSUFFIXCLASS_H

#include <vector>
#include <stack>
#include <string>

using namespace std;

class MidToSuffixClass{
	
public:
	MidToSuffixClass();
	
	void setExpression(string exp);
	string getSuffixExpression();
	double getExpressionValue();
	
private:
	enum{
		LOW = -1,
		EQU = 0,
		PRE = 1
	};
	
	vector<char> exp_vec;
	stack<char> opr_stack;
	stack<double> cal_stack;
	string suf_exp;
	
	int getPrecedenceValue(char s_top , char cur_c);
	void analyzingChar(char t_c);
	double calculatingExpression();
	double calculatingOneStep(double f_d , double s_d , char opr_c);
};



#endif
