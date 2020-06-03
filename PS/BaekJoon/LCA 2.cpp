#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX=100001;

vector<int> a[MAX];
int parent[MAX];
int depth[MAX];
int p[MAX][17];
bool check[MAX];

int lca(int u, int v) {
	if(depth[u]<depth[v]) swap(u,v);
	
	// find math k in 2^k
	int log=1;
	while((1<<log)<=depth[u]) log++;
	log-=1;
	
	for(int i=log; i>=0; i--) {
		if(depth[u]-(1<<i)>=depth[v]) u=p[u][i];
	}
	
	if(u==v) return u;
	else {
		for(int i=log; i>=0; i--) {
			if(p[u][i]!=0 && p[u][i]!=p[v][i]) {
				u=p[u][i];
				v=p[v][i];
			}
		}
		
		return parent[u];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	
	for(int i=0; i<n-1; i++) {
		int u,v;
		cin>>u>>v;
		
		a[u].push_back(v);
		a[v].push_back(u);
	}

	queue<int> q;
	q.push(1);
	
	depth[1]=0;
	check[1]=true;
	parent[1]=0;
	
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		for(int y : a[x]) {
			if(check[y]==false) {
				depth[y]=depth[x]+1;
				parent[y]=x;
				check[y]=true;
				
				q.push(y);
			}
		}
	}
	
	for(int i=1; i<=n; i++) p[i][0]=parent[i];
	for(int j=1; (1<<j)<n; j++) {
		for(int i=1; i<=n; i++) {
			if(p[i][j-1]!=0) {
				p[i][j]=p[p[i][j-1]][j-1];	
			}
		}
	}
	
	int m;
	cin>>m;
	
	while(m--) {
		int u,v;
		cin>>u>>v;
		
		cout<<lca(u,v)<<'\n';
	}

	return 0;
}
