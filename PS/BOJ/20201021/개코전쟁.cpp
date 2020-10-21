#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pii=pair<int,int>;

const int MAX=1e3+1;

int N,M;
vector<pii> a[MAX];
int p[MAX], d[MAX];
bool check[MAX][MAX];

void dijkstra() {
	memset(d, 0x3f, sizeof(d));
	priority_queue<pii> q;
	q.push({0,1});
	d[1]=0;
	
	while(!q.empty()) {
		int c=-q.top().first;
		int x=q.top().second;
		q.pop();
		
		if(d[x]<c) continue;
		for(auto& next : a[x]) {
			int y=next.first;
			int nc=next.second+c;
			
			if(d[y]>nc) {
				p[y]=x;
				
				d[y]=nc;
				q.push({-nc,y});
			}
		}
	}
}

int dijkstra2() {
	memset(d, 0x3f, sizeof(d));
	priority_queue<pii> q;
	q.push({0,1});
	d[1]=0;
	
	while(!q.empty()) {
		int c=-q.top().first;
		int x=q.top().second;
		q.pop();
		
		for(auto& next : a[x]) {
			int y=next.first;
			int nc=c+next.second;
			
			if(check[x][y]) continue;
			if(d[y]>nc) {
				d[y]=nc;
				q.push({-nc,y});
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
		
		a[u].push_back({v,c});
		a[v].push_back({u,c});
	}
	
	dijkstra();
	
	int ans=0;
	int x=N;
	while(p[x]!=0) {
		check[p[x]][x]=true;
		ans=max(ans, dijkstra2());
		check[p[x]][x]=false;
		x=p[x];
	}
	cout<<ans;
	
	return 0;
}
