#include <iostream>

using namespace std;

int N;
int d[1001];	// degree of each node
int adj[1001][1001];

void dfs(int node) {
	for(int next=1; next<=N; next++) {
		while(adj[node][next]) {
			adj[node][next]--;	// out-degree
			adj[next][node]--;	// in-degree
			dfs(next);
		}
	}
	cout<<node<<" ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N;
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			cin>>adj[i][j];
			
			d[i]+=adj[i][j];
			d[j]+=adj[i][j];
		}
	}

	// is possible?
	bool is_possible=true;
	for(int i=1; i<=N; i++) {
		d[i]/=2;
		
		// node has an odd number of edge 
		if(d[i]%2) {
			is_possible=false;
			break;
		}
	}
	
	if(is_possible) dfs(1);
	else cout<<-1;
	
	return 0;
}
