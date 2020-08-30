#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using pi=pair<int,int>;

const int INF=1e9;
const int MAX=1e4+1;

int N,M;
vector<pi> a[MAX];
vector<int> mac, star;
bool check[MAX];
int d1[MAX], d2[MAX];	// d1: mac's shortest path, d2: starbuck's shortest path
int MAC_K, STAR_K;

void dijkstra(vector<int> &store, int *d, int upper) {
	fill(d, d+N+1, INF);
	priority_queue<pi> q;
	for(auto& s : store) {
		q.push({0,s});
		d[s]=0;
	}
	
	while(!q.empty()) {
		int cost=-q.top().first;
		int x=q.top().second;
		q.pop();
		
		if(d[x]<cost) continue;
		for(auto& next : a[x]) {
			int y=next.first;
			int weight=next.second+cost;
			if(weight>upper) continue;
			
			if(d[y]>weight) {
				d[y]=weight;
				q.push({-weight,y});
			}
		}
	}
}

int main() {
	cin>>N>>M;

	for(int i=0; i<M; i++) {
		int u,v,c;
		cin>>u>>v>>c;
		
		a[u].push_back({v,c});
		a[v].push_back({u,c});
	}

	int MC;
	cin>>MC>>MAC_K;
	
	while(MC--) {
		int x;
		cin>>x;
		
		mac.push_back(x);
		check[x]=true;
	}
	
	int STAR;
	cin>>STAR>>STAR_K;
	
	while(STAR--) {
		int x;
		cin>>x;
		
		star.push_back(x);
		check[x]=true;
	}
	
	// dijkstra
	dijkstra(mac, d1, MAC_K);
	dijkstra(star,d2, STAR_K);
	
	int ans=-1;
	for(int i=1; i<=N; i++) {
		if(check[i]) continue;
		if(d1[i]==INF || d2[i]==INF) continue;
		
		int dist=d1[i]+d2[i];
		if(ans==-1 || ans>dist) ans=dist;
	}
	cout<<ans;
	
	return 0;
}
