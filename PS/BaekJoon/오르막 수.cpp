#include <iostream>

using namespace std;

#define mod 10007

int DP[1001][10];
int main() {
	int N;
	cin>>N;
	
	for(int i=0; i<=9; i++) DP[1][i]=1;
	for(int i=2; i<=N; i++) {
		for(int j=0; j<=9; j++) {
			for(int k=0; k<=j; k++) {
				DP[i][j]+=(DP[i-1][k]%mod);
			}
		}
	}
	
	int total=0;
	for(int i=0; i<=9; i++) {
		total+=(DP[N][i]%mod);	
	}
	cout<<total%mod;

	return 0;
}

/*
boj.kr/11057

INPUT:
3

OUTPUT:
220
*/
