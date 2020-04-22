#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF=1e9;
typedef pair<int,int> PI;

vector<PI> list[1001];
int dist[1001];
int parent[1001];


int main() {
	int n,m;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++) dist[i]=INF;
	for(int i=0; i<m; i++) {
		int from,to,cost;
		cin>>from>>to>>cost;
		
		list[from].push_back(make_pair(to,cost));
		list[to].push_back(make_pair(from,cost));
	}
	
	priority_queue<PI, vector<PI>, greater<PI>> pq;
	pq.push(make_pair(0,1));
	dist[1]=0;
	
	while(!pq.empty()) {
		int here=pq.top().second;
		int cost=pq.top().first;
		pq.pop();
		
		if(dist[here]<cost) continue;
		for(int i=0; i<list[here].size(); i++) {
			int there=list[here][i].first;
			int there_cost=list[here][i].second+cost;
			
			if(dist[there]>there_cost) {
				dist[there]=there_cost;
				pq.push(make_pair(there_cost,there));
				parent[there]=here;
			}
		}
	}
	
	cout<<n-1<<'\n';
	for(int i=2; i<=n; i++) cout<<parent[i]<<" "<<i<<'\n';
	
	return 0;
}

/*
INPUT:
4 5
1 2 1
1 4 4
1 3 2
4 2 2
4 3 3

OUTPUT:
3
1 2
3 1
4 2
*/
