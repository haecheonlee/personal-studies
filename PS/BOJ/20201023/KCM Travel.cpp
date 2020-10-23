#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
using pii=pair<int,int>;

const int MAX=1e2+1;
const int INF=1e8;

vector<pair<int,pii>> a[MAX];
int d[MAX][10005];

int N,M,K;
int go(int x, int cost) {
	if(cost>K) return INF;
	if(x==N) return 0;

	int& ret=d[x][cost];
	if(ret!=-1) return ret;
	ret=INF;

	for(auto& next : a[x]) {
		int y=next.first;
		int c=next.second.first;
		int t=next.second.second;
		
		int nc = cost + c;
		ret=min(ret, go(y, nc) + t);
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;

	while(T--) {
		cin>>N>>K>>M;

		// reset
		for(int i=1; i<=N; i++) a[i].clear();

		for(int i=0; i<M; i++) {
			int u,v,c,t;
			cin>>u>>v>>c>>t;

			a[u].push_back({v, {c,t}});
		}

		memset(d, -1, sizeof(d));
		int ans=go(1,0);
		if(ans>=INF || ans==-1) cout<<"Poor KCM\n";
		else cout<<ans<<'\n';
	}

	return 0;
}
