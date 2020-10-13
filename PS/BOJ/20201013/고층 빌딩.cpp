/* reference: baekjoon/codeplus */

#include <iostream>

using namespace std;
using ll=long long;

const int MAX=1e2+1;

ll d[MAX][MAX][MAX];
ll MOD=1e9+7;

int main() {
	int N,L,R;
	cin>>N>>L>>R;
	
	d[1][1][1]=1;
	for(int i=1; i<=N-1; i++) {
		for(int j=1; j<=L; j++) {
			for(int k=1; k<=R; k++) {
				if(j+1<=L) {
					d[i+1][j+1][k]+=d[i][j][k];
					d[i+1][j+1][k]%=MOD;
				}
				
				if(k+1<=R) {
					d[i+1][j][k+1]+=d[i][j][k];
					d[i+1][j][k+1]%=MOD;
				}
				
				d[i+1][j][k]+=d[i][j][k] * (i - 1);
				d[i+1][j][k]%=MOD;
			}
		}
	}
	
	cout<<d[N][L][R];

	return 0;
}
