#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll=long long;

const int MAX=4e4+1;

int B,E,P,N,M;
vector<int> a[MAX];
int d[3][MAX];

void bfs(int idx, int start) {
	for(int j=1; j<=N; j++) d[idx][j]=-1;
	
	queue<int> q;
	q.push(start);
	d[idx][start]=0;
	
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		for(auto& y : a[x]) {
			if(d[idx][y]==-1) {
				d[idx][y]=d[idx][x]+1;
				q.push(y);
			}
		}
	}
}

int main() {
	cin>>B>>E>>P>>N>>M;
	
	for(int i=1; i<=M; i++) {
		int u,v;
		cin>>u>>v;
		
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	bfs(0,1);	//	Bessie
	bfs(1,2);	//	Elsie
	bfs(2,N);	//	Barn
	
	ll ans=2e9;
	for(int j=1; j<=N; j++) {
		ans=min(ans, 1LL * d[0][j] * B + 1LL * d[1][j] * E + 1LL * d[2][j] * P);
	}
	cout<<ans;
	
	return 0;
}
