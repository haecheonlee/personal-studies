#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	
 
	int T;
	cin >> T;
 
	while(T--) {
		int n, c, cc, h;
		cin >> n >> c >> cc >> h;
 
		string s;
		cin >> s;
 
		int zero = 0, one = 0;
		for(int i = 0; i < n; i++) {
			if(s[i] == '0') zero++;
			else one++;
		}
 
		int ans = zero * c + one * cc;
		for(int i = 0; i <= zero; i++) {
			int p = (h * i) + (zero - i) * c + cc * (one + i);
			ans = min(ans, p); 
		}
 
		for(int i = 0; i <= one; i++) {
			int p = (h * i) + ((zero + i) * c) + (cc * (one - i));
			ans = min(ans, p); 
		}
		cout << ans << '\n';
	}
 
	return 0;
}
