/* editorial */

#include <iostream>

using namespace std;

int main() {
	string s; cin >> s;
	
	int ans = 1;
	for(int i = s.size() - 1; i >= 0; i--) {
		int total = 1;
		for(auto& c : s) total *= max(c - '0', 1);
		ans = max(ans, total);
		
		s[i] = '9';
		if(i >= 1 && s[i - 1] != '0') s[i - 1]--;
	}
	cout << ans << '\n';

	return 0;
}
