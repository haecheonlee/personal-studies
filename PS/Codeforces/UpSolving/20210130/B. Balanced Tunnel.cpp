#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	int a[N + 1];
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	int b[N + 1];
	for(int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		
		b[x] = i;
	}
	
	int ans = 0, mx = -1;
	for(int i = 1; i <= N; i++) {
		if(mx >= b[a[i]]) ans++;
		mx = max(mx, b[a[i]]);
	}
	cout << ans << '\n';
	
	return 0;
}
