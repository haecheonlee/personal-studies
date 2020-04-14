#include <iostream>
#include <vector>
#include <limits>
#include <stack>

using namespace std;
const int INF=numeric_limits<int>::max();

struct Edge {
	int to;
	int cost;
	Edge(int to, int cost) : to(to), cost(cost) {}
};

vector<Edge> list[1001];
bool visited[1001];
int dist[1001];
int v[1001];

int main() {
	int n,m;
	cin>>n>>m;
	
	// initialization 
	for(int i=1; i<=n; i++) dist[i]=INF;
	
	for(int i=0; i<m; i++) {
		int from,to,cost;
		cin>>from>>to>>cost;
		
		list[from].push_back(Edge(to,cost));
	}
	
	int start,end;
	cin>>start>>end;
	
	dist[start]=0;
	v[start]=-1;
	for(int k=0; k<n-1; k++) {
		int min_cost=INF;
		int current=-1;
		
		for(int i=1; i<=n; i++) {
			if(visited[i]==false && min_cost>dist[i]) {
				min_cost=dist[i];
				current=i;
			}
		}
		
		visited[current]=true;
		for(auto e : list[current]) {
			int next=e.to;
			int cost=e.cost;
			
			if(dist[next]>dist[current]+cost) {
				dist[next]=dist[current]+cost;
				v[next]=current;
			}
		}
	}
	
	cout<<dist[end]<<'\n';
	stack<int> s;
	while(end!=-1) {
		s.push(end);
		end=v[end];
	}
	cout<<s.size()<<'\n';
	while(!s.empty()) {
		cout<<s.top()<<" ";
		s.pop();
	}
	
	return 0;
}

/*
INPUT:
5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5

OUTPUT:
4
3
1 3 5
*/
