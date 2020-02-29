#include <iostream>

using namespace std;

int main() {
	int result=0;
	int l,r;
	cin>>l>>r;
	
	int b=2;
	while(1) {
		l=l*r/100;
		if(l<=5) break;
		result+=(l*b);
		b*=2;
	}
	
	cout<<result;
	
	return 0;
}

/*
boj.kr/17283

INPUT:
500
30

OUTPUT:
584
*/
