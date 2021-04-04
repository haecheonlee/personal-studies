#include <iostream>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAX_N = 2e5 + 10;
const ll INF = 1e18;

int a[MAX_N];
pll tree[MAX_N * 4];
ll lazy[MAX_N * 4];

void init(int node, int L, int R) {
	if(L == R) {
		tree[node].fi = tree[node].sc = a[L];
		return;
	}
	
	int mid = (L + R) / 2;
	init(node * 2, L, mid);
	init(node * 2 + 1, mid + 1, R);
	tree[node].fi = tree[node * 2].fi + tree[node * 2 + 1].fi;
	tree[node].sc = min(tree[node * 2].sc, tree[node * 2 + 1].sc);
}

void update_lazy(int node, int L, int R) {
	if(lazy[node] != 0) {
		ll v = (R - L + 1) * lazy[node];
		tree[node].fi += v;
		tree[node].sc += lazy[node];
		
		if(L != R) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(int node, int L, int R, int i, int j, ll v) {
	update_lazy(node, L, R);
	
	if(R < i || j < L) return;
	if(i <= L && R <= j) {
		lazy[node] += v;
		update_lazy(node, L, R);
		return;
	}
	
	int mid = (L + R) / 2;
	update_range(node * 2, L, mid, i, j, v);
	update_range(node * 2 + 1, mid + 1, R, i, j, v);
	tree[node].fi = tree[node * 2].fi + tree[node * 2 + 1].fi;
	tree[node].sc = min(tree[node * 2].sc, tree[node * 2 + 1].sc);
}

ll queryM(int node, int L, int R, int i, int j) {
	update_lazy(node, L, R);
	
	if(R < i || j < L) return INF;
	if(i <= L && R <= j) return tree[node].sc;
	
	int mid = (L + R) / 2;
	return min(queryM(node * 2, L, mid, i, j), queryM(node * 2 + 1, mid + 1, R, i, j));
}

ll queryS(int node, int L, int R, int i, int j) {
	update_lazy(node, L, R);
	
	if(R < i || j < L) return 0;
	if(i <= L && R <= j) return tree[node].fi;
	
	int mid = (L + R) / 2;
	return queryS(node * 2, L, mid, i, j) + queryS(node * 2 + 1, mid + 1, R, i, j);
}

int main() {
	fastio
	
	int N, M; cin >> N >> M;
	for(int i = 1; i <= N; i++) cin >> a[i];
	init(1, 1, N);
	
	for(int i = 1; i <= M; i++) {
		char o; cin >> o;
		int s, e, v; cin >> s >> e;
		
		if(o == 'P') {
			// update
			cin >> v;
			update_range(1, 1, N, s, e, v);
		} else if(o == 'M') {
			// find minimum between A and B
			cout << queryM(1, 1, N, s, e) << '\n';
		} else if(o == 'S') {
			// sum
			cout << queryS(1, 1, N, s, e) << '\n';
		}
	}

	return 0;
}
