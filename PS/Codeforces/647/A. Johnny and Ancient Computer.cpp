#include <iostream>

using namespace std;
using ll=long long;

ll getR(ll a) {
	while(a%2==0) a/=2;
	
	return a;
}

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		ll a,b;
		cin>>a>>b;

		if(a>b) swap(a,b);
		
		ll r=getR(a);
		if(getR(b)!=r) {
			cout<<-1<<'\n';
		}
		else {
			int ans=0;
			b/=a;
			
			while(b>=8) {
				b/=8;
				ans++;
			}
			
			if(b>1) ++ans;
			cout<<ans<<'\n';
		}
	}

	return 0;
}
