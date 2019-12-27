#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if(b == 0) {
		return a;
	} else {
		return gcd(b, a%b);
	}
}

int main() {
	int T;
	cin>>T;
	
	int a, b;
	for(int i=0; i<T; i++) {
		cin>>a>>b;
		
		int result = (a*b)/gcd(a, b);
		cout<<result<<'\n';
	}


	return 0;
}

/*
boj.kr/1934

INPUT:
3
1 45000
6 10
13 17

OUTPUT:
45000
30
221
*/
