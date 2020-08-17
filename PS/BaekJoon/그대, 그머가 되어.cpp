#include <iostream>
#include <vector>

using namespace std;

const int INF=1e9;

vector<int> a[1001];
int d[1001];

void dfs(int x) {
	for(auto& y : a[x]) {
		if(d[y]>d[x]+1) {
			d[y]=d[x]+1;
			dfs(y);
		}
	}
}

int main() {
	int A,B,N,M;
	cin>>A>>B>>N>>M;
	
	for(int i=0; i<M; i++) {
		int u,v;
		cin>>u>>v;
		
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	// run the graph
	fill(d+1, d+N+1, INF);
	d[A]=0;
	dfs(A);

	// answer
	if(d[B]==INF) cout<<-1;
	else cout<<d[B];

	return 0;
}
