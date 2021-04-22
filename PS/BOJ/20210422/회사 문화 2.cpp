/* reference: beakjoon/codeplus */

#include <iostream>
#include <vector>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX_N = 1e5 + 10;

int timer = 0;
vector<int> G[MAX_N];
int tree[MAX_N * 6];
int lazy[MAX_N * 6];
int tin[MAX_N];
int tout[MAX_N];

void dfs(int x) {
	tin[x] = ++timer;
	for(auto& y : G[x]) dfs(y);
	tout[x] = ++timer;
}

void update_lazy(int node, int L, int R) {
	if(lazy[node] != 0) {
		tree[node] += (R - L + 1) * lazy[node];
		if(L != R) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(int node, int L, int R, int i, int j, int k) {
	update_lazy(node, L, R);
	if(j < L || R < i) return;
	
	if(i <= L && R <= j) {
		lazy[node] += k;
		update_lazy(node, L, R);
		return;
	}
	
	int M = (L + R) / 2;
	update_range(node * 2, L, M, i, j, k);
	update_range(node * 2 + 1, M + 1, R, i, j, k);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node ,int L, int R, int i, int j) {
	update_lazy(node, L, R);
	if(j < L || R < i) return 0;
	
	if(i <= L && R <= j) return tree[node];
	
	int M = (L + R) / 2;
	return query(node * 2, L, M, i, j) + query(node * 2 + 1, M + 1, R, i, j);
}

int main() {
	fastio
	
	int N, M; cin >> N >> M;
	
	for(int i = 1; i <= N; i++) {
		int x; cin >> x;
		if(x != -1) G[x].push_back(i);
	}
	dfs(1);

	while(M--) {
		int q; cin >> q;
		if(q == 1) {
			int i, w; cin >> i >> w;
			update_range(1, 1, timer, tin[i], tout[i], w);
		} else {
			int i; cin >> i;
			cout << query(1, 1, timer, tin[i], tin[i]) << '\n';
		}
	}

	return 0;
}
