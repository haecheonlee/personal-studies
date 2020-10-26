#include <iostream>
 
using namespace std;
 
int main() {
	int T;
	cin>>T;
 
	while(T--) {
		long long x,y,a,b;
		cin>>x>>y>>a>>b;
 
		if(x==0 && y==0) {
			cout<<0<<'\n';
		} else {
			if(x>y) swap(x,y);
			long long ans=min((y * a) + (x * a), (y - x) * a + (x * b));
			cout<<ans<<'\n'; 
		}
	}
 
	return 0;
}
