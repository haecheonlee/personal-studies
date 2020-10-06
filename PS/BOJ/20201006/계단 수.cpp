/* reference: baekjoon/codeplus */

#include <iostream>

using namespace std;
using ll=long long;

ll d[101][10][1<<10];
ll mod=1e9;

int main() {
	int N;
	cin>>N;
	
	for(int i=1; i<=9; i++) d[1][i][1<<i]=1LL;
	
	for(int i=1; i<=N-1; i++) {
		for(int j=0; j<=9; j++) {
			for(int k=0; k<(1<<10); k++) {
				if(d[i][j][k]==0) continue;
				if((k&(1<<j))==0) continue;
				
				if(j+1<=9) {
					d[i+1][j+1][k | (1<<(j+1))]+=d[i][j][k];
					d[i+1][j+1][k | (1<<(j+1))]%=mod;
				}
				
				if(j-1>=0) {
					d[i+1][j-1][k | (1<<(j-1))]+=d[i][j][k];
					d[i+1][j-1][k | (1<<(j-1))]%=mod;
				}
			}
		}
	}
	
	ll ans=0;
	for(int i=0; i<=9; i++) {
		ans+=d[N][i][(1<<10)-1];
		ans%=mod;
	}
	cout<<ans;
	
	return 0;
}
