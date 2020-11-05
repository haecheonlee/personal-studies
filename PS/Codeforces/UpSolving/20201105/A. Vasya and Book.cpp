#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		int n, x, y, d;
		cin >> n >> x >> y >> d;
		
		int ans = 1e9;
		
		if((y - 1) % d == 0) ans = min(ans, (int)ceil((double)x / d) + ((y - 1) / d));
		if(abs(y - x) % d == 0) ans = min(ans, abs(y - x) / d);
		if((n - y) % d == 0) ans = min(ans, (int)ceil((double)(n - x) / d) + (n - y) / d);
		
		cout << (ans == 1e9 ? -1 : ans) << '\n';
	}
	
	return 0;
}
