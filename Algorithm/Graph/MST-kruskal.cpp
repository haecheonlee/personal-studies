/* MST using kruskal (union find) */
/* boj.kr/11657 */

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

vector<Edge> list;
int n,m,from,to,cost;

int main() {
	cin>>n>>m;
	
	// initialization
	for(int i=1; i<=n; i++) p[i]=i;
	
	list.resize(m);
	for(int i=0; i<m; i++) cin>>list[i].from>>list[i].to>>list[i].cost;
	sort(list.begin(), list.end());
	
	int ans=0;
	for(int i=0; i<m; i++) {
		Edge e=list[i];
		
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
