#include <iostream>

using namespace std;

#define size 1000

int d[size+1];

int main() {
	int t,k;
	cin>>t;
	
	for(int i=1; i<=size; i++) {
		d[i]=i+d[i-1];	
	}
	
	while(t--) {
		cin>>k;

		bool check=false;
		for(int i=1; d[i]<k; i++) {
			for(int j=1; d[j]<k; j++) {
				for(int n=1; d[n]<k; n++) {
					if((d[i]+d[j]+d[n])==k) {
						check=true;
						break;
					}
				}
				if(check) break;
			}
			if(check) break;
		}

		if(check) cout<<1<<'\n';
		else cout<<0<<'\n';
	}
	
	return 0;
}

/*
INPUT:
3
10
20
1000

OUTPUT:
1
0
1
*/
