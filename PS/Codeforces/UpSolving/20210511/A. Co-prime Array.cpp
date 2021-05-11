#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e3 + 10;

int a[MAX_N];

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int N; cin >> N;

	for(int i = 0; i < N; i++) cin >> a[i];
	
	vector<int> ans;
	for(int i = 0; i < N - 1; i++) {
		ans.push_back(a[i]);

		int r = gcd(a[i], a[i + 1]);
		if(r != 1) ans.push_back(1);
	}
	ans.push_back(a[N - 1]);
	
	cout << ans.size() - N << '\n';
	for(auto& x : ans) cout << x << ' ';
	
	return 0;
}
