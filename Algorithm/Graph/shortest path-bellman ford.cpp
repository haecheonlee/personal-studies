/* Shortest Path using bellman ford */
/* boj.kr/11657 */

#include <iostream>
#include <vector>

using namespace std;
const int INF=1e9;

struct Edge {
	int to;
	int cost;
	Edge(int to, int cost) : to(to), cost(cost) {}
};

vector<Edge> list[501];
int d[501];

int n,m,from,to,cost;

int main() {
	cin>>n>>m;
	
	// initialziation
	for(int i=1; i<=n; i++) d[i]=INF;
	
	for(int i=0; i<m; i++) {
		cin>>from>>to>>cost;
		list[from].push_back(Edge(to,cost));
	}
	
	d[1]=0;
	bool negative_cycle=false;
	
	for(int i=1; i<=n; i++) {
		for(int here=1; here<=n; here++) {
			if(d[here]==INF) continue;
			
			for(auto &next : list[here]) {
				int to=next.to;
				int cost=next.cost;
				
				if(d[to]>d[here]+cost) {
					d[to]=d[here]+cost;
					if(i==n) negative_cycle=true;
				}
			}
		}	
	}
	
	if(negative_cycle) cout<<-1<<'\n';
	else {
		for(int i=2; i<=n; i++) {
			if(d[i]==INF) d[i]=-1;
			cout<<d[i]<<'\n';
		}
	}
	
	return 0;
}
