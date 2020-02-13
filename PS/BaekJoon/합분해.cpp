#include <iostream>

using namespace std;

const int mod=1000000000;
long long d[201][201];
int main() {
	int n,k;
	cin>>n>>k;
	
	d[0][0]=1;
	for(int i=1; i<=k; i++) {
		for(int j=0; j<=n; j++) {
			for(int a=0; a<=j; a++) {
				d[i][j]+=d[i-1][j-a];
				d[i][j]%=mod;
			}
		}
	}
	
	cout<<d[k][n];
	
	return 0;
}

/*
boj.kr/2225

INPUT:
20 2

OUTPUT:
21
*/
