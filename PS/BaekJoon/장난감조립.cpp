#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
	int to;
	int cost;
	Edge(int to, int cost) : to(to), cost(cost) { }
};

vector<Edge> list[101];
int d[101][101];
int in_degree[101];
int n,m,x,y,z;

int main() {
	cin>>n>>m;
	
	for(int i=0; i<m; i++) {
		cin>>x>>y>>z;
		
		list[y].push_back(Edge(x,z));
		in_degree[x]+=1;
	}
	
	queue<int> q;
	for(int i=1; i<=n; i++) {
		if(in_degree[i]==0) {
			q.push(i);
			d[i][i]=1;
		}
	}
	
	while(!q.empty()) {
		int current=q.front();
		q.pop();
		
		for(auto &next : list[current]) {
			int to=next.to;
			int cost=next.cost;
			
			for(int i=1; i<=n; i++) {
				d[to][i]+=cost*d[current][i];
			}
			
			in_degree[to]-=1;
			if(in_degree[to]==0) {
				q.push(to);
			}
		}
	}
	
	for(int i=1; i<=n; i++) {
		if(d[n][i]) cout<<i<<" "<<d[n][i]<<'\n';
	}
	
	return 0;
}

/*
INPUT:
7
8
5 1 2
5 2 2
7 5 2
6 5 2
6 3 3
6 4 4
7 6 3
7 4 5

OUTPUT:
1 16
2 16
3 9
4 17
*/
