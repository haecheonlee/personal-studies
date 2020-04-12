#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
	int to;
	int cost;
	bool operator<(const Edge &other) const {
		return cost>other.cost;
	}
};

vector<Edge> a[1001];
bool c[1001];

int main() {
	int n,m;
	cin>>n>>m;
	
	for(int i=0; i<m; i++) {
		int from,to,cost;
		cin>>from>>to>>cost;

		a[from].push_back(Edge{to,cost});
		a[to].push_back(Edge{from,cost});
	}
	
	c[1]=true;
	priority_queue<Edge> q;
	for(auto e : a[1]) q.push(e);
	
	int ans=0;
	while(!q.empty()) {
		auto e=q.top();
		q.pop();
		
		if(c[e.to]==true) continue;
		c[e.to]=true;
		ans+=e.cost;
		
		for(auto ee : a[e.to]) q.push(ee);
	}
	cout<<ans;

	return 0;
}

/*
INPUT:
6
9
1 2 5
1 3 4
2 3 2
2 4 7
3 4 6
3 5 11
4 5 3
4 6 8
5 6 8

OUTPUT:
23
*/
