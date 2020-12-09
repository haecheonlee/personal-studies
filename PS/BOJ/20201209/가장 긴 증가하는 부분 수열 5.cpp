#include <iostream>
#include <vector>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define sz(x) (int)(x.size())

using namespace std;

const int MAX = 1e6 + 1;

int a[MAX], p[MAX];

int main() {
	fastio
	
	int N;
	cin >> N;
	
	for(int i = 1; i <= N; i++) cin >> a[i];

	vector<int> list;
	for(int i = 1; i <= N; i++) {
		if(list.empty() || list.back() < a[i]) {
			list.push_back(a[i]);
			p[i] = sz(list);
		} else {
			int idx = lower_bound(list.begin(), list.end(), a[i]) - list.begin();
			list[idx] = a[i];
			p[i] = idx + 1;	// index starts from 0, but [p] array starts from 1
		}
	}

	vector<int> ans;
	int current_index = sz(list);
	for(int i = N; i >= 1; i--) {
		if(p[i] == current_index) ans.push_back(a[i]), current_index--;
	}
	
	// print answer
	cout << sz(ans) << '\n';
	for(int i = sz(ans) - 1; i >= 0; i--) cout << ans[i] << ' ';
	
	return 0;
}
