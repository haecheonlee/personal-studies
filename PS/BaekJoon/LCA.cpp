#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX=50001;
vector<int> a[MAX];
int parent[MAX];
int depth[MAX];
bool check[MAX];

int lca(int u, int v) {
	if(depth[u]<depth[v]) swap(u,v);
	
	while(depth[u]!=depth[v]) u=parent[u];
	while(u!=v) {
		u=parent[u];
		v=parent[v];
	}
	
	return u;
}

int main() {
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
	
	parent[1]=0;
	depth[1]=0;
	check[1]=true;
	
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		for(int y : a[x]) {
			if(check[y]==false) {
				parent[y]=x;
				depth[y]=depth[x]+1;
				check[y]=true;
				
				q.push(y);
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
