#include <iostream>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	int length=N*2-1;
	for(int i=0; i<length; i++) {
		if(i<N) {
			for(int j=0; j<=i; j++) cout<<"*";
			cout<<endl;
		} else {
			for(int j=0; j<length-i; j++) cout<<"*";
			cout<<endl;
		}
	}
	
	return 0;
}

/*
boj.kr/2523

INPUT:
3

OUTPUT:
*
**
***
**
*

*/
