#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using PI=pair<int,int>;

const int MAX=40001;

vector<PI> a[MAX];
int parent[MAX];
int depth[MAX];
int dist[MAX];
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
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	
	for(int i=0; i<n-1; i++) {
		int x,y,z;
		cin>>x>>y>>z;
		
		a[x].push_back(make_pair(y,z));
		a[y].push_back(make_pair(x,z));
	}
	
	queue<int> q;
	q.push(1);
	
	parent[1]=0;
	dist[1]=0;
	depth[1]=0;
	check[1]=true;
	
	while(!q.empty()) {
		int x=q.front();
		q.pop();
			
		for(auto next : a[x]) {
			int y=next.first;
			int cost=next.second;
			
			if(check[y]==false) {
				dist[y]=dist[x]+cost;
				depth[y]=depth[x]+1;
				parent[y]=x;
				check[y]=true;
				
				q.push(y);
			}
		}
	}
	
	int m;
	cin>>m;
	

	for(int i=0; i<m; i++) {
		int u,v;
		cin>>u>>v;
		
		cout<<dist[u]+dist[v]-(2*dist[lca(u,v)])<<'\n';
	}
	
	return 0;
}
