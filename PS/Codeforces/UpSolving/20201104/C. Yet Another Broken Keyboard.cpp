#include <iostream>

#define sz(x) (int)(x.size())

using namespace std;

typedef long long ll;

bool check[26];

int main() {
	int n, k;
	cin >> n >> k;
	
	string s;
	cin >> s;
	
	for(int i = 0; i < k; i++) {
		char x;
		cin >> x;
		
		check[x - 'a'] = true;
	}
	
	s += ' ';
	
	ll ans = 0;
	ll L = 0, P = 0;
	for(int i = 0; i < sz(s); i++) {
		if(i < n && check[s[i] - 'a']) {
			L++;
			P += L;
		} else {
			ans += P;
			L = 0, P = 0;
		}
	}
	cout << ans;

	return 0;
}
