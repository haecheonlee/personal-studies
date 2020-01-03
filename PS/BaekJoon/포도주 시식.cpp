#include <iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	int DP[n+1][2] {0};
	int glasses[n+1] {0};
	for(int i=1; i<=n; i++) {
		cin>>glasses[i];
	}
	
	DP[1][0]=glasses[1];DP[1][1]=glasses[1];
	
	int m=glasses[1];
	for(int i=2; i<=n; i++) {
		DP[i][0]=glasses[i];
		DP[i][1]=glasses[i];
		
		for(int j=2; j<=i; j++) {
			DP[i][0] = max(DP[i][0], (max(DP[i-j][0], DP[i-j][1]) + glasses[i]));	 
			DP[i][1] = max(DP[i][0], (DP[i-1][0] + glasses[i]));	 
		
			m = max(m, max(DP[i][0], DP[i][1]));
		}
	}
	
	cout<<m;
	
	return 0;
}

/*
boj.kr/2156

INPUT:
6
6
10
13
9
8
1

OUTPUT:
33
*/
