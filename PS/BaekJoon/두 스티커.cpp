#include <iostream>

using namespace std;

int main() {
	int h,w,n;
	cin>>h>>w>>n;
	
	int r[n],c[n];
	for(int i=0; i<n; i++) cin>>r[i]>>c[i];
	
	int ans=0;
	for(int i=0; i<n; i++) {
		int r1=r[i], c1=c[i];
		for(int j=i+1; j<n; j++) {
			int r2=r[j], c2=c[j];
			
			for(int a=0; a<2; a++) {
				for(int b=0; b<2; b++) {
					if(r1+r2<=h && max(c1,c2)<=w) {
						int temp=r1*c1+r2*c2;
						ans=max(temp,ans);
					}
					
					if(max(r1,r2)<=h && c1+c2<=w) {
						int temp=r1*c1+r2*c2;
						ans=max(temp,ans);
					}
					
					swap(r2,c2);
				}
				swap(r1,c1);
			}
		}
	}

	cout<<ans;

	return 0;
}

/*
INPUT:
10 9
4
2 3
1 1
5 10
9 11

OUTPUT:
56
*/
