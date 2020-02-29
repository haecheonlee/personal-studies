#include <iostream>

using namespace std;

int gcd(int a, int b){
	if(b==0) return a;
	
	return gcd(b, a%b);
}

int main() {
	int n,m;
	scanf("%d:%d",&n,&m);
	
	int r=gcd(n,m);
	cout<<n/r<<":"<<m/r;

	return 0;
}

/*
boj.kr/14490

INPUT:
18:24

OUTPUT:
3:4
*/
