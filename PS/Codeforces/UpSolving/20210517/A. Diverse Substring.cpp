#include <iostream>
#include <cstring>

using namespace std;

int cnt[26];

int main() {
	int N; cin >> N;
	string s; cin >> s;
	
	for(int i = 0; i < N; i++) {
		memset(cnt, 0, sizeof(cnt));
		for(int j = i; j < N; j++) {
			int L = j - i + 1, x = s[j] - 'a';
			cnt[x]++;
			
			bool flag = 1;
			for(int k = 0; k < 26; k++) if(cnt[k] > L / 2) flag = 0;
			if(flag) {
				cout << "YES" << '\n';
				cout << s.substr(i, L) << '\n';
				return 0;
			}
		}
	}

	cout << "NO" << '\n';
	
	return 0;
}
