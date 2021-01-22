#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	int a[N + 1];
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	int ans = 0;
	for(int i = 2; i < N; i++) {
		if(a[i] == 1) continue;
		if(a[i - 1] && a[i + 1]) {
			a[i + 1]--;
			ans++;
		}
	}
	cout << ans << '\n';
	
	return 0;	
}
