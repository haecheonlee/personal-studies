#include <iostream>
#include <vector>

#define sz(x) (int)(x.size())

using namespace std;

vector<int> a[26];

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		for(int i = 0; i < 26; i++) a[i].clear();
		
		string s;
		int K;
		
		cin >> s >> K;

		for(int i = 0; i < s.size(); i++) {
			int pos = s[i] - 'a';
			a[pos].push_back(i);
		}
		
		int ans1 = -1, ans2 = -1;
		
		for(int i = 0; i < 26; i++) {
			for(int k = 0; k + K - 1 < sz(a[i]); k++) {
				int L = a[i][k + K - 1] - a[i][k] + 1;
				
				if(ans1 == -1 || ans1 > L) ans1 = L;
				ans2 = max(ans2, L);
			}
		}
		
		if(ans1 == -1 || ans2 == -1) cout << -1 << '\n';
		else cout << ans1 << ' ' << ans2 << '\n';
	}

	return 0;
}
