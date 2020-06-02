#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
	int to;
	int cost;
	Edge(int to, int cost) : to(to), cost(cost) {}
};

const int INF=1e9;
vector<Edge> a[10001];
priority_queue<int> dist[10001];

int main() {
	int n,m,k;
	cin>>n>>m>>k;
	
	for(int i=0; i<m; i++) {
		int from, to ,cost;
		cin>>from>>to>>cost;
		
		a[from].push_back(Edge(to, cost));
	}
	
	priority_queue<pair<int,int>> q;
	q.push(make_pair(0,1));
	dist[1].push(0);

	while(!q.empty()) {
		int from=q.top().second;
		int current=-q.top().first;	// cost 
		q.pop();
		
		for(auto next : a[from]) {
			int to=next.to;
			int cost=current+next.cost;
			
			if(dist[to].size()<k || dist[to].top()>cost) {
				if(dist[to].size()==k) dist[to].pop();
				
				dist[to].push(cost);
				q.push(make_pair(-cost,to));
			}
		}
	}
	
	for(int i=1; i<=n; i++) {
		if(dist[i].size()!=k) cout<<-1<<'\n';
		else cout<<dist[i].top()<<'\n';
	}
	
	return 0;
}
