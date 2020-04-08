#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	
	long long a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	sort(a,a+n);
	
	long long ans=-1;
	int s=0,e=0;
	while(e<n && s<n) {
		long long diff=abs(a[s]-a[e]);
		if(diff>=m) {
			s++;
			if(ans==-1 || ans>diff) ans=diff;
		} else {
			e++;
		}
	}
	cout<<ans;

	return 0;
}

/*
INPUT:
3 3
1
5
3

OUTPUT:
4
*/
