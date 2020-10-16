#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
using pi=pair<int,int>;
using ll=long long;

const int MAX=1e3+1;
const ll INF=1e12;

vector<pair<int,pi>> a;
vector<int> b[MAX];
int adj[MAX][MAX];
int p[MAX];
ll d[MAX];

int Find(int x) {
	if(p[x]==x) return p[x];
	return p[x]=Find(p[x]);
}

void Union(int x, int y) {
	x=Find(p[x]);
	y=Find(p[y]);
	
	if(x!=y) p[y]=x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<M; i++) {
		int u,v,c;
		cin>>u>>v>>c;
		
		a.push_back({c, {u,v}});
	}
	
	for(int i=0; i<N; i++) p[i]=i;
	sort(a.begin(), a.end());

	ll ans=0;	// cost for connection betwenn all cities
	for(int i=0; i<M; i++) {
		int c=a[i].first;
		int u=a[i].second.first;
		int v=a[i].second.second;
		
		if(Find(u)!=Find(v)) {
			Union(u,v);
			adj[u][v]=adj[v][u]=c;
			b[u].push_back(v);
			b[v].push_back(u);
			ans+=c*1LL;
		}
	}
	cout<<ans<<'\n';
	
	// bfs for max cost between two city
	memset(d, -1, sizeof(d));
	queue<int> q;
	q.push(0);
	d[0]=0;
	
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		for(auto& y : b[x]) {
			if(d[y]==-1) {
				d[y]=d[x] + adj[x][y];
				q.push(y);
			}
		}
	}
	
	// find farthest one
	int c1=-1, temp=0;
	for(int i=0; i<N; i++) {
		if(d[i]>temp) c1=i, temp=d[i];
	}
	
	// start new bfs from farthest one
	memset(d, -1, sizeof(d));
	q.push(c1);
	d[c1]=0;
	
	ll ans2=0;
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		ans2=max(ans2, d[x]);
		for(auto& y : b[x]) {
			if(d[y]==-1) {
				d[y]=d[x] + adj[x][y];
				q.push(y);
			}
		}
	}
	cout<<ans2;
	
	return 0;
}
