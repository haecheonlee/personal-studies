#include <iostream>

using namespace std;

const int MAX_N = 1e2 + 1;

int a[MAX_N], p[MAX_N];

void make_tree(int h, int l, int r) {
	if(l > r) return;
	
	int node = -1, mx = -1;
	for(int i = l; i <= r; i++) {
		if(mx < a[i]) node = i, mx = a[i];
	}
	
	p[node] = h;
	make_tree(h + 1, l, node - 1);
	make_tree(h + 1, node + 1, r);
}

void solve() {
	int N; cin >> N;
	
	int root = -1, mx = -1;
	for(int i = 0; i < N; i++) {
		cin >> a[i];
		if(mx < a[i]) mx = a[i], root = i;
	}
	
	make_tree(0, 0, N - 1);
	for(int i = 0; i < N; i++) cout << p[i] << ' ';
	cout << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
