/* reference: https://justicehui.github.io/ps/2020/06/22/BOJ12895/ */

#include <iostream>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX_N = 1e5 + 10;

int N, T, Q;
int tree[MAX_N * 4];
int lazy[MAX_N * 4];

void update_lazy(int node, int L, int R) {
	if(lazy[node] != 0) {
		tree[node] = lazy[node];
		if(L != R) {
			lazy[node * 2] = lazy[node];
			lazy[node * 2 + 1] = lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(int node, int L, int R, int i, int j, int c) {
	update_lazy(node, L, R);
	
	if(R < i || j < L) return;
	if(i <= L && R <= j) {
		lazy[node] = c;
		update_lazy(node, L, R);
		return;
	}
	
	int mid = (L + R) / 2;
	update_range(node * 2, L, mid, i, j, c);
	update_range(node * 2 + 1, mid + 1, R, i, j, c);
	tree[node] = tree[node * 2] | tree[node * 2 + 1];
}

int query(int node, int L, int R, int i, int j) {
	update_lazy(node, L, R);
	
	if(R < i || j < L) return 0;
	if(i <= L && R <= j) return tree[node];
	
	int mid = (L + R) / 2;
	return query(node * 2, L, mid, i, j) | query(node * 2 + 1, mid + 1, R, i, j);
}

int main() {
	fastio
	
	cin >> N >> T >> Q;
	update_range(1, 1, N, 1, N, 1);
	
	while(Q--) {
		char o; cin >> o;
		int x, y, z; cin >> x >> y;
		if(x > y) swap(x, y);
		
		if(o == 'C') {
			// update
			cin >> z;
			update_range(1, 1, N, x, y, 1 << (z - 1));
		} else if(o == 'Q') {
			// query
			cout << __builtin_popcount(query(1, 1, N, x, y)) << '\n';
		}
	}
	
	return 0;
}
