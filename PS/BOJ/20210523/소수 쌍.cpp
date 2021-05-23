/* reference: codeplus/baekjoon */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct MaximumFlow {
	int N;
	vector<vector<int>> G;
	vector<bool> check;
	vector<int> pred;
	
	MaximumFlow(int N) : N(N) {
		G.resize(N);
		check.resize(N);
		pred.resize(N, -1);
	}
	
	void add_edge(int u, int v) {
		G[u].push_back(v);
	}
	
	bool dfs(int now) {
		if(now == -1) return true;
		for(auto& nxt : G[now]) {
			if(check[nxt]) continue;
			check[nxt] = 1;
			if(dfs(pred[nxt])) {
				pred[nxt] = now;
				return true;
			}
		}
		return false;
	}
	
	int flow() {
		int ans = 0;
		for(int i = 0; i < N; i++) {
			fill(check.begin(), check.end(), false);
			if(dfs(i)) ans++;
		}
		return ans;
	}
};

bool is_prime(int x) {
	for(int i = 2; i * i <= x; i++) if(x % i == 0) return false;
	return true;
}

int main() {
	int N; cin >> N;	
	int a[N];
	for(int i = 0; i < N; i++) cin >> a[i];
	
	vector<int> ans;
	for(int k = 1; k < N; k++) {
		if(!is_prime(a[0] + a[k])) continue;
        
		vector<int> even, odd;
		for(int i = 1; i < N; i++) {
			if(i == k) continue;
			if(a[i] & 1) odd.push_back(a[i]);
			else even.push_back(a[i]);
		}
		
		if(odd.size() != even.size()) continue;
		
		int SZ = odd.size();
		MaximumFlow mf(SZ);
		
		for(int i = 0; i < SZ; i++) for(int j = 0; j < SZ; j++)
			if(is_prime(odd[i] + even[j])) 
				mf.add_edge(i, j);
		
		if(mf.flow() == SZ) ans.push_back(a[k]);
	}
	
	if(ans.empty()) {
		cout << -1 << '\n';
	} else {
		sort(ans.begin(), ans.end());
		for(auto& x : ans) cout << x << ' ';
	}
	
	return 0;
}
