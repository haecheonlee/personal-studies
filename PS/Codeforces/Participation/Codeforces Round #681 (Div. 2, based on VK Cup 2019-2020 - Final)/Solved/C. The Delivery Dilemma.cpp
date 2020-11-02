#include <iostream>
#include <algorithm>

#define sz(x) (int)(x.size())

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin>>T;

	while(T--) {
		int N;
		cin>>N;
		

		pll a[N];
		ll total = 0;
		for(int i = 0; i < N; i++) cin>>a[i].first;
		for(int i = 0; i < N; i++) { cin>>a[i].second; total += a[i].second; }
		sort(a, a + N);
		
		ll ans = total;
		for(int i = 0; i < N; i++) {
			total -= a[i].second;
			
			ll t = max(a[i].first, total);
			if(ans > t) ans = t;
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
