/* editorial */

#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 10;

ll a[MAX_N];
ll d[MAX_N][3];

int main() {
	ll N, P, Q, R; cin >> N >> P >> Q >> R;
	for(int i = 1; i <= N; i++) cin >> a[i];

	d[1][0] = P * a[1];
	d[1][1] = d[1][0] + Q * a[1];
	d[1][2] = d[1][1] + R * a[1];
	
	for(int i = 2; i <= N; i++) {
		d[i][0] = max(d[i - 1][0], P * a[i]);
		d[i][1] = max(d[i - 1][1], d[i][0] + Q * a[i]);
		d[i][2] = max(d[i - 1][2], d[i][1] + R * a[i]);
	}
	cout << d[N][2] << '\n';

	return 0;
}
