/* reference: baekjoon/codeplus */

#include <iostream>

using namespace std;
using ll=long long;

const ll MOD=1e9+9;
const int MAX=1e3;

ll d[MAX+1][MAX+1];

int main() {
	for(int j=0; j<=MAX; j++) d[0][j]=1;
	for(int i=1; i<=MAX; i++) {
		for(int j=1; j<=MAX; j++) {
			if(0<=i-1) d[i][j]+=d[i-1][j-1];
			if(0<=i-2) d[i][j]+=d[i-2][j-1];
			if(0<=i-3) d[i][j]+=d[i-3][j-1];
			
			d[i][j]%=MOD;
		}
	}
	
	int T;
	cin>>T;
	
	while(T--) {
		int N,M;
		cin>>N>>M;
		
		cout<<d[N][M]<<'\n';
	}
	
	return 0;
}
