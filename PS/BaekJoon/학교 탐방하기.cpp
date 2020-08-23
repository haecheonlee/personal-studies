#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

vector<pi> a[1000];
int p[1000];
bool check[1000];

int get_total_cost(bool is_mst) {
	memset(check,false,sizeof(check));
	
	priority_queue<pi> q;
	q.push({0,0});
	
	int total=0;
	while(!q.empty()) {
		int cost=q.top().first;
		int x=q.top().second;
		q.pop();
		
		if(is_mst) cost=-cost;
		if(check[x]) continue;
		check[x]=true;
		total+=cost;
		
		// adding edges
		for(auto& next : a[x]) {
			int y=next.first;
			int c=next.second;
			
			if(is_mst) c=-c;
			q.push({c,y});
		}
	}
	
	return total*total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<=M; i++) {
		int u,v,c;
		cin>>u>>v>>c;
		
		// 내리막길: 1, 오르막길: 0 간선 값 바꾸기 
		a[u].push_back({v,1-c});
		a[v].push_back({u,1-c});
	}
	
	cout<<get_total_cost(false)-get_total_cost(true);

	return 0;
}
