#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e5+1;

int N,Q;
vector<pi> a[MAX];
int p[MAX][17];
int tin[MAX], tout[MAX];
int d[MAX];
int timer=0, K;

void dfs(int x, int parent) {
	tin[x]=++timer;
	
	p[x][0]=parent;
	for(int i=1; i<=K; i++) p[x][i]=p[p[x][i-1]][i-1]; 
	
	for(auto& next : a[x]) {
		int y=next.first;
		int cost=next.second;
		
		if(y!=parent) {
			d[y]=d[x]+cost;
			dfs(y,x);
		}
	}
	
	tout[x]=++timer;
}

bool upper(int u, int v) {
	// if  (u) is the parent of (v)
	return tin[u]<=tin[v] && tout[u]>=tout[v];
}

int lca(int u, int v) {
	if(upper(u,v)) return u;
	if(upper(v,u)) return v;
	
	for(int i=K; i>=0; i--) {
		if(upper(p[u][i],v)==false) u=p[u][i];
	}
	return p[u][0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N>>Q;
	
	for(int i=0; i<N-1; i++) {
		int u,v,c;
		cin>>u>>v>>c;
		
		a[u].push_back({v,c});
		a[v].push_back({u,c});
	}
	
	K=log2(N);
	d[1]=0;
	dfs(1,1);
	
	while(Q--) {
		int u,v;
		cin>>u>>v;
		
		cout<<d[u]+d[v]-(2*d[lca(u,v)])<<'\n';
	}
	
	return 0;
}
