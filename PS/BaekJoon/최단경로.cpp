#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
const int INF=numeric_limits<int>::max();

struct Edge {
	int to;
	int cost;
	Edge(int to, int cost) : to(to), cost(cost) {}
};

vector<Edge> list[20001];
bool visited[20001];
int dist[20001];

int main() {
	int n,m,start;
	cin>>n>>m>>start;
	
	for(int i=1; i<=n; i++) dist[i]=INF;
	for(int i=0; i<m; i++) {
		int from,to,cost;
		cin>>from>>to>>cost;
		
		list[from].push_back(Edge(to,cost));
	}
	
	priority_queue<pair<int,int>> q;
	q.push(make_pair(0,start));
	dist[start]=0;
	
	while(!q.empty()) {
		auto p=q.top();
		q.pop();
		
		int current=p.second;
		if(visited[current]) continue;
		
		for(auto &e : list[current]) {
			int to=e.to;
			int cost=e.cost;
			
			if(dist[to]>dist[current]+cost) {
				dist[to]=dist[current]+cost;
				q.push(make_pair(-dist[to],to));
			}
		}
	}
	
	for(int i=1; i<=n; i++) {
		if(dist[i]==INF) cout<<"INF\n";
		else cout<<dist[i]<<'\n';
	}

	return 0;
}

/*
INPUT:
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6

OUTPUT:
0
2
3
7
INF
*/
