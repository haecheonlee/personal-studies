#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

int N,M;
int adj[251][251];
vector<int> a[251];
int d[251];
int p[251];

int dijkstra() {
	memset(d,0x3f,sizeof(d));
	memset(p,0,sizeof(d));
	
	priority_queue<pi> q;
	q.push({0,1});
	d[1]=0;
	while(!q.empty()) {
		int cost=-q.top().first;
		int x=q.top().second;
		q.pop();
		
		if(d[x]<cost) continue;
		for(auto& y : a[x]) {
			int weight=d[x]+adj[x][y];
			if(d[y]>weight) {
				d[y]=weight;
				p[y]=x;
				q.push({-weight,y});
			}
		}
	}
	
	return d[N];
}

int main() {
	cin>>N>>M;
	
	for(int i=0; i<M; i++) {
		int u,v,c;
		cin>>u>>v>>c;
		
		adj[u][v]=adj[v][u]=c;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	// run first dijkstra
	int first=dijkstra();
	
	// get used edges from 1 to N
	vector<int> selected;
	int current=N;
	while(p[current]!=current) {
		selected.push_back(current);
		current=p[current];
	}
	
	// run dijkstra, changing weight of connected edge from 1 to N found in the initial dijktstra
	int longest=0;
	for(int i=0; i<selected.size()-1; i++) {
		int weight=adj[selected[i]][selected[i+1]];
		adj[selected[i]][selected[i+1]]=adj[selected[i+1]][selected[i]]=weight*2;
		longest=max(longest, dijkstra());
		adj[selected[i]][selected[i+1]]=adj[selected[i+1]][selected[i]]=weight;
	}

	// print answer
	cout<<longest-first;

	return 0;
}
