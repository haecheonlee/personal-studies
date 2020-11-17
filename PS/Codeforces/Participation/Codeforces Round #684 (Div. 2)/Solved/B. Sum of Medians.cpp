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
		int n, k;
		cin >> n >> k;
 
		int L = n * k;
		int a[L + 1];
		for(int i = 1; i <= L; i++) cin >> a[i];
 
		if(n <= 2) {
			ll ans = 0;
			for(int i = 1; i <= L; i += n) ans += a[i];
			cout << ans << '\n';
		} else {
			ll ans = 0;
			int m = n / 2;
			for(int i = L - m, K = 0; i >= 1 && K < k; i -= (m + 1), K++) ans += a[i];
			cout << ans << '\n';
		}
	}
 
	return 0;
}
