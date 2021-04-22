/* reference: beakjoon/codeplus */

#include <iostream>
#include <vector>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX_N = 1e5 + 10;

int a[MAX_N];
vector<int> tree[MAX_N * 4];

void init(int node, int L, int R) {
	if(L == R) {
		tree[node].push_back(a[L]);
		return;
	}
	
	int M = (L + R) / 2;
	init(node * 2, L, M);
	init(node * 2 + 1, M + 1, R);

	merge(tree[node * 2].begin(), tree[node * 2].end(), 
		  tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(),
		  back_inserter(tree[node]));
}

int query(int node, int L, int R, int i, int j, int k) {
	if(j < L || R < i) return 0;
	
	if(i <= L && R <= j) {
		return tree[node].size() - 
			   (upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin());
	}
	
	int M = (L + R) / 2;
	return query(node * 2, L, M, i, j, k) + query(node * 2 + 1, M + 1, R, i, j, k);
}

int main() {
	fastio
	
	int N; cin >> N;
	for(int i = 1; i <= N; i++) cin >> a[i];
	init(1, 1, N);
	
	int Q; cin >> Q;
	int ans = 0;
	while(Q--) {
		int t1, t2, t3; cin >> t1 >> t2 >> t3;
		int i = t1 ^ ans;
		int j = t2 ^ ans;
		int k = t3 ^ ans;
		ans = query(1, 1, N, i, j, k);
		cout << ans << '\n';
	}

	return 0;
}
