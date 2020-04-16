/* MST using prim (min-heap) */
/* boj.kr/11657 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
	int to;
	int cost;

	Edge(int to, int cost) : to(to), cost(cost) {}
	
	bool operator<(const Edge &other) const {
		return cost>other.cost;
	}
};

vector<Edge> list[10001];
bool visited[10001];
int n,m,from,to,cost;

int main() {
	cin>>n>>m;	

	for(int i=0; i<m; i++) {
		cin>>from>>to>>cost;
		
		list[from].push_back(Edge(to,cost));
		list[to].push_back(Edge(from,cost));
	}

	visited[1]=true;
	priority_queue<Edge> q;
	for(auto &e : list[1]) q.push(e);
	
	int ans=0;
	while(!q.empty()) {
		auto e=q.top();
		q.pop();
		
		if(visited[e.to]) continue;
		visited[e.to]=true;
		ans+=e.cost;
		
		for(auto &ee : list[e.to]) {
			q.push(ee);
		}
	}

	cout<<ans;

	return 0;
}
