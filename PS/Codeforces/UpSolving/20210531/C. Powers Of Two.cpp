/* reference: editorial */

#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main() {
	int N, K; cin >> N >> K;

	queue<int> q;
	map<int, int> ans;
	for(int i = 0; i <= 30; i++) {
		if(N & (1 << i)) {
			if(i > 0) q.push(1 << i);
			ans[1 << i]++;
		}
	}
	
	if(K < (int)ans.size()) {
		cout << "NO" << '\n';
		return 0;
	}
	
	int cnt = ans.size();
	while(cnt < K && !q.empty()) {
		int x = q.front();
		q.pop();
		
		ans[x]--;
		ans[x / 2] += 2;
		if(x / 2 > 1) {
			q.push(x / 2);
			q.push(x / 2);
		}
		cnt++;
	}
	
	if(cnt < K) {
		cout << "NO" << '\n';
		return 0;
	}
	
	cout << "YES" << '\n';
	for(auto& x : ans) for(int i = 0; i < x.second; i++) cout << x.first << ' ';
	cout << '\n';

	return 0;
}
