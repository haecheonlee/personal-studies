/* reference: _Alireza_ */

#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 100;

int a[MAX_N], b[MAX_N];

int main() {
	int N; cin >> N;
	
	int ans = 1;
	for(int i = 1; i <= N; i++) {
		int x; cin >> x;

		a[x]++;
		b[a[x]]++;

		if(a[x] * b[a[x]] == i && i != N) {
			ans = i + 1;
		} else {
			if(a[x] * b[a[x]] == i - 1) ans = i;
		}
	}
	cout << ans << '\n';

	return 0;
}
