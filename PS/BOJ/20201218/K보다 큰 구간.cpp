#include <iostream>
#include <vector>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

typedef long long ll;

const int MAX = 1e5 + 2;

ll a[MAX];

int main() {
	fastio
	
	int N;
	cin >> N;
	
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	vector<ll> p(N + 1, 0);
	for(int i = 1; i <= N; i++) p[i] = p[i - 1] + a[i];
	
	int K;
	cin >> K;
	
	ll ans = 0, sum = 0;
	for(int i = 1; i <= N; i++) {
		int pos = upper_bound(p.begin() + i, p.end(), K + sum) - p.begin();
		if(pos != N + 1) ans += N - pos + 1;
		sum += a[i];
	}
	cout << ans << '\n';
	
	return 0;
}
