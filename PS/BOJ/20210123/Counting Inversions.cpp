#include <iostream>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

typedef long long ll;

const int MAX = 1e6 + 1;

int a[MAX];
ll tree[MAX * 4];

ll sum(int node, int start, int end, int L, int R) {
	if(L > end || R < start) return 0;
	if(L <= start && end <= R) return tree[node];
	
	return sum(node * 2, start, (start + end) / 2, L, R) +
		   sum(node * 2 + 1, (start + end) / 2 + 1, end, L, R);
}

void update(int node, int start, int end, int i) {
	if(i > end || i < start) return;
	
	tree[node] += 1;
	if(start != end) {
		update(node * 2, start, (start + end) / 2, i);
		update(node * 2 + 1, (start + end) / 2 + 1, end, i);
	}
}

int main() {
	fastio
	
	int N;
	cin >> N;
	
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	ll ans = 0;
	for(int i = 1; i <= N; i++) {
		ans += sum(1, 1, N, a[i], N);
		update(1, 1, N, a[i]);
	}
	cout << ans << '\n';

	return 0;
}
