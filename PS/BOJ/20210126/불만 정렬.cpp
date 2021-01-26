/* reference: baekoon/codeplus */

#include <iostream>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 1;

int a[MAX_N];
ll tree1[MAX_N * 4];
ll tree2[MAX_N * 4];

ll sum(ll* tree, int node, int start, int end, int L, int R) {
	if(end < L || R < start) return 0;
	if(L <= start && end <= R) return tree[node];
	
	return sum(tree, node * 2, start, (start + end) / 2, L , R) +
		   sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, L, R);
}

void update(ll* tree, int node, int start, int end, int i, int v) {
	if(i < start || end < i) return;
	
	tree[node] += v;
	if(start != end) {
		update(tree, node * 2, start, (start + end) / 2, i, v);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, i , v);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

int main() {
	fastio
	
	int N;
	cin >> N;
	
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	ll ans = 0;
	for(int i = 1; i <= N; i++) {
		update(tree1, 1, 1, N, a[i], 1);
		update(tree2, 1, 1, N, a[i], sum(tree1, 1, 1, N, a[i] + 1, N));
		ans += sum(tree2, 1, 1, N, a[i] + 1, N);
	}
	cout << ans << '\n';
	
	return 0;
}
