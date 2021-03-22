#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N; cin >> N;
	string s; cin >> s;

	vector<int> L, R;
	for(int i = 0; i < N; i++) {
		int x; cin >> x;

		if(s[i] == 'L') L.push_back(x);
		else R.push_back(x);
	}
	sort(L.begin(), L.end()); sort(R.begin(), R.end());
	
	int ans = -1;
	for(int i = 0; i < (int)R.size(); i++) {
		auto it = lower_bound(L.begin(), L.end(), R[i]);

		if(it != L.end()) {
			int p = (abs(R[i] - (*it)) + 1) / 2;
			if(ans == -1 || ans > p) ans = p;
		}
	}
	cout << ans << '\n';

	return 0;
}
