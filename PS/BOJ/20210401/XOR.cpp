#include <iostream>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

typedef long long ll;

const int MAX_N = 5e5 + 10;

int arr[MAX_N];
ll tree[MAX_N * 4];
ll lazy[MAX_N * 4];

void init(int node, int L, int R) {
	if(L == R) {
		tree[node] = arr[L];
		return;
	}
	
	int mid = (L + R) / 2;
	init(node * 2, L, mid);
	init(node * 2 + 1, mid + 1, R);
}

void update_lazy(int node, int L, int R) {
	if(lazy[node] != 0) {
		tree[node] ^= lazy[node];
		if(L != R) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(int node, int L, int R, int i, int j, ll d) {
	update_lazy(node, L, R);
	
	if(R < i || j < L) return;
	if(i <= L && R <= j) {
		tree[node] ^= d;
		if(L != R) {
			lazy[node * 2] ^= d;
			lazy[node * 2 + 1] ^= d;
		}
		return;
	}
	
	int mid = (L + R) / 2;
	update_range(node * 2, L, mid, i, j, d);
	update_range(node * 2 + 1, mid + 1, R, i, j, d);
}

ll query(int node, int L, int R, int i) {
	update_lazy(node, L, R);
	
	if(R < i || i < L) return 0;
	if(i <= L && R <= i) return tree[node];
	
	int mid = (L + R) / 2;
	return query(node * 2, L, mid, i) + query(node * 2 + 1, mid + 1, R, i);
}

int main() {
	fastio
	
	int N; cin >> N;
	for(int i = 0; i < N; i++) cin >> arr[i];
	init(1, 0, N - 1);
	
	int M; cin >> M;
	for(int i = 1; i <= M; i++) {
		int t; cin >> t;
		if(t == 1) {
			int a, b, c; cin >> a >> b >> c;
			update_range(1, 0, N - 1, a, b, c);
		} else {
			int a; cin >> a;
			cout << query(1, 0, N - 1, a) << '\n';
		}
	}

	return 0;
}
