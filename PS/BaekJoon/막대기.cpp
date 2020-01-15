#include <iostream>

using namespace std;

int main() {
	int X;
	cin>>X;
	
	int count=0;
	while(X!=0) {
		int S=64;
		
		while(S>X) S/=2;
		
		if(S<=X) {
			X-=S;
			count++;
		}
	}

	cout<<count;
	return 0;
}

/*
boj.kr/1094

INPUT:
48

OUTPUT:
2
*/
