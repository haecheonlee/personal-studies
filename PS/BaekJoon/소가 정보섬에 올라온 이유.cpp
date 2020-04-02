#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,q,idx,x=0;
	cin>>n>>q;
	
	int a[n],sum[n],total=0;
	for(int i=0; i<n; i++) cin>>a[i], sum[i]=1;
	
	for(int i=0; i<4; i++) sum[0]*=a[i];
	
	for(int i=1; i<n; i++) { 
		if(i+3<n) sum[i]=(sum[i-1]/a[i-1])*a[i+3];
		else sum[i]=(sum[i-1]/a[i-1])*(a[x++]);
	}
	
	for(int i=0; i<n; i++) total+=sum[i];

	while(q--) {
		cin>>idx;
		
		for(int i=((4-idx>0) ? 0 : idx-4); i<idx; i++) {
			total-=sum[i];
			sum[i]*=-1;
			total+=sum[i];
		}
			
		for(int i=n-1; i>n-1-(4-idx); i--) {
			total-=sum[i];
			sum[i]*=-1;
			total+=sum[i];
		}
		
		
		cout<<total<<'\n';
	}
	
	return 0;
}

/*
INPUT:
8 5
-2 3 5 -6 10 -8 7 6
3 5 2 7 7

OUTPUT:
-1080
1920
4224
2376
4224
*/
