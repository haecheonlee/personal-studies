#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e3+1;

vector<pi> a[MAX];
int d[MAX];
int p[MAX];

void print(int x) {
	if(p[x]!=1) print(p[x]);
	cout<<x<<' ';
}

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<M; i++) {
		int u,v,cost;
		cin>>u>>v>>cost;
		
		a[u].push_back({v,cost});
	}
	
	memset(d, -1, sizeof(d));
	priority_queue<pi> q;
	q.push({0,1});
	d[1]=0, p[1]=-1;
	while(!q.empty()) {
		int x=q.top().second;
		int cost=q.top().first;
		q.pop();
		
		if(x==1 && cost>0) continue;
		for(auto& next : a[x]) {
			int y=next.first;
			int next_cost=d[x]+next.second;
			
			if(d[y]==-1 || d[y]<next_cost) {
				d[y]=next_cost, p[y]=x;
				q.push({next_cost, y});
			}
		}
	}
	
	cout<<d[1]<<'\n';
	cout<<1<<' '; print(1);
	
	return 0;
}
