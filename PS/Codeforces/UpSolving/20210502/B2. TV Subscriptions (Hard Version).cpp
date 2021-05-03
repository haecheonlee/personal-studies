#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAX_N = 2e5 + 10;

int a[MAX_N];
int p[MAX_N];

void solve() {
	int N, K, D; cin >> N >> K >> D;
	vector<int> b;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		b.push_back(a[i]);
	}
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	for(int i = 0; i < b.size(); i++) p[i] = 0;
	
	for(int i = 1; i <= N; i++) a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
	
	set<int> show;
	for(int i = 1; i <= D; i++) {
		if(p[a[i]] == 0) show.insert(a[i]);
		p[a[i]]++;
	}
	
	int ans = show.size();
	for(int i = D + 1; i <= N; i++) {
		p[a[i - D]]--;
		if(p[a[i - D]] == 0) show.erase(a[i - D]);
		p[a[i]]++;
		show.insert(a[i]);
		
		ans = min(ans, (int)show.size());
	}
	
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
