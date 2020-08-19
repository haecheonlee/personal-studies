#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

int N,M,K;
vector<pi> a[1001];
bool check[1001];

void removeEdge(pair<int,pi>& edge) {
	int cost=edge.first;
	int u=edge.second.first;
	int v=edge.second.second;
	
	a[u].erase(remove(a[u].begin(), a[u].end(), make_pair(v,cost)), a[u].end());
	a[v].erase(remove(a[v].begin(), a[v].end(), make_pair(u,cost)), a[v].end());
}

int mst(pair<int,pi> &edge) {
	memset(check,false,sizeof(check));
	
	priority_queue<pair<int,pi>> q;
	q.push({0,{0,1}});	// cost,node
	
	int total=0;
	while(!q.empty()) {
		int cost=-q.top().first;
		int p=q.top().second.first;		// from
		int x=q.top().second.second;	// to
		q.pop();
		
		if(check[x]) continue;
		check[x]=true;
		total+=cost;
		
		// exception for first cost
		if(cost>0) {
			if(edge.first>cost) {
				edge.first=cost;
				edge.second.first=p;
				edge.second.second=x;
			}
		}
		
		// adding all connected edges of 'x'
		for(auto& p : a[x]) {
			int y=p.first;
			int weight=p.second;
			if(check[y]==false) q.push({-weight,{x,y}});
		}
	}
	
	for(int i=1; i<=N; i++) {
		if(check[i]==false) return 0;
	}
	
	return total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N>>M>>K;
	
	for(int i=1; i<=M; i++) {
		int u,v;
		cin>>u>>v;
		
		a[u].push_back({v,i});
		a[v].push_back({u,i});
	}
	
	int score=1;
	while(K--) {
		pair<int,pi> min_edge {1e5, {-1,-1}};
		if(score) {
			score=mst(min_edge);
			removeEdge(min_edge);
		}
		cout<<score<<' ';
	}

	return 0;
}
