#include <iostream>
#include <queue>

using namespace std;
using PI=pair<int,int>;

const int MAX=1e5+1;

vector<PI> a[MAX];
int dist[MAX];

int main() {
	int n,m;
	cin>>n>>m;
	
	for(int i=0; i<=m; i++) dist[i]=-1;
	for(int i=0; i<n; i++) {
		int x,y,z;
		cin>>x>>y>>z;
		
		a[x].push_back(make_pair(y,z));
	}
	
	queue<int> q;
	q.push(0);
	dist[0]=0;
	
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		// +1
		int next=x+1;
		if(next>MAX) continue;
		
		if(dist[next]==-1 || dist[next]>dist[x]+1) {
			dist[next]=dist[x]+1;
			q.push(next);
		}
		
		// shortcut
		for(auto y : a[x]) {
			int to=y.first;
			int cost=y.second;
			
			if(dist[to]==-1 || dist[to]>cost+dist[x]) {
				dist[to]=cost+dist[x];
				q.push(to);
			}
		}
	}
	
	cout<<dist[m];
	
	return 0;
}
