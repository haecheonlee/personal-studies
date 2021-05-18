#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e4 + 10;

int ans = 1;
vector<int> G[MAX_N];
int c[MAX_N];

void dfs(int x) {
	for(auto& y : G[x]) {
		if(c[y] != c[x]) ans++;
		dfs(y);
	}
}

int main() {
	int N; cin >> N;
	for(int i = 2; i <= N; i++) {
		int x; cin >> x;
		G[x].push_back(i);
	}
	for(int i = 1; i <= N; i++) cin >> c[i];
	
	dfs(1);
	cout << ans << '\n';
	
	return 0;
}
