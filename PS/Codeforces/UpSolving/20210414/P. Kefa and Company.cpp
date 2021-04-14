#include <iostream>
#include <algorithm>

#define fi first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5 + 10;

pll a[MAX_N];

int main() {
	int N, D; cin >> N >> D;
	for(int i = 1; i <= N; i++) cin >> a[i].fi >> a[i].sc;
	sort(a + 1, a + 1 + N);
	
	long long ans = 0, sum = 0;
	int L = 1, R = 1;
	while(L <= R && L <= N && R <= N) {
		if(L == R && R <= N) {
			sum += a[R].sc;
			R++;
		} else {
			ll diff = a[R].fi - a[L].fi;
			if(diff < D) {
				sum += a[R].sc;
				R++;
			} else {
				sum -= a[L].sc;
				L++;
			}
		}
		ans = max(ans, sum);
	}
	cout << ans << '\n';
	
	return 0;
}
