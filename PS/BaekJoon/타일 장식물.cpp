#include <iostream>

using namespace std;

int main() {
	long long d[81];
	
	int n;
	cin>>n;
	
	d[0]=1;d[1]=1;
	for(int i=2; i<=n; i++) d[i]=d[i-1]+d[i-2];

	cout<<(d[n-1]+d[n])*2;

	return 0;
}

/*
boj.kr/13301

INPUT:
5

OUTPUT:
26
*/
