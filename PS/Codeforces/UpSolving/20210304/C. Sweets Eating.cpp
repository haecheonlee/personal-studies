/* editorial */

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 1;

ll a[MAX_N], ans[MAX_N];

int main() {
	int N, M; cin >> N >> M;
	for(int i = 1; i <= N; i++) cin >> a[i];
	sort(a + 1, a + 1 + N);
	
	ll sum = 0;
	for(int i = 1; i <= N; i++) {
		sum += a[i];
		ans[i] = sum;
		
		if(i - M >= 0) ans[i] += ans[i - M];
		cout << ans[i] << ' ';
	}

	return 0;
}
