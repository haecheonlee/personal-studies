#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF=1e9;

struct Edge {
	int to;
	int cost;
	Edge(int to, int cost) : to(to), cost(cost) {}
	
	bool operator<(const Edge &other) const {
		return cost<other.cost;
	}
};

vector<Edge> list[5001];
int d[5001];
int v,e,p;

int dist(int start, int end) {
	for(int i=1; i<=v; i++) d[i]=INF;

	priority_queue<Edge> pq;
	pq.push(Edge(start,0));
	d[start]=0;
	
	while(!pq.empty()) {
		int here=pq.top().to;
		int cost=-pq.top().cost;
		pq.pop();
		
		if(d[here]<cost) continue;
		for(auto &next : list[here]) {
			int to=next.to;
			int next_cost=next.cost+cost;
			
			if(d[to]>next_cost) {
				d[to]=next_cost;
				pq.push(Edge(to,-next_cost));
			}
		}
	}	

	return d[end];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>v>>e>>p;
	
	for(int i=0; i<e; i++) {
		int p1,p2,cost;
		cin>>p1>>p2>>cost;
		
		list[p1].push_back(Edge(p2,cost));
		list[p2].push_back(Edge(p1,cost));
	}
	
	int path1=dist(1,v);
	int path2=dist(1,p);
	int path3=dist(p,v);
	
	if(path1==path2+path3) cout<<"SAVE HIM";
	else cout<<"GOOD BYE";

	return 0;
}

/*
INPUT:
6 7 4
1 2 1
1 3 1
2 3 10
3 4 1
3 5 2
4 5 1
5 6 1

OUTPUT:
SAVE HIM
*/
