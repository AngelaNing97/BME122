#include <iostream>
using namespace std;
struct S{
	int val;
	S(int v):val{v} {
		cout <<"SV: "<<val<<endl;
	}
	S(const S &v) {
		val = v.val;
		cout<<"CC:" <<val<<endl;
	}
	S& operator= (const S &v) {
		val=v.val;
		cout<<"AO:" <<val<<endl;
		return *this;
	}
	};
	
	const S operator+(const S first, const S second) {
		return S(first.val+second.val);
	}


int main() {
	S a{20};
	cout<<"---"<<endl;
	S b{a};
	cout<<"---"<<endl;
	a =50;
	cout<<"---"<<endl;
	a=b+b;
}
