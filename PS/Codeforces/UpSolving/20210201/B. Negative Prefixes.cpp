#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e2 + 1;

int a[MAX_N];
int l[MAX_N];

void solve() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	vector<int> p;
	for(int i = 1; i <= N; i++) {
		cin >> l[i];
		if(l[i] == 0) p.push_back(a[i]);	
	}
	
	sort(p.rbegin(), p.rend());
	int L = 0;
	for(int i = 1; i <= N; i++) {
		if(l[i] == 1) cout << a[i] << ' ';
		else cout << p[L++] << ' ';
	}
	cout << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
