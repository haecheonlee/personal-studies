#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;

	while(T--) {
		int x,y;
		cin>>x>>y;

		if(x%2==0) {
			if(x==2 && 3<y) cout<<"NO\n";
			else cout<<"YES\n";
		} else {
			if(x<=3 && x<y) cout<<"NO\n";
			else cout<<"YES\n";
		}
	}

	return 0;
}
