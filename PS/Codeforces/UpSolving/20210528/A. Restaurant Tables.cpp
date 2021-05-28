#include <iostream>

using namespace std;

int main() {
	int N, a, b; cin >> N >> a >> b;
	b *= 2;
	
	int c = 0, ans = 0;
	for(int i = 1; i <= N; i++) {
		int x; cin >> x;
		
		if(x == 1) {
			if(a) a--;
			else if(b >= 2) b -= 2, c++;
			else if(c) c--;
			else ans++;
		} else {
			if(b >= 2) b -= 2;
			else ans += 2;
		}
	}
	cout << ans << '\n';

	return 0;
}
