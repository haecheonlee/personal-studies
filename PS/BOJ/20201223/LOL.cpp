#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		string s;
		cin >> s;
		
		int ans = 3;
		for(int i = 0; i < (int)s.size(); i++) {
			if(s[i] == 'l') {
				ans = min(ans, 2);
				if(s[i + 1] == 'o' && s[i + 2] == 'l') ans = 0;
				if(s[i + 1] == 'l' || s[i + 2] == 'l' || s[i + 1] == 'o') ans = min(ans, 1);
			} else if(s[i] == 'o') {
				ans = min(ans, 2);
				if(s[i + 1] == 'l') ans = min(ans, 1);
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
