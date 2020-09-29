#include <iostream>
#include <vector>

using namespace std;
using pi=pair<int,int>;

const int INF=1e9;
const int MAX=3e2;

int adj[MAX][MAX];

int main() {
	int N;
	cin>>N;
	
	vector<pi> a;
	for(int i=0; i<N; i++) {
		int L,R;
		cin>>L>>R;
		
		a.push_back({L,R});
	}
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) adj[i][j]=INF;
	}
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(i==j) continue;
			if((a[j].second>=a[i].second && a[j].first<=a[i].second) || 
			   (a[j].second<=a[i].second && a[i].first<=a[j].second)) {
				adj[i][j]=1;
			}
		}
	}
	
	for(int k=0; k<N; k++) {
		for(int i=0; i<N; i++) {
			if(adj[i][k]==INF) continue;
			for(int j=0; j<N; j++) {
				if(adj[k][j]==INF) continue;
				adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
			}
		}
	}

	int Q;
	cin>>Q;
	
	while(Q--) {
		int u,v;
		cin>>u>>v;
		
		u--, v--;
		if(adj[u][v]==INF) cout<<-1<<'\n';
		else cout<<adj[u][v]<<'\n';
	}

	return 0;
}
