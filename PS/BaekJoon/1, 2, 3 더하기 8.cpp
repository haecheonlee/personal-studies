#include <iostream>

using namespace std;

const int mod = 1000000009;
long long DP[100001][2]{0};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	DP[0][0]=0;DP[1][0]=1;DP[2][0]=1;
	DP[0][1]=1;DP[1][1]=0;DP[2][1]=1;
	
	int T,n;
	cin>>T;
	
	while(T--) {
		cin>>n;
		
		if(DP[n][0]==0 && DP[n][1]==0) {
			for(int i=3; i<=n; i++) {
				if(DP[i][0]!=0 || DP[i][1]!=0) continue;
				DP[i][0]=DP[i-1][1]+DP[i-2][1]+DP[i-3][1];
				DP[i][1]=DP[i-1][0]+DP[i-2][0]+DP[i-3][0];
				
				DP[i][0]%=mod;
				DP[i][1]%=mod;
			}
		}
		
		cout<<DP[n][0]<<" "<<DP[n][1]<<'\n';
	}

	return 0;
}

/*
INPUT:
3
4
7
10

OUTPUT:
3 4
22 22
137 137
*/
