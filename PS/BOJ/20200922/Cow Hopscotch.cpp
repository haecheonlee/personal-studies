#include <iostream>

using namespace std;

const int MAX=1e2;
const int MOD=1e9+7;

int a[MAX][MAX];
int d[MAX][MAX];

int main() {
	int N,M,K;
	cin>>N>>M>>K;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) cin>>a[i][j];
	}
	
	d[0][0]=1;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(d[i][j]==0) continue;
			
			for(int x=i+1; x<N; x++) {
				for(int y=j+1; y<M; y++) {
					if(a[i][j]==a[x][y]) continue;
					d[x][y]+=(d[i][j]%MOD);
					d[x][y]%=MOD;
				}
			}
			
		}
	}
	cout<<d[N-1][M-1]%MOD;

	return 0;
}
