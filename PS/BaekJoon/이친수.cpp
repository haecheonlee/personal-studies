#include <iostream>

using namespace std;

long long int dp[91];
int main() {
	dp[1]=1;dp[2]=1;
	
	int n;
	cin>>n;
	
	for(int i=3; i<=n; i++) {
		dp[i] = dp[i-1]+dp[i-2];
	}
	
	cout<<dp[n];
	return 0;
}

/*
boj.kr/2193

INPUT:
3

OUTPUT:
2
*/
