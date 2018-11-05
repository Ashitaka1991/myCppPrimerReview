#include <iostream>
#include <string>

using namespace std;

string greet(string form,string lastname,string title,string::size_type pos,int length);

int main()
{
	string generic1("Dear Ms Daisy:");
	string generic2("MrsMsMissPeople");
	
	string lastName("AnnaP");
	string salute = greet(generic1,lastName,generic2,5,4);
	
	cout << salute;
	
	return 0;
}


string greet(string form,string lastname,string title,string::size_type pos,int length)
{
	string::iterator begi,endi;
	begi = form.begin() + form.find("Daisy");
	endi = begi + 5;
	form.replace(begi,endi,lastname);
	
	begi = form.begin() + form.find("Ms");
	endi = begi + 2;
	form.replace(begi,endi,title.substr(pos,length));
	
	return form;
	
}
