/* reference: https://github.com/kks227/BOJ/blob/master/2100/2176.cpp */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e3+1;
const int S=1, T=2;

int N, M, d[MAX], dist[MAX];
vector<pi> a[MAX];

int go(int curr) {
	if(curr==T) return 1;
	
	int& ret=d[curr];
	if(ret!=-1) return ret;
	ret=0;
	
	for(auto& p : a[curr]) {
		if(dist[p.first]<dist[curr]) ret+=go(p.first);
	}
	
	return ret;
}

int main() {
	cin>>N>>M;
	
	for(int i=0; i<M; i++) {
		int u,v,c;
		cin>>u>>v>>c;
		
		a[u].push_back({v,c});
		a[v].push_back({u,c});
	}
	
	bool visited[MAX]={ false };
	fill(dist, dist+MAX, 0x7fffffff);
	dist[T]=0;
	priority_queue<pi> q;
	q.push({0,T});

	while(!q.empty()) {
		int c=-q.top().first;
		int x=q.top().second;
		q.pop();
		
		if(dist[x]<c) continue;
		for(auto& p : a[x]) {
			int y=p.first;
			int nc=dist[x]+p.second;
			
			if(dist[y]>nc) {
				dist[y]=nc;
				q.push({-nc, y});
			}
		}
	}

	memset(d, -1, sizeof(d));
	cout<<go(S);
	
	return 0;
}
