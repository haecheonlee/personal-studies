#include <iostream>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX_N = 1e5 + 10;

int tree[MAX_N * 4], lazy[MAX_N * 4];

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

void update_range(int node, int L, int R, int i, int j, int c) {
	update_lazy(node, L, R);
	if(R < i || j < L) return;
	if(i <= L && R <= j) {
		lazy[node] += c;
		update_lazy(node, L, R);
		return;
	}
	
	int M = (L + R) / 2;
	update_range(node * 2, L, M, i, j, c);
	update_range(node * 2 + 1, M + 1, R, i, j, c);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int L, int R, int i, int j) {
	update_lazy(node, L, R);
	if(R < i || j < L) return 0;
	if(i <= L && R <= j) {
		int flower = tree[node];
		tree[node] = 0;
		return flower;
	}
	
	int M = (L + R) / 2;
	return query(node * 2, L, M, i, j) + query(node * 2 + 1, M + 1, R, i, j);
}

int main() {
	fastio
	
	int N; cin >> N;
	for(int i = 0; i < N; i++) {
		int L, R; cin >> L >> R;
		
		cout << query(1, 1, MAX_N, L, L) + query(1, 1, MAX_N, R, R) << '\n';
		update_range(1, 1, MAX_N, L + 1, R - 1, 1);
	}
	
	return 0;
}
