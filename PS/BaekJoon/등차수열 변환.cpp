#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	vector<int> a(n);
	for(int i=0; i<n; i++) cin>>a[i];
	
	if(n==1) {
		cout<<0;
		return 0;
	}
	
	int ans=-1;
	for(int d1=-1; d1<=1; d1++) {
		for(int d2=-1; d2<=1; d2++) {
			int change=0;
			
			if(d1!=0) change+=1;
			if(d2!=0) change+=1;
			
			int a0=a[0]+d1;
			int diff=(a[1]+d2)-a0;
			bool ok=true;
			
			int an=a0+diff;	// 'n' th of a
			for(int i=2; i<n; i++) {
				an+=diff;
				if(a[i]==an) continue;
				if(a[i]-1==an) change+=1;
				else if(a[i]+1==an) change+=1;
				else {
					ok=false;
					break;
				}
			}
			
			if(ok) {
				if(ans==-1 || ans>change) ans=change;
			}
		}
	}
	cout<<ans;

	return 0;
}
