#include <iostream>

using namespace std;

const int INF=1e9;

int d1[100][100];
int d2[100][100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin>>N>>M;
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			if(i==j) d1[i][j]=d2[i][j]=0;
			else d1[i][j]=d2[i][j]=INF;
		}
	}
	
	for(int i=0; i<M; i++) {
		int u,v;
		cin>>u>>v;
		
		d1[u][v]=1;
		d2[v][u]=1;
	}

	// heavy & light
	for(int k=1; k<=N; k++) {
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				d1[i][j]=min(d1[i][j], d1[i][k]+d1[k][j]);
				d2[i][j]=min(d2[i][j], d2[i][k]+d2[k][j]);
			}
		}
	}
	
	int ans=0;
	int mid=(N+1)/2;
	for(int i=1; i<=N; i++) {
		int heavy=0, light=0;
		for(int j=1; j<=N; j++) {
			if(i==j) continue;
			if(d1[i][j]!=INF) heavy++;
			if(d2[i][j]!=INF) light++;
		}
		
		if(heavy>=mid || light>=mid) ans++;
	}
	cout<<ans;

	return 0;
}
