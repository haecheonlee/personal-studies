#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long long x; cin >> x;
	
	if(x <= 9) {
		cout << x << '\n';
	} else {
		string s = to_string(x);
		
		long long sum = (s[0] - '0' - 1);
		for(int i = 1; sum * 10 + 9 <= x; i++) sum = sum * 10 + 9;
		long long r = x - sum;
		
		long long ans = 0;
		while(sum) {
			ans += sum % 10;
			sum /= 10;
		}
		
		while(r) {
			ans += r % 10;
			r /= 10;
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
