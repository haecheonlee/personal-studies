#include <iostream>
#include <vector>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX_N = 1e5 + 10;

vector<int> G[MAX_N];
int timer = 1;
int numbering[MAX_N], numChild[MAX_N];
bool check[MAX_N];
int tree1[MAX_N * 4], lazy1[MAX_N * 4];
int tree2[MAX_N * 4], lazy2[MAX_N * 4];

int dfs(int x) {
	check[x] = 1;
	
	int child = 0;
	for(auto& y : G[x]) if(!check[y]) child += dfs(y);
	
	numbering[x] = timer++;
	numChild[x] = child;
	
	return child + 1;
}

void update_lazy(int* tree, int* lazy, int node, int L, int R) {
	if(lazy[node] != 0) {
		tree[node] += (R - L + 1) * lazy[node];
		if(L != R) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(int* tree, int* lazy, int node, int L, int R, int i, int j, int c) {
	update_lazy(tree, lazy, node, L, R);
	if(R < i || j < L) return;
	if(i <= L && R <= j) {
		lazy[node] += c;
		update_lazy(tree, lazy, node, L, R);
		return;
	}
	
	int M = (L + R) / 2;
	update_range(tree, lazy, node * 2, L, M, i, j, c);
	update_range(tree, lazy, node * 2 + 1, M + 1, R, i, j , c);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int* tree, int* lazy, int node, int L, int R, int i, int j) {
	update_lazy(tree, lazy, node, L, R);
	if(R < i || j < L) return 0;
	if(i <= L && R <= j) return tree[node];
	
	int M = (L + R) / 2;
	return query(tree, lazy, node * 2, L, M, i, j) + 
		   query(tree, lazy, node * 2 + 1, M + 1, R, i, j);
}

int main() {
	fastio
	
	int N, M; cin >> N >> M;	
	for(int i = 1; i <= N; i++) {
		int x; cin >> x;
		if(x != -1) G[x].push_back(i);
	}
	dfs(1);

	bool down = true;
	while(M--) {
		int o; cin >> o;
		if(o == 1) {
			// update
			int i, w; cin >> i >> w;
			if(down) update_range(tree1, lazy1, 1, 1, N, numbering[i] - numChild[i], numbering[i], w); 
			else update_range(tree2, lazy2, 1, 1, N, numbering[i], numbering[i], w);
		} else if(o == 2) {
			// query
			int i; cin >> i;
			cout << query(tree1, lazy1, 1, 1, N, numbering[i], numbering[i]) + 
					query(tree2, lazy2, 1, 1, N, numbering[i] - numChild[i], numbering[i]) << '\n';
		} else if(o == 3) {
			down = !down;
		}
	}

	return 0;
}
