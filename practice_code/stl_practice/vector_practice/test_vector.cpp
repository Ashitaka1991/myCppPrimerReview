#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void displayVector(const string& , vector<int>&);

//function object , it may have constructor
class FindANumberForAFormula{
public:
	bool operator() (int& n) {
		return n*n == n+n;
	}
};

int main() {
	
	const int N = 15;
	vector<int> v_1;
	
	for(int i = 0 ; i < N ; ++i){
		v_1.push_back(i);
	}
	displayVector("Test",v_1);
	
	//reserve()
	vector<int> v_2;
	v_2.reserve(N);
	for(int i = 0 ; i < N ; ++i){
		v_2[i] = i;
	}
	//can not use iterator , the size of vector is not changed relatively
	displayVector("Reserve",v_2);
	cout << "Size: " << v_2.size() << "  Maximun Size: " << v_2.max_size() << "  Capacity: " << v_2.capacity() << endl;
	 
	//count() count_if() function object
//	auto a = v_2[3];
//	cout << a << endl;

/*count()*/
//	int num = count(v_1.begin(),v_1.end(),5);
//	cout << num;

/*lambda for count_if()*/
//	int num = count_if(v_1.begin(),v_1.end(),[](int& a){
//		return a == 3;
//	});
//	cout << num;
	
/*function object for count_if()*/
//	int num = count_if(v_1.begin(),v_1.end(),FindANumberForAFormula());	
//	cout << num;
	
//algorithm for vector
	vector<int>::iterator find_iter = find(v_1.begin(),v_1.end(),12);
	find_iter = find(v_1.begin(),v_1.end(),N);
	if(find_iter == v_1.end()){
		cout << "Can Not Find!" << endl;
	}
	else{
		cout << "Find " << *find_iter << " in vector!" << endl;
	}

//lambda for find_if()
	vector<int>::iterator findif_it = find_if(v_1.begin(),v_1.end(),[](int& n){
		return n*n == n + 6;
	});
	if(findif_it == v_1.end()){
		cout << "Can not Find to match the condition!" << endl;
	}
	else{
		cout << "Find " << *findif_it << " to match the conditon!" << endl;
	}

//search() for vector
	vector<int> sub_vec;
	sub_vec.push_back(11);
	sub_vec.push_back(12);
	sub_vec.push_back(13);
	sub_vec.push_back(14);
	
	vector<int>::iterator ser_iter = search(v_1.begin(),v_1.end(),sub_vec.begin(),sub_vec.end());
	if(ser_iter == v_1.end()){
		cout << "Can not find sub vector!" << endl;
	}
	else{
		cout << "Find sub vector in " << *ser_iter << endl;
	}

/************************************************************************/
//algorithms may change order
	
	//insert,new element will be inserted in the front of the iter by default
	//if you want to insert element after the iter,use ++iter
	vector<int> v_3(v_1.begin(),v_1.end());
	for(vector<int>::iterator iter = v_3.begin() ; iter != v_3.end() ; ++iter){
		if(*iter == 5){
			//necessary
			iter = v_3.insert(iter,0);
			++iter;
		}
	}
	displayVector("Insert By Default : ", v_3);
	
	//insert after the iter
	for(vector<int>::iterator iter = v_3.begin() ; iter != v_3.end() ; ++iter){
		if(*iter == 5){
			iter = v_3.insert(++iter,1);
		}
	}
	displayVector("Insert 1 after 5 : " , v_3);
	
	//erase , the position after erase() is after the iter by default
	for(vector<int>::iterator iter = v_3.begin() ; iter != v_3.end() ; ++iter){
		if(*iter == 5){
			iter = v_3.insert(++iter,5);
		}
	}
	for(vector<int>::iterator iter = v_3.begin() ; iter != v_3.end() ; ++iter){
		if(*iter == 5){
			iter = v_3.erase(iter);
		}
	}
	displayVector("Erase 5 : " , v_3);
	
	//use --iter
	for(vector<int>::iterator iter = v_3.begin() ; iter != v_3.end() ; ++iter){
		if(*iter == 5){
			iter = v_3.insert(++iter,5);
		}
	}
	for(vector<int>::iterator iter = v_3.begin() ; iter != v_3.end() ; ++iter){
		if(*iter == 5){
			iter = v_3.erase(iter);
			if(iter != v_3.begin())
				--iter;
		}
	}
	displayVector("Erase 5 : " , v_3);
	
	//remove algorithm
	cout << "The size before remove : " << v_3.size() << endl;
	displayVector("Before remove : " , v_3);
	vector<int>::iterator rm_iter = remove(v_3.begin(),v_3.end(),1);
	cout << "The size after remove : " << v_3.size() << endl;
	displayVector("After remove : " , v_3);
	v_3.erase(rm_iter,v_3.end()); 
	displayVector("After Erase the tail" , v_3);
	
	//swap
	cout << "Before swap!" << endl;
	displayVector("Vec1 " , v_1);
	displayVector("Vec3 " , v_3);
	
	cout << "After in-built swap!" << endl;
	v_1.swap(v_3);
	displayVector("Vec1 " , v_1);
	displayVector("Vec3 " , v_3);
	
	cout << "After swap algorithm!" << endl;
	swap(v_1,v_3);
	displayVector("Vec1 " , v_1);
	displayVector("Vec3 " , v_3);
	
	return 0;
}


void displayVector(const string& str, vector<int>& vec){
	cout << str << ": ";
	for(vector<int>::iterator iter = vec.begin() ; iter != vec.end() ; ++iter){
		cout << *iter << "  ";
	}
	cout << endl;
}
