/* reference: https://sys09270883.github.io/ps/6/#17941%EB%B2%88-%EB%AA%A9%EC%9E%A5-cctv */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e5 + 1;

int N, K, M;
int a[MAX];
vector<pii> G[MAX];
int cost[MAX];
bool check[MAX];

bool chk(int mid) {

	int cnt = 0;
	queue<int> q;
	for(int i = 1; i <= N; i++) {
		cost[i] = a[i];
		check[i] = false;
		
		if(a[i] <= mid) {
			cnt++;
			check[i] = true;
			q.push(i);
		}
	}
	
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		
		for(auto& p : G[u]) {
			int v = p.first;
			int c = p.second;
			
			if(check[v]) continue;
			
			cost[v] -= c;
			if(cost[v] <= mid) {
				check[v] = true;
				cnt++;
				q.push(v);
			}
		}
	}

	
	return cnt >= K;
}

int main() {
	fastio
	
	cin >> N >> K;
	
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	cin >> M;
	for(int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		
		G[u].push_back({v, c});
	}
	
	int ans = 1e8;
	int L = 1, R = 1e8;
	while(L <= R) {
		int mid = (L + R) / 2;
		if(chk(mid)) ans = min(ans, mid), R = mid - 1;
		else L = mid + 1;
	}
	cout << ans << '\n';
	
	return 0;
}
