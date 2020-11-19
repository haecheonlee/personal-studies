#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cstring>

#define sz(x) (int)(x.size())

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;

	while(T--) {
		int N;
		cin >> N;

		int a[N];
		ll sum = 0;
		for(int i = 0; i < N; i++) {
			cin >> a[i];
			sum += a[i];
		}

		sort(a, a + N);
		ll ans = (N - 1LL) * a[N - 1] - sum;
		if(ans < 0) {
			ans %= (N - 1);
			if (ans < 0) ans += N - 1;
		}
		cout << ans << '\n';
	}

	return 0;
}
