#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;

const int MAX = 2e5 + 1;

pli a[MAX];
ll p[MAX];

int main() {
	int T;
	cin >> T;

	while(T--) {
		ll N, W;
		cin >> N >> W;
		
		int m = -1;
		for(int i = 1; i <= N; i++) {
			cin >> a[i].first;
			a[i].second = i;
			
			if(W <= (a[i].first * 2) && a[i].first <= W)	m = i;
		}
		
		if(m != -1) {
			cout << 1 << ' ' << m << '\n';
			continue;
		}
		
		sort(a + 1, a + N + 1);

		vector<int> ans;
		int L = 1, R = 1;
		ll sum = a[1].first;
		
		while(L <= R) {
			if(W <= (sum * 2) && sum <= W) {
				for(int k = L; k <= R; k++) ans.push_back(a[k].second);
				break;
			}

			if(R + 1 <= N && sum + a[R + 1].first <= W) {
				sum += a[R + 1].first;
				R++;
			} else {
				sum -= a[L].first;
				L++;
			}
		}

		if(ans.empty()) {
			cout << -1 << '\n';
		} else {
			cout << ans.size() << '\n';
			for(auto& x : ans) cout << x << ' ';
			cout << '\n';
		}
 	}

	return 0;
}
