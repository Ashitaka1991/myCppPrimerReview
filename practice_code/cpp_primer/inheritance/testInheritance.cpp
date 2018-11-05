#include <iostream>

using namespace std;

class A{
public:
	void pubA();
protected:
	void proA();
private:
	void priA();
};

void A::pubA()
{
	cout << "This is Public function from class A!" << endl;
	
	return;
}

void A::proA()
{
	cout << "This is Protected function from class A!" << endl;
	
	return;
}

void A::priA()
{
	cout << "This is Private function from class A!" << endl;
	
	return;
}

class B:public A{
public:
	void pubB();
protected:
	void proB();
private:
	void priB();
};

void B::pubB()
{
	cout << "This is Public function from class B!" << endl;
	this->proA();

	
	return;
}

void B::proB()
{
	cout << "This is Protected function from class B!" << endl;
	
	return;
}

void B::priB()
{
	cout << "This is Private function from class B!" << endl;
	
	return;
}


int main()
{
	A a;
	B b;
		
	b.pubB();
	b.pubA();
	
	return 0;
}


