#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX=30001;

vector<int> a[MAX];
int parent[MAX];
int dist[MAX];
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
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	
	for(int i=0; i<n-1; i++) {
		int x,y;
		cin>>x>>y;
		
		a[x].push_back(y);
		a[y].push_back(x);
	}
	
	parent[1]=0;
	depth[1]=0;
	dist[1]=0;
	check[1]=true;
	
	queue<int> q;
	q.push(1);
	
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		for(int y : a[x]) {
			if(check[y]==false) {
				parent[y]=x;
				depth[y]=depth[x]+1;
				dist[y]=dist[x]+1;
				check[y]=true;
				
				q.push(y);
			}
		}
	}
	
	int m=0;
	cin>>m;
	
	int total=0, current=1, next;
	while(m--) {
		cin>>next;
		
		int x=lca(current, next);
		int d=(dist[current]-dist[x])+(dist[next]-dist[x]);
		
		total+=d;
		current=next;
	}
	cout<<total;

	return 0;
}
