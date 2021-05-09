/* reference: beakjoon/codeplus */

#include <iostream>
#include <vector>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

const int MAX_N = 2e5 + 10;

vector<pii> a;
vector<int> b;
int tree[MAX_N * 4];
int lazy[MAX_N * 4];

void update_lazy(int node, int L, int R) {
	if(lazy[node] != 0) {
		tree[node] = max(tree[node], lazy[node]);
		if(L != R) {
			lazy[node * 2] = max(lazy[node * 2], lazy[node]);
			lazy[node * 2 + 1] = max(lazy[node * 2 + 1], lazy[node]);
		}
		lazy[node] = 0;
		return;
	}
}

void update_range(int node, int L, int R, int i, int j, int c) {
	update_lazy(node, L, R);
	
	if(j < L || R < i) return;
	if(i <= L && R <= j) {
		lazy[node] = max(lazy[node], c);
		update_lazy(node, L, R);
		return;
	}
	
	int M = (L + R) / 2;
	update_range(node * 2, L, M, i, j, c);
	update_range(node * 2 + 1, M + 1, R, i, j, c);
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int query(int node, int L, int R, int i, int j) {
	update_lazy(node, L, R);
	
	if(j < L || R < i) return 0;
	if(i <= L && R <= j) return tree[node];
	
	int M = (L + R) / 2;
	int q1 = query(node * 2, L, M, i, j);
	int q2 = query(node * 2 + 1, M + 1, R, i, j);
	
	return max(q1, q2);
}

int main() {
	fastio
	
	int N;	cin >> N;
	
	a.resize(N);
	for(int i = 0; i < N; i++) {
		int l, r; cin >> l >> r;
		int start = r, end = r + l - 1;
		
		a[i] = make_pair(start, end);
		b.push_back(start);
		b.push_back(end);
	}
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	
	for(int i = 0; i < N; i++) {
		int x = lower_bound(b.begin(), b.end(), a[i].fi) - b.begin();
		int y = lower_bound(b.begin(), b.end(), a[i].sc) - b.begin();

		a[i] = make_pair(x, y);
	}

	int SZ = b.size();
	for(int i = 0; i < N; i++) {
		int max_h = query(1, 0, SZ - 1, a[i].fi, a[i].sc);
		update_range(1, 0, SZ - 1, a[i].fi, a[i].sc, max_h + 1);
	}
	
	cout << tree[1] << '\n';
	
	return 0;
}
