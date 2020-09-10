#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

const int MAX=1e4+1;

vector<int> a[MAX];
bool check[MAX];
int tin[MAX], tout[MAX];
int p[MAX][15];
int timer, K;

void dfs(int u, int parent) {
	tin[u]=timer++;
	
	p[u][0]=parent;
	for(int i=1; i<=K; i++) p[u][i]=p[p[u][i-1]][i-1];
	
	for(auto& v : a[u]) {
		if(v!=parent) dfs(v,u);
	}
	
	tout[u]=timer++;
}

bool upper(int u, int v) {
	// (u) is parent of (v)
	return tin[u]<=tin[v] && tout[u]>=tout[v];
}

int lca(int u, int v) {
	if(upper(u,v)) return u;
	if(upper(v,u)) return v;
	
	for(int i=K; i>=0; i--) {
		if(!upper(p[u][i], v)) u=p[u][i];
	}
	
	return p[u][0];
}

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		// reset for each test case
		memset(p, 0, sizeof(p));
		memset(check, false, sizeof(check));
		timer=0;
		K=(int)log2(N);
		for(int i=1; i<=N; i++) a[i].clear();
		
		for(int i=0; i<N-1; i++) {
			int u,v;
			cin>>u>>v;
		
			a[u].push_back(v);
			check[v]=true;
		}
		
		int root=-1;
		for(int i=1; i<=N; i++)
			if(check[i]==false) root=i;
		
		dfs(root, root);
		
		int x,y;
		cin>>x>>y;
		
		cout<<lca(x,y)<<'\n';
	}

	return 0;
}
