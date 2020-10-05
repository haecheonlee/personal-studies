#include <iostream>

using namespace std;

const int MAX=251;
const int INF=1e9;

int adj[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin>>N>>M;

	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			if(i==j) adj[i][j]=0;
			else adj[i][j]=INF;
		}
	}

	for(int i=0; i<M; i++) {
		int u,v,b;
		cin>>u>>v>>b;
		
		if(b==0) {
			adj[u][v]=0;
			adj[v][u]=1;	
		}
		else {
			adj[u][v]=0;
			adj[v][u]=0;
		}
	}
	
	for(int k=1; k<=N; k++) {
		for(int i=1; i<=N; i++) {
			if(adj[i][k]==INF) continue;
			for(int j=1; j<=N; j++) {
				if(adj[k][j]==INF) continue;
				adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
			}
		}
	}
	
	
	int K;
	cin>>K;
	
	while(K--) {
		int s,e;
		cin>>s>>e;
		
		cout<<adj[s][e]<<'\n';
	}

	return 0;
}
