/* editorial by: adedalic */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int n, d;
		cin >> n >> d;
		
		int MX = (int)sqrt(d) + 2;
		int x;
		for(x = 0; x < MX; x++) {
			if(x + (d + x) / (x + 1) <= n) break;
		}
		cout<<(x < MX ? "YES" : "NO")<<'\n';
	}
	
	return 0;
}
