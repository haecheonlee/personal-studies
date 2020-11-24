/* reference: meiron04 */

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>

#define sz(x) (int)(x.size())

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		ll N;
		cin >> N;

		map<ll, int> mp;
		for(ll i = 2; i * i <= N; i++) {
			while(N % i == 0) {
				mp[i]++;
				N /= i;
			}
		}

		if(N > 1) mp[N]++;

		vector<pair<int, ll>> v;
		for(auto& p : mp) v.emplace_back(p.second, p.first);
		sort(v.rbegin(), v.rend());
	
		vector<ll> ans;
		for(int i = 0; i < v[0].first; i++) ans.push_back(v[0].second);
		for(int i = 1; i < sz(v); i++) {
			for(int j = 0; j < v[i].first; j++) {
				ans.back() *= v[i].second;
			}
		}

		cout << sz(ans) << '\n';
		for(auto& x : ans) cout << x << ' ';
		cout << '\n';
	}

	return 0;
}
