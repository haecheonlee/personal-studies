#include <iostream>

using namespace std;

int main() {
	int A=-1, B=-1;

	while(1) {
		cin>>A>>B;
		
		if(A == 0 && B == 0) break;
		if(A%B==0) {
			cout<<"multiple"<<endl;
		} else if(B%A==0) {
			cout<<"factor"<<endl;
		} else {
			cout<<"neither"<<endl;
		}
	}

	return 0;
}

/*
boj.kr/5086

INPUT:
8 16
32 4
17 5
0 0

OUTPUT:
factor
multiple
neither
*/
