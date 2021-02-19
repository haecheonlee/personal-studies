/* editorial */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long calc(vector<int>& x) {
	sort(x.begin(), x.end());
	return x[x.size() / 2] - x[(x.size() - 1) / 2] + 1;
}

void solve() {
	int N; cin >> N;
	vector<int> x(N), y(N);
	for(int i = 0; i < N; i++) cin >> x[i] >> y[i];
	
	cout << calc(x) * calc(y) << '\n';;
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
