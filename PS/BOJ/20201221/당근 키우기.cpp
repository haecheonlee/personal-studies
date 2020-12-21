#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	ll X, Y;
	cin >> X >> Y;
	
	if(X > Y) swap(X, Y);
	
	ll extra = X / 10;
	cout << X + Y + extra << '\n';

	return 0;
}
