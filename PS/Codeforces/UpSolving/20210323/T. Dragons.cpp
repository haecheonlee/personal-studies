#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int K, N; cin >> K >> N;
	pair<int, int> a[N];
	for(int i = 0; i < N; i++) cin >> a[i].first >> a[i].second;
	sort(a, a + N);
	
	for(int i = 0; i < N; i++) {
		if(K > a[i].first) {
			K += a[i].second;
		} else {
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';

	return 0;
}
