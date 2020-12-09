#include <iostream>

using namespace std;

typedef long long ll;

const int MAX = 1e5 + 1;

ll odd[MAX], even[MAX];

int main() {
	int N;
	cin >> N;
	
	int a[N];
	for(int i = 1; i <= N; i++) cin >> a[i];

	for(int i = 1; i <= N; i++) {
		if(i&1) odd[i] = odd[i - 1] + a[i];
		else odd[i] = odd[i - 1];
	}
	
	for(int i = 1; i <= N; i++) {
		if(!(i&1)) even[i] = even[i - 1] + a[i];
		else even[i] = even[i - 1];
	}
	
	ll ans = odd[N];
	for(int i = 1; i < N; i++) {
		if(i&1) ans = max(ans, odd[i - 1] + even[N - 1] - even[i] + a[N]);
		else ans = max(ans, odd[i - 1] + even[N - 1] - even[i - 1]);
	}
	cout << ans << '\n';
	
	return 0;
}
