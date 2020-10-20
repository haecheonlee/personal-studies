#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
using pii=pair<int,int>;

const int MAX=1e2+1;
const int INF=1e9;

int K,N,M;
vector<pair<int,pii>> a[MAX];
int d[MAX][10001];

int dfs(int x, int k) {
	if(x==N) return 0;
	
	int& ret=d[x][k];
	if(ret!=-1) return ret;
	ret=INF;
	
	for(auto& next : a[x]) {
		int y=next.first;
		int dist=next.second.first;
		int cost=next.second.second;
		
		if(k-cost>=0) ret=min(ret, dfs(y, k-cost) + dist);
	}
	
	return ret;
}

int main() {
	cin>>K>>N>>M;
	
	for(int i=0; i<M; i++) {
		int u,v,dist,cost;
		cin>>u>>v>>dist>>cost;
		
		a[u].push_back({v, {dist,cost}});
	}

	memset(d, -1, sizeof(d));
	int ans=dfs(1,K);
	cout<<(ans==INF ? -1 : ans);
	
	return 0;
}
