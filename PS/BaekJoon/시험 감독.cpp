#include <iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	long long a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	
	long long b,c;
	cin>>b>>c;
	
	long long cnt=0;
	for(int i=0; i<n; i++) {
		a[i]-=b;
		cnt++;
		
		if(a[i]>0) {
			cnt+=a[i]/c;
			a[i]%=c;
			if(a[i]>0) cnt++;
		}
	}
	cout<<cnt;
	
	return 0;
}

/*
INPUT:
5
1000000 1000000 1000000 1000000 1000000
5 7

OUTPUT:
714290
*/
