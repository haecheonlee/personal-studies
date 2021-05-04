/* reference: editorial */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int x, y; cin >> x >> y;
	
	double xx = y * log(x);
	double yy = x * log(y);
	
	if(abs(xx - yy) < 1e-8) cout << "=" << '\n';
	else if(xx < yy) cout << "<" << '\n';
	else cout << ">" << '\n';
	
	return 0;
}
