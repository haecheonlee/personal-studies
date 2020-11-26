#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	int a[M];
	for(int i = 0; i < M; i++) cin >> a[i];
	sort(a, a + M);
	
	int ans = 0, price = 0;
	for(int i = 0; i < M; i++) {
		int sum = a[i] * min(N, M - i);
		if(sum > ans) ans = sum, price = a[i];
	}
	cout << price << ' ' << ans << '\n';
	
	return 0;
}
