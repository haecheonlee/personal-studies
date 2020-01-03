#include <iostream>

using namespace std;

#define module 1000000000

long long DP[101][10];

int main() {
	int N;
	cin>>N;
	
	for(int i=1; i<=9; i++) DP[1][i]=1;
	
	for(int i=2; i<=N; i++) {
		for(int j=0; j<=9; j++) {
			DP[i][j]=0;
			if((j-1)>=0) DP[i][j] += DP[i-1][j-1];
			if((j+1)<=9) DP[i][j] += DP[i-1][j+1];
			DP[i][j]%=module;
		}
	}
	
	long long result = 0;
	for(int i=0; i<=9; i++) result += DP[N][i];
	
	cout<<result%module;

	return 0;
}

/*
boj.kr/10844

INPUT:
1

OUTPUT:
9
*/
