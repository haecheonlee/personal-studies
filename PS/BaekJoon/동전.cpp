#include <iostream>

using namespace std;

int main() {
	int t,n,m;
	cin>>t;
	
	while(t--) {
		cin>>n;
		
		int a[n];
		for(int i=0; i<n; i++) cin>>a[i];
		cin>>m;
		
		int d[m+1] {0};
		d[0]=1;
		for(int i=0; i<n; i++) {
			for(int j=0; j<=m; j++) {
				if(j-a[i]>=0) d[j]+=d[j-a[i]];
			}
		}
		cout<<d[m]<<'\n';
	}
	
	return 0;
}

/*
INPUT:
3
2
1 2
1000
3
1 5 10
100
2
5 7
22

OUTPUT:
501
121
1
*/
