#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int a[3];
		for(int i=0; i<3; i++) cin>>a[i];
		sort(a, a+3);
				
		int ans=0;
		for(int i=0; i<3; i++) if(a[i]>0) { a[i]--, ans++; }	// one
		
		for(int i=0; i<3; i++) {
			for(int j=2; j>i; j--)	{
				if(i==j) continue;
				if(a[i] && a[j]) { a[i]--, a[j]--, ans++; }
			}
		}
		if(a[0] && a[1] && a[2]) ans++;
		
		cout<<ans<<'\n';
	}	

	return 0;
}
