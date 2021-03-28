#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 10;

typedef pair<int,int> pii;

pii a[MAX_N];

int main() {
	int N; cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a + N);

	int ans = 0;
	for(int i = 0; i < N; i++) {
		if(a[i].second > i) ans = max(ans, abs(a[i].second - i));
	}
	cout << ans + 1 << '\n';

	return 0;
}
