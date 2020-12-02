#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> a;
	for(int i = 0; i < N; i++) {
		int x;
		cin >> x;
		
		if(x == 1) a.push_back(i);
	}

	if(a.size() < K) {
		cout << -1;
	} else {
		int ans = 1e9;
		for(int i = K - 1; i < a.size(); i++) ans = min(ans, a[i] - a[(i + 1) - K] + 1);
		cout << ans;
	}

	return 0;
}
