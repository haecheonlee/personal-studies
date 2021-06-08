#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 1e3 + 10;

int a[MAX_N], ans[MAX_N];
vector<int> G[MAX_N];
bool check[MAX_N];

int go(int x) {
	check[x] = 1;
	
	for(auto& y : G[x]) {
		if(check[y]) return y;
		return go(y);
	}
}

int main() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		G[i].push_back(a[i]);	
	}
	
	for(int i = 1; i <= N; i++) {
		memset(check, false, sizeof(check));
		ans[i] = go(i);
	}
	for(int i = 1; i <= N; i++) cout << ans[i] << ' ';
	
	return 0;
}
