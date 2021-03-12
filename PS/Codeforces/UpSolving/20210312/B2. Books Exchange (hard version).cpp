#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 1;

int a[MAX_N], ans[MAX_N];
bool check[MAX_N];

void go(int x, vector<int>& p) {
	check[x] = 1;
	p.push_back(x);
	
	if(!check[a[x]]) go(a[x], p);
}

void solve() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		ans[i] = check[i] = 0;
	}
	
	for(int i = 1; i <= N; i++) {
		vector<int> p;
		if(!check[i]) go(i, p);
		if(!p.empty()) for(auto& x : p) ans[x] = (int)p.size();
	}
	
	for(int i = 1; i <= N; i++) cout << ans[i] << ' ';
	cout << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
