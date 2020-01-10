#include <iostream>

using namespace std;

int DP[31][31]{0};
int main() {
	for(int i=1; i<=30; i++) DP[i][0]=1;
	
	int T,n,r;
	cin>>T;
	
	while(T--) {
		cin>>r>>n;
		
		for(int i=1; i<=r; i++) DP[n][i]=((n-i+1)*DP[n][i-1])/i;
		cout<<DP[n][r]<<'\n';
	}
	
	return 0;
}

/*
boj.kr/1010

INPUT:
3
2 2
1 5
13 29

OUTPUT:
1
5
67863915
*/
