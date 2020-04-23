#include <iostream>
#include <vector>
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

int p[100001];

int Find(int x) {
	if(p[x]==x) return x;
	else return p[x]=Find(p[x]);
}

void Union(int x, int y) {
	x=Find(x);
	y=Find(y);
	
	p[x]=y;
}

vector<Edge> list;
int n,m,from,to,cost;

int main() {
	cin>>n>>m;
	
	for(int i=1; i<=n; i++) p[i]=i;
	
	list.resize(m);
	for(int i=0; i<m; i++) cin>>list[i].from>>list[i].to>>list[i].cost;
	sort(list.begin(), list.end());
	
	int ans=0;
	int mx_cost=-1;
	for(int i=0; i<m; i++) {
		Edge e=list[i];
		
		int x=Find(e.from);
		int y=Find(e.to);
		
		if(x!=y) {
			Union(e.from, e.to);
			ans+=e.cost;
			mx_cost=max(mx_cost,e.cost);
		}
	}
	cout<<ans-mx_cost;
	
	return 0;
}

/*
INPUT:
7 12
1 2 3
1 3 2
3 2 1
2 5 2
3 4 4
7 3 6
5 1 5
1 6 2
6 4 1
6 5 3
4 5 3
6 7 4

OUTPUT:
8
*/
