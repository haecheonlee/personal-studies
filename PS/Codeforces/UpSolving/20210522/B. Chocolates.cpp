#include <iostream>

using namespace std;

const int MAX_N = 2e5 + 10;

int a[MAX_N];

int main() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	long long ans = a[N];
	for(int i = N - 1; i >= 1; i--)	{
		a[i] = min(a[i], max(0, a[i + 1] - 1));
		ans += a[i];
	}
	cout << ans << '\n';
	
	return 0;
}
