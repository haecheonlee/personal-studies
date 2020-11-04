#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 2e3 + 1;
const int INF = 1e9;

vector<pair<pii,int>> a[MAX];
int d[MAX][201];

int main() {
	int K,N,M;
	cin>>K>>N>>M;
	
	for(int i = 0; i < M; i++) {
		int u,v,t,h;
		cin>>u>>v>>t>>h;
		
		a[u].push_back({{t,h}, v});
		a[v].push_back({{t,h}, u});
	}
	
	// start & end
	int S,E;
	cin>>S>>E;
	
	memset(d, 0x3f, sizeof(d));
	priority_queue<pair<pii,int>> q;
	q.push({{0,0}, S});
	d[S][0] = 0;
	
	while(!q.empty()) {
		int t = -q.top().first.first;
		int h = q.top().first.second;
		int x = q.top().second;
		q.pop();
		
		if(d[x][h] < t) continue;
		for(auto& next : a[x]) {
			int y = next.second;
			int nt = next.first.first + t;
			int nh = next.first.second + h;
			
			if(nh >= K) continue;
			if(d[y][nh] > nt) {
				d[y][nh] = nt;
				q.push({{-nt, nh}, y});
			}
		}
	}
	
	int ans = -1;
	for(int i = 0; i < K; i++) {
		if(d[E][i] >= INF) continue;
		if(ans == -1 || ans > d[E][i]) ans = d[E][i];
	}
	cout<<ans;

	return 0;
}
