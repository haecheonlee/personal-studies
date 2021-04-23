/* reference: https://degurii.tistory.com/26 */

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 10;

int timer = 1;
int a[MAX_N], p[MAX_N];
vector<int> G[MAX_N];
int numbering[MAX_N], numChild[MAX_N];
int tree[MAX_N * 4], lazy[MAX_N * 4];
bool check[MAX_N];

int dfs(int x) {
	check[x] = true;
	int child = 0;
	for(auto& y : G[x]) {
		if(!check[y]) child += dfs(y);
	}
	
	numbering[x] = timer;
	p[timer++] = a[x];
	numChild[x] = child;
	return child + 1;
}

void init(int node, int L, int R) {
	if(L == R) {
		tree[node] = p[L];
		return;
	}
	
	int M = (L + R) / 2;
	init(node * 2, L, M);
	init(node * 2 + 1, M + 1, R);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

void update_lazy(int node, int L, int R) {
	if(lazy[node] != 0) {
		int k = (R - L + 1);
		if(k & 1) tree[node] ^= lazy[node];
		if(L != R) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(int node, int L, int R, int i, int j, int c) {
	update_lazy(node, L, R);
	if(R < i || j < L) return;
	if(i <= L && R <= j) {
		lazy[node] ^= c;
		update_lazy(node, L, R);
		return;
	}
	
	int M = (L + R) / 2;
	update_range(node * 2, L, M, i, j, c);
	update_range(node * 2 + 1, M + 1, R, i, j, c);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int query(int node, int L, int R, int i, int j) {
	update_lazy(node, L, R);
	if(R < i || j < L) return 0;
	if(i <= L && R <= j) return tree[node];
	
	int M = (L + R) / 2;
	return query(node * 2, L, M, i, j) ^ query(node * 2 + 1, M + 1, R, i, j);
}

int main() {
	fastio
	
	int N, M; cin >> N >> M;
	for(int i = 0; i < N - 1; i++) {
		int A, B; cin >> A >> B;
		G[A].push_back(B);
		G[B].push_back(A);
	}
	for(int i = 1; i <= N; i++) cin >> a[i];
	dfs(1);
	init(1, 1, N);
	
	while(M--) {
		int o; cin >> o;
		if(o == 1) {
			int x; cin >> x;
			cout << query(1, 1, N, numbering[x] - numChild[x], numbering[x]) << '\n';
		} else if(o == 2) {
			int x, y; cin >> x >> y;
			update_range(1, 1, N, numbering[x] - numChild[x], numbering[x], y);
		}
	}
	
	return 0;
}
