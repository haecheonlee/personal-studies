/* https://www.youtube.com/watch?v=wad17BQD8n8&ab_channel=ProjectStarcoderbyCSKitty */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define fi first
#define sc second
#define sz(x) (int)x.size()

using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;

const int MAX_N = 5e4 + 1;
const ll INF = 1e15;

int a[MAX_N];
ll d[MAX_N];
bool check[51][51];
vector<int> G[51];

void insert(auto& pq, int& x, int& y) {
	ll nc = d[x] + abs(x - y);
	if(d[y] > nc) {
		d[y] = nc;
		pq.push({d[y], y});
	}
}

int main() {
	fastio
	
	int N, K; cin >> N >> K;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		G[a[i]].push_back(i);	
	}

	for(int i = 1; i <= K; i++) {
		for(int j = 1; j <= K; j++) {
			char x; cin >> x;
			check[i][j] = x - '0';
		}
	}
	
	fill(d, d + MAX_N, INF);
	priority_queue<pli, vector<pli>, greater<pli>> pq;
	pq.push({0, 1});
	d[1] = 0;

	while(!pq.empty()) {
		ll c = pq.top().fi;
		int x = pq.top().sc;
		pq.pop();
		
		if(d[x] < c) continue;
		if(check[a[x]][a[N]]) d[N] = min(d[N], d[x] + N - x);
		for(int k = 1; k <= K; k++) {
			if(check[a[x]][k]) {
				int R = upper_bound(G[k].begin(), G[k].end(), x) - G[k].begin();
				if(R != sz(G[k])) insert(pq, x, G[k][R]);
				int L = -1;
				if(k == a[x]) {
					if(R >= 2) L = R - 2; 	
				} else {
					if(R != 0) L = R - 1;
				}
				if(L >= 0) insert(pq, x, G[k][L]);
			}
		}
	}

	cout << (d[N] == INF ? -1 : d[N]) << '\n';

	return 0;
}
