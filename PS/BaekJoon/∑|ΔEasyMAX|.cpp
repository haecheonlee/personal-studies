#include <iostream>

using namespace std;

int main() {
	int n,q,q1,q2;
	cin>>n>>q;
	
	int a[n], sum[n] {0};
	for(int i=0; i<n; i++) {
		cin>>a[i];
		if(i>0) {
			sum[i]=abs(a[i-1]-a[i])+sum[i-1];
		}
	}
	
	while(q--) {
		cin>>q1>>q2;
		cout<<sum[q2-1]-sum[q1-1]<<'\n';
	}
	
	return 0;
}

/*
INPUT:
4 3
100 101 382 573
1 1
1 3
2 4

OUTPUT:
0
282
472
*/
