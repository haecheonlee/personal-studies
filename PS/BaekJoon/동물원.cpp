#include <iostream>

using namespace std;

#define mod 9901

int DP[100001][3] {0};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	DP[1][0]=1;DP[1][1]=1;DP[1][2]=1;
	
	int N;
	cin>>N;
	
	for(int i=2; i<=N; i++) {
		DP[i][0]=DP[i-1][0]+DP[i-1][1]+DP[i-1][2];
		DP[i][1]=DP[i-1][0]+DP[i-1][2];
		DP[i][2]=DP[i-1][0]+DP[i-1][1];
		
		DP[i][0]%=mod;
		DP[i][1]%=mod;
		DP[i][2]%=mod;
	}
	
	int result=DP[N][0]+DP[N][1]+DP[N][2];
	cout<<result%mod;
	
	return 0;
}

/*
boj.kr/1309

INPUT:
4

OUTPUT:
41
*/
