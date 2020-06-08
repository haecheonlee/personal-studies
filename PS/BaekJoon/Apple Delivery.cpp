#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using PI=pair<int,int>;

const int inf=1e9;
const int MAX=1e5+1;

vector<PI> a[MAX];
vector<int> dist;
bool check[MAX];
int n,m,start,p1,p2;

vector<int> dijkstra(int start) {
	// reset
	for(int i=1; i<=n; i++) {
		dist[i]=inf;
		check[i]=false;
	}

	priority_queue<PI> q;
	q.push(make_pair(0,start));
	dist[start]=0;
	
	while(!q.empty()) {
		int from=q.top().second;
		q.pop();
		
		if(check[from]) continue;
		check[from]=true;
		
		for(auto next : a[from]) {
			int to=next.first;
			int next_cost=dist[from]+next.second;
			
			if(dist[to]>next_cost) {
				dist[to]=next_cost;
				q.push(make_pair(-dist[to],to));
			}
		}
	}
	
	return dist;
}

int main() {
	cin>>m>>n>>start>>p1>>p2;
	
	// set size of array of dist
	dist.resize(n+1);
	for(int i=0; i<m; i++) {
		int x,y,z;
		cin>>x>>y>>z;
		
		a[x].push_back(make_pair(y,z));
		a[y].push_back(make_pair(x,z));
	}

	vector<int> d1=dijkstra(start), d2=dijkstra(p1), d3=dijkstra(p2);
	int ans1=d1[p1]+d2[p2];
	int ans2=d1[p2]+d3[p1];
	
	cout<<min(ans1,ans2);
	
	return 0;
}
