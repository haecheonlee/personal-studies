#include <iostream>
#include <vector>
#include <map>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

map<int,bool> mp;

int main() {
	fastio
	
	int N, M; cin >> N >> M;
	for(int i = 0; i < N; i++) {
		int x; cin >> x;
		mp[x] = true;
	}
	
	vector<int> ans;
	int sum = 0, idx = 1;
	while(sum + idx <= M) {
		if(mp.find(idx) == mp.end()) {
			sum += idx;
			ans.push_back(idx);
		}
		idx++;
	}
	
	cout << ans.size() << '\n';
	for(auto& x : ans) cout << x << ' ';
	
	return 0;
}
