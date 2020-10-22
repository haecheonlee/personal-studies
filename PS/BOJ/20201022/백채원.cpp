#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pii=pair<int,int>;

const int MAX=2e5+1;

int N,M,K;
vector<pii> a[MAX];
vector<int> stalkers;
int d[MAX];
bool check[MAX];

void dijkstra() {
	memset(d, 0x7f, sizeof(d));

	priority_queue<pii> q;
	for(auto& x : stalkers) { d[x]=0; q.push({0,x}); }

	while(!q.empty()) {
		int c=-q.top().first;
		int x=q.top().second;
		q.pop();

		if(d[x]<c) continue;
		for(auto& next : a[x]) {
			int y=next.first;
			int nc=c+next.second;

			if(d[y]>nc) {
				d[y]=nc;
				q.push({-nc,y});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin>>N>>M>>K;

	for(int i=0; i<M; i++) {
		int u,v,c;
		cin>>u>>v>>c;

		a[u].push_back({v,c});
		a[v].push_back({u,c});
	}

	stalkers.resize(K);
	for(int i=0; i<K; i++) cin>>stalkers[i];

	// dijkstra by stalkers
	dijkstra();

	// dijkstra by Chaewon
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
				check[y]=true;
				d[y]=nc;
				q.push({-nc,y});
			} 
		}
	}

	vector<int> ans;
	for(int i=2; i<=N; i++) {
		if(check[i]) ans.push_back(i);
	}

	if(ans.size()) for(auto& x : ans) cout<<x<<' ';
	else cout<<0;

	return 0;
}
