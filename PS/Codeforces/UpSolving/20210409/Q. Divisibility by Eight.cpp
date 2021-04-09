#include <iostream>

using namespace std;

int cnt[10];
int need[10];

bool chk() {
	for(int i = 0; i < 10; i++) 
		if(need[i] > cnt[i]) 
			return false;
			
	return true;
}

int main() {
	string s; cin >> s;
	for(auto& x : s) cnt[x - '0']++;

	if(cnt[0]) {
		cout << "YES" << '\n';
		cout << 0 << '\n';
		goto END;
	} else if(cnt[8]) {
		cout << "YES" << '\n';
		cout << 8 << '\n';
		goto END;
	} else {
		for(int i = 0; i < s.size(); i++) {
			for(int j = i + 1; j < s.size(); j++) {
				int sum = 10 * (s[i] - '0') + (s[j] - '0');
				if(sum % 8 == 0) {
					cout << "YES" << '\n';
					cout << sum << '\n';
					goto END;
				}
				
				for(int k = j + 1; k < s.size(); k++) {
					int sum = 10 * (s[j] - '0') + (s[k] - '0');
					
					if((s[i] - '0') & 1) {
						if(sum % 4 == 0 && sum % 8 != 0) {
							cout << "YES" << '\n';
							cout << s[i] << sum << '\n';
							goto END;
						}
					} else {
						if(sum % 8 == 0) {
							cout << "YES" << '\n';
							cout << s[i] << sum << '\n';
							goto END;
						}
					}
					
				}
			}
		}
	}
	
	cout << "NO" << '\n';

	END:
	return 0;
}
