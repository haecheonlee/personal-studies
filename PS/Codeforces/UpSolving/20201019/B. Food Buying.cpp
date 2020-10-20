#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int s;
		cin>>s;
		
		int ans=s;
		while(s/10) {
			int rem=s/10;
			s%=10;
			s+=rem;
			ans+=rem;
		}
		cout<<ans<<'\n';
	}

	return 0;
}
