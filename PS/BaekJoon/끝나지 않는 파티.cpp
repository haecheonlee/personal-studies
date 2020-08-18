#include <iostream>

using namespace std;

int d[501][501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin>>N>>M;

	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) cin>>d[i][j];
	}

	for(int k=1; k<=N; k++) {
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
			}
		}
	}
	
	for(int i=0; i<M; i++) {
		int u,v,t;
		cin>>u>>v>>t;
		
		if(d[u][v]<=t) cout<<"Enjoy other party\n";
		else cout<<"Stay here\n";
	}

	return 0;
}
