#include <iostream>

using namespace std;

int main() {
	int a, b, c; cin >> a >> b >> c;	

	int ans = 0;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			int sum = 0, sum1 = 0;
			if(i == 0) sum += (a + b); else sum += (a * b);
			if(j == 0) sum += c; else sum *= c;
			
			if(j == 0) sum1 += (b + c); else sum1 += (b * c);
			if(i == 0) sum1 += a; else sum1 *= a;
			
			ans = max(ans, max(sum, sum1));
		}
	}
	
	cout << ans << '\n';

	return 0;
}
