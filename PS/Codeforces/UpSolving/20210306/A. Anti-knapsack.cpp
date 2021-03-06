#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 1e3 + 1;

bool check[MAX_N];

void solve() {
	int N, K; cin >> N >> K;
	memset(check, false, sizeof(check));
	
	for(int i = N; i >= 1; i--) {
		if(i > K) continue;
		else if(i == K) check[i] = 1;
		else if(i != K - i && K - i < i) check[K - i] = 1;
	}
	
	vector<int> ans;
	for(int i = 1; i <= N; i++) if(!check[i]) ans.push_back(i);
	cout << ans.size() << '\n';
	for(auto& x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
