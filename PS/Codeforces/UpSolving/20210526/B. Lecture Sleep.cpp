#include <iostream>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX_N = 1e5 + 10;

int a[MAX_N], t[MAX_N];

int main() {
	fastio
	
	int N, K; cin >> N >> K;
	int ans = 0;
	
	for(int i = 1; i <= N; i++) cin >> a[i];
	for(int i = 1; i <= N; i++) {
		cin >> t[i];
		if(t[i] == 1) ans += a[i];	
	}
	
	int sum = 0;
	for(int i = 1; i <= K; i++) if(t[i] == 0) sum += a[i];
	
	int mx = sum;
	for(int i = K + 1; i <= N; i++) {
		if(t[i - K] == 0) sum -= a[i - K];
		if(t[i] == 0) sum += a[i];
		
		mx = max(mx, sum);
	}
	
	ans += mx;
	cout << ans << '\n';
	
	return 0;
}
