#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	ll a, b; cin >> a >> b;
	
	while(a != 0 && b != 0) {
		if(a >= 2 * b) {
			ll x = (a / (2 * b)) * (2 * b);
			a -= x;
		} else if(b >= 2 * a) {
			ll x = (b / (2 * a)) * (2 * a);
			b -= x;
		} else {
			break;
		}
	}
	cout << a << ' ' << b << '\n';
	
	return 0;
}
