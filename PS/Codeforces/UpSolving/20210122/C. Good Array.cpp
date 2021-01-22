#include <iostream>
#include <vector>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;

int main() {
	fastio
	
	int N;
	cin >> N;

	ll sum = 0;
	vector<pli> a(N);
	for(int i = 0; i < N; i++) {
		cin >> a[i].first;
		a[i].second = i + 1;
		sum += a[i].first;	
	}
	sort(a.begin(), a.end());

	vector<int> ans;
	for(int i = 0; i < N; i++) {
		if(i == N - 1) {
			sum -= a[i].first;
			if(sum - a[N - 2].first == a[N - 2].first) ans.push_back(a[i].second);
			sum += a[i].first;
		} else {
			sum -= a[i].first;
			if(sum - a[N - 1].first == a[N - 1].first) ans.push_back(a[i].second);
			sum += a[i].first;
		}
	}

	cout << (int)ans.size() << '\n';
	for(auto& x : ans) cout << x << ' ';

	return 0;
}
