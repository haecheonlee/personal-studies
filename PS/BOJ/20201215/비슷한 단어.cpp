#include <iostream>
#include <cstring>

#define sz(x) (int)(x.size())

using namespace std;

int c[26];
bool u[26];

int main() {
	int N;
	cin >> N;
	
	string s[N];
	for(int i = 0; i < N; i++) cin >> s[i];
	
	int ans = 0;
	for(int i = 0; i < N; i++) {
		for(int j = i + 1; j < N; j++) {
			if(sz(s[i]) != sz(s[j])) continue;
			memset(c, -1, sizeof(c)); memset(u, false, sizeof(u));
			
			int L = sz(s[i]);
			
			for(int k = 0; k < L; k++) {
				char c1 = s[i][k], c2 = s[j][k];
				int ii = c1 - 'a', jj = c2 - 'a';
				
				if(c[ii] == -1) {
					if(c1 == c2) {
						if(!u[ii]) c[ii] = ii, u[ii] = 1;
					} else if(c1 != c2) {
						if(!u[jj]) c[ii] = jj, u[jj] = 1;
					}
				}
			}
			
			bool is_good = 1;
			for(int k = 0; k < L; k++) {
				if(c[s[i][k] - 'a'] != s[j][k] - 'a') is_good = 0;
			}
			if(is_good) ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}
