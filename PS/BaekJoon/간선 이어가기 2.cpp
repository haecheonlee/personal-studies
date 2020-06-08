#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using PI=pair<int,int>;

const int MAX=5e3+1;
const int inf=1e8;

vector<PI> a[MAX];
int dist[MAX];
bool visited[MAX];

int main() {
	int n,m;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++) dist[i]=inf;
	for(int i=0; i<m; i++) {
		int x,y,z;
		cin>>x>>y>>z;
		
		a[x].push_back(make_pair(y,z));
		a[y].push_back(make_pair(x,z));
	}
	
	int start, end;
	cin>>start>>end;
	
	priority_queue<PI> q;
	q.push(make_pair(0,start));
	dist[start]=0;
	
	while(!q.empty()) {
		int from=q.top().second;
		int cost=-q.top().first;
		q.pop();
		
		if(visited[from]) continue;
		visited[from]=true;
		
		for(auto next : a[from]) {
			int to=next.first;
			int next_cost=dist[from]+next.second;
			
			if(dist[to]>next_cost) {
				dist[to]=next_cost;
				q.push(make_pair(-dist[to], to));
			}
		}
	}
	
	cout<<dist[end];

	return 0;
}
