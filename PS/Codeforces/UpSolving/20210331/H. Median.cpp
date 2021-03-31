#include <iostream>
#include <vector>
#include <algorithm>

#define sz(x) (int)x.size()

using namespace std;

int main() {
	int N, X; cin >> N >> X;

	vector<int> a(N);
	bool found = 0;
	for(int i = 0; i < N; i++) {
		cin >> a[i];
		if(a[i] == X) found = 1;
	}
	if(!found) a.push_back(X);
	sort(a.begin(), a.end());
	
	int L = lower_bound(a.begin(), a.end(), X) - a.begin();
	int R = upper_bound(a.begin(), a.end(), X) - a.begin() - 1;

	int K = (found ? N : N + 1);
	for(int i = 0; i <= N; i++, K++) {
		int median = (K + 1) / 2 - 1;
		if(L <= median && median <= R) break;
		if(R < median) L++, R++;
	}
	cout << K - N << '\n';

	return 0;
}
