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
 
		int a[N];
		for(int i = 0; i < N; i++) cin>>a[i];
 
		int L = 0;
		for(int i = 1; i < N - 1; i++) {
			if(a[0] < a[i] || a[i] > a[i + 1]) {
				L = i;
				break;
			}
		}
 
		int R = 0;
		for(int i = N - 2; i >= 1; i--) {
			if(a[N - 1] < a[i] || a[i] > a[i - 1]) {
				R = i;
				break;
			}
		}
 
		cout<<(N - R + L >= N ? "YES\n" : "NO\n");
	}
	
	return 0;
}
