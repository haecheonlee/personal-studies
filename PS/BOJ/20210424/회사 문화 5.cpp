#include <iostream>
#include <vector>
#include <cstring>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX_N = 1e5 + 10;

int timer = 1;
vector<int> G[MAX_N];
int numbering[MAX_N], numChild[MAX_N];
bool check[MAX_N];
int tree[MAX_N * 4];
int lazy[MAX_N * 4];

int dfs(int x) {
	check[x] = true;
	
	int child = 0;
	for(auto& y : G[x]) if(!check[y]) child += dfs(y);
	
	numbering[x] = timer++;
	numChild[x] = child;
	
	return child + 1;
}

void init(int node, int L, int R) {
	if(L == R) {
		tree[node] = 1;
		return;
	}
	
	int M = (L + R) / 2;
	init(node * 2, L, M);
	init(node * 2 + 1, M + 1, R);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update_lazy(int node, int L, int R) {
	if(lazy[node] != -1) {
		tree[node] = (R - L + 1) * lazy[node];
		if(L != R) {
			lazy[node * 2] = lazy[node];
			lazy[node * 2 + 1] = lazy[node];
		}
		lazy[node] = -1;
	}
}

void update_range(int node, int L, int R, int i, int j, int k) {
	update_lazy(node, L, R);
	if(R < i || j < L) return;
	
	if(i <= L && R <= j) {
		lazy[node] = k;
		update_lazy(node, L, R);
		return;
	}
	
	int M = (L + R) / 2;
	update_range(node * 2, L, M, i, j, k);
	update_range(node * 2 + 1, M + 1, R, i, j, k);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int L, int R, int i, int j) {
	update_lazy(node, L, R);
	if(R < i || j < L) return 0;
	if(i <= L && R <= j) return tree[node];
	
	int M = (L + R) / 2;
	return query(node * 2, L, M, i, j) + query(node * 2 + 1, M + 1, R, i, j);
}

int main() {
	fastio
	
	int N; cin >> N;
	
	int root = -1;
	for(int i = 1; i <= N; i++) {
		int x; cin >> x;
		
		if(x == 0) root = i;
		else G[x].push_back(i);
	}
	dfs(root);
	init(1, 1, N);

	memset(lazy, -1, sizeof(lazy));
	int M; cin >> M;
	while(M--) {
		int o, x; cin >> o >> x;
		if(o == 1) {
			// turn on
			if(numChild[x])
				update_range(1, 1, N, numbering[x] - numChild[x], numbering[x] - 1, 1);
		} else if(o == 2) {
			// turn off
			if(numChild[x])
				update_range(1, 1, N, numbering[x] - numChild[x], numbering[x] - 1, 0);
		} else if(o == 3) {
			// query
			cout << query(1, 1, N, numbering[x] - numChild[x], numbering[x] - 1) << '\n';
		}
	}

	return 0;
}
