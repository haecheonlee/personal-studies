#include <iostream>

using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	
	long long a[n];
	long long left=0;
	long long right=0;
	
	for(int i=0; i<n; i++) { 
		cin>>a[i];
		right+=a[i];
	}
	
	while(left+1<right) {
		long long mid=(left+right)/2;
		
		int count=0;
		for(int i=0; i<n; i++) count+=a[i]/mid;
		
		if(count>=m) left=mid;
		else right=mid;
	}

	long long ans=0;
	for(int i=0; i<n; i++) {
		if((a[i]/left)<m) {
			m-=a[i]/left;
			ans+=a[i]%left;
		} else {
			ans+=a[i]-(left*m);
		}
	}
    cout<<ans;

	return 0;
}

/*
INPUT:
3 5
440
350
230

OUTPUT:
145
*/
