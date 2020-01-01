#include <iostream>

using namespace std;

int dp[11];
int main() {
	dp[0]=1;dp[1]=1;dp[2]=2;
	
	
	int T;
	cin>>T;
	
	for(int i=0; i<T; i++) {
		int n;
		cin>>n;
		
		if(dp[n] <= 0) {
			for(int j=3; j<=n; j++) {
				dp[j] = dp[j-1] + dp[j-2] + dp[j-3];	
			}
		}
		
		cout<<dp[n]<<'\n';
	}
	
	return 0;
}

/*
boj.kr/9095

INPUT:
3
4
7
10

OUTPUT:
7
44
274
*/
