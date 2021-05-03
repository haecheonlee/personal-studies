#include <iostream>
#include <set>

using namespace std;

void solve() {
	int N; cin >> N;
	string s[N];
	for(int i = 0; i < N; i++) cin >> s[i];

	multiset<string> list;
	for(int i = 0; i < N; i++) list.insert(s[i]);

	int ans = 0;
	for(int i = 0; i < N; i++) {
		auto it = list.find(s[i]);
		list.erase(it);
		it = list.find(s[i]);
		if(it != list.end()) {
			string original = s[i];
			for(int k = 0; k < 4; k++) {
				char x = s[i][k];
				for(int j = 0; j <= 9; j++) {
					s[i][k] = j + '0';
					if(list.find(s[i]) == list.end()) {
						goto END;
					}
				}
				s[i][k] = x;
			}
			
			END:
			list.insert(s[i]);
			ans++;
		} else {
			list.insert(s[i]);
		}
	}
	
	cout << ans << '\n';
	for(int i = 0; i < N; i++) cout << s[i] << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
