#include <iostream>
#include <string>

#include "midtosuffixclass.h"

using namespace std;

int main()
{
	string input_exp;
	MidToSuffixClass mts;
	
	cout << "Please input a expression : ";
	cin >> input_exp; 
	
	mts.setExpression(input_exp);
	
	cout << "Suffix Expression : " << mts.getSuffixExpression() << endl;
	cout << "Value of expression : " << mts.getExpressionValue() << endl;
	
	return 0;
}
