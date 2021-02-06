#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define sz(x) (int)(x.size())
#define fi first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1e5 + 1;

int a[MAX], b[MAX], c[MAX];
set<int> diff[MAX], same[MAX];
multiset<int> cHave;

void solve() {
	int N, M; cin >> N >> M;
	
	cHave.clear();
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		diff[i].clear(), same[i].clear();	
	}
	for(int i = 1; i <= N; i++) {
		cin >> b[i];
		
		if(a[i] != b[i]) diff[b[i]].insert(i);
		else same[b[i]].insert(i);
	}

	for(int i = 1; i <= M; i++) {
		cin >> c[i];
		if(!diff[c[i]].empty() || !same[c[i]].empty()) cHave.insert(c[i]);
	}

	vector<int> ans(M + 1, 0);
	for(int i = 1; i <= M; i++) {
		if(cHave.find(c[i]) != cHave.end())
			cHave.erase(cHave.lower_bound(c[i]));	

		if(!diff[c[i]].empty()) {
			ans[i] = *diff[c[i]].begin();
			diff[c[i]].erase(*diff[c[i]].begin());
			same[c[i]].insert(ans[i]);
		} else if(!same[c[i]].empty()) {
			ans[i] = *same[c[i]].begin();
		} else {
			int color = *cHave.begin();

			if(cHave.empty()) {
				cout << "NO" << '\n';
				return;
			} else if(!diff[color].empty()) {
				ans[i] = *diff[color].begin();
			} else if(!same[color].empty()) {
				ans[i] = *same[color].begin();
				diff[color].insert(*same[color].begin());
				same[color].erase(*same[color].begin());
			} else {
				cout << "NO" << '\n';
				return;
			}
		}
	}
	
	for(int i = 1; i <= N; i++) {
		if(!diff[i].empty()) {
			cout << "NO" << '\n';
			return;
		}
	}
	
	cout << "YES" << '\n';
	for(int i = 1; i <= M; i++) cout << ans[i] << ' ';
	cout << '\n';
}

int main() {
	fastio

	int T; cin >> T;
	while(T--) solve();

	return 0;
}
