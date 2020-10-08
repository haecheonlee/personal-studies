#include <iostream>
#include <cstring>

using namespace std;

const int MAX=1e3+1;

int a[MAX][MAX];
int d[MAX][MAX];

int main() {
	
	while(1) {
		int N,M;
		cin>>N>>M;
		if(N==0 && M==0) break;
		
		memset(d, 0, sizeof(d));
		
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=M; j++) cin>>a[i][j];
		}
		
		int ans=0;
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=M; j++) {
				if(a[i][j]==0) continue;
				d[i][j]=min(d[i-1][j], min(d[i-1][j-1], d[i][j-1]))+1;
				ans=max(ans, d[i][j]);
			}
		}
		cout<<ans<<'\n';
		
	}

	return 0;
}
