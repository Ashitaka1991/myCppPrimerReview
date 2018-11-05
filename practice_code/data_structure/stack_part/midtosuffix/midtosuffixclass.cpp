#include "midtosuffixclass.h"
#include <iostream>

//#define MTSDEBUG


MidToSuffixClass::MidToSuffixClass()
{
	
}

//public functions
void MidToSuffixClass::setExpression(string exp)
{
	int n = exp.length();
	
#ifdef MTSDEBUG
	cout << "Length of expression : " << n << endl;
#endif

	
	for(int i = 0 ; i < n ; ++i){
		analyzingChar(exp[i]);
	}

#ifdef MTSDEBUG
	cout << "Size of Stack : " << opr_stack.size() << endl;
#endif	
	
	while(!opr_stack.empty()){
		exp_vec.push_back(opr_stack.top());
		opr_stack.pop();
	}
	
	return;
}

string MidToSuffixClass::getSuffixExpression()
{
	int n = exp_vec.size();
	for(int i = 0 ; i < n ;++i){
		suf_exp.push_back(exp_vec[i]);
	}
	
	return suf_exp;
}

double MidToSuffixClass::getExpressionValue()
{
	return calculatingExpression();
}

//private functions
int MidToSuffixClass::getPrecedenceValue(char s_top , char cur_c)
{
	if(s_top == '('){
		return LOW;
	}
	
	if((s_top == '+') || (s_top == '-')){
		if((cur_c == '*') || (cur_c == '/')){
			return LOW;
		}
		else{
			return EQU;
		}
	}
	
	if((s_top == '*') || (s_top == '/')){
		if((cur_c == '+') || (cur_c == '-')){
			return PRE;
		}
		else{
			return EQU;
		}
	}
}

void MidToSuffixClass::analyzingChar(char t_c)
{
	if(t_c == '('){
		opr_stack.push(t_c);
#ifdef MTSDEBUG
	cout << "Size of Stack after '(': " << opr_stack.size() << endl;
#endif
	}
	else if(t_c == ')'){
		while(opr_stack.top() != '('){
			exp_vec.push_back(opr_stack.top());
			opr_stack.pop();
		}
		opr_stack.pop();
#ifdef MTSDEBUG
	cout << "Size of Stack after ')': " << opr_stack.size() << endl;
#endif
	}
	else if((t_c >= '1') && (t_c <= '9')){
		exp_vec.push_back(t_c);
#ifdef MTSDEBUG
	cout << "Size of Stack after number : " << opr_stack.size() << endl;
	cout << "Size of Vector after number: " << exp_vec.size() << endl;
#endif
	}
	else{
		if(opr_stack.empty()){
			opr_stack.push(t_c);
			return;
		}
		
		int pre_value = getPrecedenceValue(opr_stack.top(),t_c);
		
		if(pre_value == LOW){
			opr_stack.push(t_c);
		}
		else{
			while((pre_value == EQU) || (pre_value == PRE)){
				exp_vec.push_back(opr_stack.top());
				opr_stack.pop();
				if(opr_stack.empty()){
					break;
				}
				pre_value = getPrecedenceValue(opr_stack.top(),t_c);
			}
			opr_stack.push(t_c);
		}
	}
	
	return;
}

double MidToSuffixClass::calculatingExpression()
{
	int n = suf_exp.size();
	char t_c;
	int t_i;
	double t_d;
	for(int i = 0 ; i < n ; ++i){
		t_c = suf_exp[i];
		if((t_c >= '1') && (t_c <= '9')){
			t_i = t_c - '0';
			cal_stack.push((double)t_i);
		}
		else{
			double f,s;
			s = cal_stack.top();
			cal_stack.pop();
			f = cal_stack.top();
			cal_stack.pop();	
			t_d = calculatingOneStep(f,s,t_c);
			cal_stack.push(t_d);
		}
	}
	
	return cal_stack.top();
}

double MidToSuffixClass::calculatingOneStep(double f_d , double s_d , char opr_c)
{
	switch(opr_c){
		case '+':
			return (f_d + s_d);
		case '-':
			return (f_d - s_d);
		case '*':
			return (f_d*s_d);
		case '/':
			return (f_d/s_d);
	}
}
