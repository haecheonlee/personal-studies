#include <iostream>

using namespace std;

int main() {
	int t,n;
	cin>>t;
	
	while(t--) {
		cin>>n;
		
		int a[n],sum[n],mx;
		for(int i=0; i<n; i++) {
			cin>>a[i];
			
			if(i==0) {
				mx=a[i];
				sum[i]=a[i];
			} else {
				sum[i]=max(sum[i-1]+a[i], a[i]);
			}

			mx=max(sum[i],mx);
		}
		
		cout<<mx<<'\n';
	}
	
	return 0;
}

/*
INPUT:
2
5
1 2 3 4 5
5
2 1 -2 3 -5

OUTPUT:
15
4
*/
