#include<iostream>
#include <string>
using namespace std;
struct Binary{
	int size;
	bool *bits;

	Binary(int size) {
		if(size<1) {
			size=0;
			bits=nullptr;
		}else {
			this->size=size;
			bits=new bool[size];
			
		}
	}
	
	Binary(string s) {
		size = s.length();
	 	bits= new bool[size];
	 	for(int i=0; i<size;i++) {
	 		bits[i]=s[i];
	 		if(bits[i]==0) bits[i]=false;
	 		else bits[i]=true;
		 }
	}
	
	Binary(const Binary &b) {
		size=b.size;
		if(size<1) {
			size=0;
			bits=nullptr;
		}else{
					bits= new bool[size];
					for(int i=0; i<size; i++) {
			bits[i]=b.bits[i];
		}
		}
		
	}

};

	ostream& operator<<(ostream &out, const Binary& object) {
		for(int i=0; i<object.size; i++) {
			if(object.bits[i]) out<<1;
			else out<<0;
		}
//		out<<endl;
		return out;
	}
	
int main() {
	int i=1;
	cout<<++i<<endl;
 i=1;
	cout<<i++<<endl;

	}


