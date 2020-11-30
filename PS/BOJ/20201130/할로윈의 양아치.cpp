#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

const int MAX = 3e4 + 1;

vector<int> G[MAX];
int a[MAX], d[MAX];
bool check[MAX];
pli p[MAX];
int grp;

void dfs(int u) {
	p[grp].first += a[u];
	p[grp].second++;	
	check[u] = true;
	
	for(auto& v : G[u]) if(!check[v]) dfs(v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, K;
	cin >> N >> M >> K;
	
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		
		G[u].push_back(v);
		G[v].push_back(u);
	}

	for(int i = 1; i <= N; i++) {
		if(!check[i]) {
			dfs(i);
			grp++;
		}
	}

	for(int i = 0; i < grp; i++) {
		int v = p[i].first;
		int k = p[i].second;

		for(int j = K - 1; j >= 0; j--) {
			if(j - k >= 0 && d[j] < d[j - k] + v) d[j] = d[j - k] + v;
		}
	}

	int ans = 0;
	for(int k = 0; k < K; k++) ans = max(ans, d[k]);
	cout << ans;
	
	return 0;
}
