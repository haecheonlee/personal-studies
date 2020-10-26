#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
using pii=pair<int,int>;

const int MAX=1e4+1;

vector<pii> a[MAX];
vector<int> markets, indexes;
int d[5][MAX];
bool check[MAX];

void dijkstra(int start, int idx) {
	priority_queue<pii> q;
	q.push({0, start});
	d[idx][start]=0;

	while(!q.empty()) {
		int c=-q.top().first;
		int x=q.top().second;
		q.pop();

		if(d[idx][x]<c) continue;
		for(auto& next : a[x]) {
			int y=next.first;
			int nc=c+next.second;

			if(d[idx][y]>nc) {
				d[idx][y]=nc;
				q.push({-nc,y});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N,M,K;
	cin>>N>>M>>K;

	markets.resize(K);
	for(int i=0; i<K; i++) { cin>>markets[i]; check[markets[i]]=true; }

	for(int i=0; i<M; i++) {
		int u,v,c;
		cin>>u>>v>>c;

		a[u].push_back({v,c});
		a[v].push_back({u,c});
	}

	memset(d, 0x3f, sizeof(d));
	for(int i=0; i<K; i++) dijkstra(markets[i], i);

	int ans=1e9;
	
	for(int i=0; i<K; i++) indexes.push_back(i);
	do {
		for(int i=1; i<=N; i++) {
			if(check[i]) continue;
			
			int sum=d[indexes[0]][i];
			for(int j=0; j<K; j++) {
				if(j+1<K) sum+=d[indexes[j]][markets[indexes[j+1]]];
				else sum+=d[indexes[j]][i];
			}
			ans=min(ans, sum);
		}
	} while(next_permutation(indexes.begin(), indexes.end()));
	
	// print answer
	cout<<ans;	

	return 0;
}
