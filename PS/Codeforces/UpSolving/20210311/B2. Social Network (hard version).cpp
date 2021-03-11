#include <iostream>
#include <queue>
#include <map>

#define sz(x) (int)x.size()
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX_N = 2e5 + 1;

int a[MAX_N];

int main() {
  fastio
  
	int N, K; cin >> N >> K;	
	for(int i = 0; i < N; i++) cin >> a[i];
	
	map<int,bool> check;
	queue<int> q;
	for(int i = 0; i < N; i++) {
		if(!check[a[i]]) {
			// not found
			
			if(sz(q) == K) {
				check[q.front()] = 0;
				q.pop();
			}
			
			q.push(a[i]);
			check[a[i]] = 1;
		}
	}
	
	vector<int> ans;
	while(!q.empty()) {
		ans.push_back(q.front());
		q.pop();
	}
	
	cout << sz(ans) << '\n';
	for(int i = sz(ans) - 1; i >= 0; i--) cout << ans[i] << ' ';

	return 0;
}
