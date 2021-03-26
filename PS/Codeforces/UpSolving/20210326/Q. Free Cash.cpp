#include <iostream>

using namespace std;

int main() {
	int N; cin >> N;
	int h[N], m[N];
	
	int ans = 1, cnt = 1;
	for(int i = 0; i < N; i++) {
		cin >> h[i] >> m[i];
		
		if(i > 0 && h[i - 1] == h[i] && m[i - 1] == m[i]) cnt++;
		else cnt = 1;
		
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
	
	return 0;
}
