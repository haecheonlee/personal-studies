/* shortest path - dijkstra */
/* boj.kr/1916 */

#include <iostream>
#include <vector>

using namespace std;
const int INF=1e9;

struct Edge {
	int to;
	int cost;
	Edge(int to, int cost) : to(to), cost(cost) {}
};

vector<Edge> list[1001];
int d[1001];
bool visited[1001];

int n,m,x,y,z;

int main() {
	cin>>n>>m;
	
	// initialization
	for(int i=1; i<=n; i++) d[i]=INF;
	
	for(int i=0; i<m; i++) {
		cin>>x>>y>>z;
		list[x].push_back(Edge(y,z));
	}

	int start,end;
	cin>>start>>end;
	
	d[start]=0;
	for(int k=0; k<n-1; k++) {
		int min_cost=INF;
		int current=-1;
		
		for(int i=1; i<=n; i++) {
			if(visited[i]==false && min_cost>d[i]) {
				min_cost=d[i];
				current=i;
			}
		}
		
		visited[current]=true;
		for(auto &next : list[current]) {
			int to=next.to;
			int cost=next.cost;
			
			if(d[to]>d[current]+cost) d[to]=d[current]+cost;	
		}
	}

	cout<<d[end];

	return 0;
}
