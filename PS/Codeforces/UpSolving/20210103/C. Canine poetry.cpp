/* reference: editorial */

#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 1;

bool used[MAX_N];

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		string s;
		cin >> s;
		
		int L = s.size();
		for(int i = 0; i < L; i++) used[i] = false;
		
		int ans = 0;
		for(int i = 1; i < L; i++) {
			bool need = false;
			if(s[i] == s[i - 1] && !used[i - 1]) need = true;
			if(i > 1 && s[i] == s[i - 2] && !used[i - 2]) need = true;
			
			used[i] = need;
			ans += used[i];
		}
		cout << ans << '\n';
	}
	
	return 0;
}
