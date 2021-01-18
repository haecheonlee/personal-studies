/* reference: editoral */

#include <iostream>

using namespace std;

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	int x, y, x1, y1, x2, y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	x += -a + b, y += -c + d;
	
	if(x >= x1 && x <= x2 && y >= y1 && y <= y2 && (x2 > x1 || (a + b) == 0) && (y2 > y1 || c + d == 0)) {
	  	cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
}

int main() {
	int T;
	cin >> T;

	while(T--) solve();
	
	return 0;
}
