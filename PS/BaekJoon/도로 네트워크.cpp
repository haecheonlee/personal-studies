/* reference: baekjoon/codeplus */

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e5+1;

int N;
vector<pi> a[MAX];
int parent[MAX], depth[MAX], d[MAX];
bool check[MAX];
int p[MAX][17];
int d_min[MAX][17], d_max[MAX][17];


pair<int,int> lca(int u, int v) {
	pair<int,int> ans={1e6+1,0};	// {min,max}
	
	// if (u) is higher than (v) in tree 
	if(depth[u]<depth[v]) swap(u,v);
	
	int K=log2(N);
	
	// setting the same height with (v)
	for(int i=K; i>=0; i--) {
		if(depth[u]-(1<<i)>=depth[v]) {
			ans.first=min(ans.first, d_min[u][i]);
			ans.second=max(ans.second, d_max[u][i]);

			u=p[u][i];
		}
	}
	
	if(u==v) return ans;
	for(int i=K; i>=0; i--) {
		if(p[u][i]!=0 && p[u][i]!=p[v][i]) {
			ans.first=min(ans.first, min(d_min[u][i], d_min[v][i]));
			ans.second=max(ans.second, max(d_max[u][i], d_max[v][i]));
		
			u=p[u][i];
			v=p[v][i];
		}
	}
	
	ans.first=min(ans.first, min(d_min[u][0], d_min[v][0]));
	ans.second=max(ans.second, max(d_max[u][0], d_max[v][0]));
	
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N;
	
	for(int i=0; i<N-1; i++) {
		int u,v,c;
		cin>>u>>v>>c;
		
		a[u].push_back({v,c});
		a[v].push_back({u,c});
	}
	
	queue<int> q;
	q.push(1);
	d[1]=depth[1]=parent[1]=0;
	check[1]=true;
	
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		for(auto& next : a[x]) {
			int y=next.first;
			int distance=next.second;
			
			if(check[y]==false) {
				check[y]=true;
				depth[y]=depth[x]+1;
				parent[y]=x;
				d[y]=distance;	// distance between x and y
				q.push(y);
			}
		}
	}
	
	
	// set (k)th parent
	for(int i=1; i<=N; i++) {
		p[i][0]=parent[i];
		d_min[i][0]=d[i];
		d_max[i][0]=d[i];
	}
	
	for(int j=1; (1<<j)<N; j++) {
		for(int i=1; i<=N; i++) {
			if(p[i][j-1]!=0) {
				p[i][j]=p[p[i][j-1]][j-1];
				d_min[i][j]=d_min[i][j-1];
				d_max[i][j]=d_max[i][j-1];
				
				if(p[p[i][j-1]][j-1]!=0) {
					d_min[i][j]=min(d_min[i][j], d_min[p[i][j-1]][j-1]);
					d_max[i][j]=max(d_max[i][j], d_max[p[i][j-1]][j-1]);
				}
			}
		}
	}
	
	int M;
	cin>>M;
	
	while(M--) {
		int u,v;
		cin>>u>>v;
		
		auto ans=lca(u,v);
		cout<<ans.first<<' '<<ans.second<<'\n';
	}
	
	return 0;
}
