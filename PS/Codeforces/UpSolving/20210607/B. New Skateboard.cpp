#include <iostream>

using namespace std;

int main() {
	string s; cin >> s;
	int N = s.size();
	
	long long ans = 0;
	if((s[0] - '0') % 4 == 0) ans++;

	for(int i = 0; i < N - 1; i++) {
		int x = s[i] - '0';
		int xx = s[i + 1] - '0';
		int sum = x * 10 + xx;
		
		if(xx % 4 == 0) ans++;
		if(sum % 4 == 0) ans += i + 1;
	}
	cout << ans << '\n';

	return 0;
}
