/* editorial */

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

const int MAX_N = 2e5 + 1;

int a[MAX_N];
bool check[MAX_N];

bool chk(int start, int end, int k) {
	memset(check, false, sizeof(check));
	
	for(int i = start; i <= end; i++) check[a[i]]= 1;
	for(int i = 1; i <= k; i++) if(!check[i]) return false;
	
	return true;
}

void solve() {
	int N; cin >> N;
	
	int k = 0;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		k = max(k, a[i]);
	}
	
	vector<pii> ans;
	if(chk(1, k, k) && chk(k + 1, N, N - k)) ans.push_back({k, N - k});
	if(k * 2 != N) {
		if(chk(1, N - k, N - k) && chk(N - k + 1, N, k)) ans.push_back({N - k, k});
	}
	
	cout << ans.size() << '\n';
	for(auto& x : ans) cout << x.first << ' ' << x.second << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
