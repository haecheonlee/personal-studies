#include <iostream>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX_N = 5e5 + 10;

int a[MAX_N];
int tree[MAX_N * 4];
int lazy[MAX_N * 4];

void init(int node, int L, int R) {
	if(L == R) {
		tree[node] = a[L];
		return;
	}
	
	int mid = (L + R) / 2;
	init(node * 2, L, mid);
	init(node * 2 + 1, mid + 1, R);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

void update_lazy(int node, int L, int R) {
	if(lazy[node] != 0) {
		int cnt = (R - L + 1);
		tree[node] = (cnt & 1 ? tree[node] ^ lazy[node] : tree[node]);
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
		int cnt = (R - L + 1);
		tree[node] = (cnt & 1 ? tree[node] ^ c : tree[node]);
		if(L != R) {
			lazy[node * 2] ^= c;
			lazy[node * 2 + 1] ^= c;
		}
		return;
	}
	
	int mid = (L + R) / 2;
	update_range(node * 2, L, mid, i, j, c);
	update_range(node * 2 + 1, mid + 1, R, i, j, c);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int sum(int node, int L, int R, int i, int j) {
	update_lazy(node, L, R);
	
	if(R < i || j < L) return 0;
	if(i <= L && R <= j) return tree[node];
	
	int mid = (L + R) / 2;
	return sum(node * 2, L, mid, i, j) ^ sum(node * 2 + 1, mid + 1, R, i, j);
}

int main() {
	fastio
	
	int N; cin >> N;
	for(int i = 1; i <= N; i++) cin >> a[i];
	init(1, 1, N);
	
	int M; cin >> M;
	for(int i = 1; i <= M; i++) {
		int q; cin >> q;
		if(q == 1) {
			int s, e, c; cin >> s >> e >> c; 
			s++, e++;
			update_range(1, 1, N, s, e, c);
		} else {
			int s, e; cin >> s >> e;
			s++, e++;
			cout << sum(1, 1, N, s, e) << '\n';
		}
	}
	
	return 0;
}
