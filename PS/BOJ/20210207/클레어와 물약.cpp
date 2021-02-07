#include <iostream>
#include <vector>
#include <queue>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define sc second
#define sz(x) (int)x.size()

using namespace std;

typedef pair<int,int> pii;

const int MAX_N = 2e5 + 1;

vector<pii> G[MAX_N];
vector<int> ind[MAX_N];
bool check[MAX_N];

int main() {
	fastio
	
	int N, M; cin >> N >> M;
	for(int i = 1; i <= M; i++) {
		int k, r; cin >> k;
		
		vector<int> x(k);
		for(int j = 0; j < k; j++) cin >> x[j];
		
		cin >> r;
		ind[r].push_back(k);
		for(int j = 0; j < k; j++) {
			G[x[j]].push_back(make_pair(r, sz(ind[r]) - 1));
		}
	}
	
	int L;
	cin >> L;
	
	queue<int> q;
	for(int i = 1; i <= L; i++) {
		int x; cin >> x;
		q.push(x);
		
		check[x] = 1;
	}
	

	while(!q.empty()) {
		int x = q.front();
		q.pop();
		
		for(auto& nxt : G[x]) {
			int y = nxt.fi, idx = nxt.sc;
			if(check[y]) continue;
			ind[y][idx]--;
			
			if(ind[y][idx] == 0) {
				check[y] = 1;
				q.push(y);
			}
		}
	}
	
	vector<int> ans;
	for(int i = 1; i <= N; i++) {
		if(check[i]) ans.push_back(i);
	}
	cout << (int)ans.size() << '\n';
	for(auto& x : ans) cout << x << ' ';
	
	return 0;
}
