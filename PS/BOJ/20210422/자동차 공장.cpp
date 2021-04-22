#include <iostream>
#include <vector>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

typedef long long ll;

const int MAX_N = 5e5 + 10;

int timer = 0;
int a[MAX_N];
int tin[MAX_N], tout[MAX_N];
int p[MAX_N * 2];
vector<int> G[MAX_N];
ll tree[MAX_N * 2 * 4];
ll lazy[MAX_N * 2 * 4];

void dfs(int x) {
	tin[x] = ++timer;
	p[timer] = x;
	for(auto& y : G[x]) dfs(y);
	tout[x] = ++timer;
}

void init(int node, int L, int R) {
	if(L == R) {
		tree[node] = a[p[L]];
		return;
	}
	
	int M = (L + R) / 2;
	init(node * 2, L, M);
	init(node * 2 + 1, M + 1, R);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
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

ll query(int node, int L, int R, int i, int j) {
	update_lazy(node, L, R);
	if(j < L || R < i) return 0;
	if(i <= L && R <= j) return tree[node];
	
	int M = (L + R) / 2;
	return query(node * 2, L, M, i, j) + query(node * 2 + 1, M + 1, R, i, j);
}

int main() {
	fastio
	int N, M; cin >> N >> M;

	cin >> a[1];
	for(int i = 2; i <= N; i++) {
		int p;
		cin >> a[i] >> p;
		G[p].push_back(i);
	}
	dfs(1);
	init(1, 1, timer);
	
	while(M--){
		char o; cin >> o;
		if(o == 'p') {
			// increase pay in x
			int i, x; cin >> i >> x;
			update_range(1, 1, timer, tin[i] + 1, tout[i] - 1, x);
		} else if(o == 'u') {
			// print pay of a
			int i; cin >> i;
			cout << query(1, 1, timer, tin[i], tin[i]) << '\n';
		}
	}

	return 0;
}
