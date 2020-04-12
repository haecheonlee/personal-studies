#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
	int from;
	int to;
	int cost;
	
	bool operator<(const Edge &other) const {
		return cost<other.cost;
	}
};

int p[10001];
int Find(int x) {
	if(p[x]==x) return x;
	else return p[x]=Find(p[x]);
}

void Union(int x, int y) {
	x=Find(x);
	y=Find(y);
	
	p[x]=y;
}

int main() {
	int n,m;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++) p[i]=i;
	
	vector<Edge> a(m);
	for(int i=0; i<m; i++) cin>>a[i].from>>a[i].to>>a[i].cost;
	sort(a.begin(),a.end());
	
	int ans=0;
	for(auto &e : a) {
		int x=Find(e.from);
		int y=Find(e.to);
		
		if(x!=y) {
			Union(e.from, e.to);
			ans+=e.cost;
		}
	}
	cout<<ans;
	
	return 0;
}

/*
INPUT:
3 3
1 2 1
2 3 2
1 3 3

OUTPUT:
3
*/
