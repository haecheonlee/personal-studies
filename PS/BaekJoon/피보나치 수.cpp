#include <iostream>

using namespace std;

int main() {
	int d[50],n;
	
	d[0]=0;d[1]=1;
	
	cin>>n;
	for(int i=2; i<=n; i++) d[i]=d[i-1]+d[i-2];	
		
	cout<<d[n];

	return 0;
}

/*
boj.kr/2747

INPUT:
10

OUTPUT:
55
*/
