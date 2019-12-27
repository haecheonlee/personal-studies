#include <iostream>

using namespace std;

int main() {
	int a=0,b=0;
	cin>>a>>b;
	
	int l=a*b;
	while(b != 0) {
		int r=a%b;
		a=b;
		b=r;
	}
	
	cout<<a<<endl<<l/a;

	return 0;
}

/*
boj.kr/2609

INPUT:
24 18

OUTPUT:
6
72
*/
