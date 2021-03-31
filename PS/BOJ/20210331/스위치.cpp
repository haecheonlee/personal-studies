#include <iostream>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX_N = 1e5 + 10;

int tree[MAX_N * 4];
int lazy[MAX_N * 4];

void update_lazy(int node, int L, int R) {
	if(lazy[node] != 0) {
		if(lazy[node] & 1) tree[node] = abs(tree[node] - (R - L + 1));
		if(L != R) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(int node, int L, int R, int i, int j) {
	update_lazy(node, L, R);
	
	if(R < i || j < L) return;
	if(i <= L && R <= j) {
		tree[node] = abs(tree[node] - (R - L + 1));
		if(L != R) {
			lazy[node * 2]++;
			lazy[node * 2 + 1]++;
		}
		return;	
	}
	
	int mid = (L + R) / 2;
	update_range(node * 2, L, mid, i, j);
	update_range(node * 2 + 1, mid + 1, R, i, j);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int sum(int node, int L, int R, int i, int j) {
	update_lazy(node, L, R);
	
	if(R < i || j < L) return 0;
	if(i <= L && R <= j) return tree[node];
	
	int mid = (L + R) / 2;
	return sum(node * 2, L, mid, i, j) +sum(node * 2 + 1, mid + 1, R, i, j);
}

int main() {
	fastio
	
	int N, M; cin >> N >> M;
	for(int i = 1; i <= M; i++) {
		int o, s, t; cin >> o >> s >> t;
		
		if(o == 0) {
			// xor
			update_range(1, 1, N, s, t);
		} else {
			// sum
			cout << sum(1, 1, N, s, t) << '\n';
		}
	}
	
	return 0;
}
