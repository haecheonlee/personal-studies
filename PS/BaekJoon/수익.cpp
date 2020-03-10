#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	
	while(1) {
		cin>>n;
		if(n==0) break;
		
		int a[n],sum[n],largest=-10001;
		for(int i=0; i<n; i++) {
			cin>>a[i];
			
			if(i==0) {
				sum[i]=a[i];
			} else {
				sum[i]=max(a[i],sum[i-1]+a[i]);
			}
			
			largest=max(largest,sum[i]);
		}
		cout<<largest<<'\n';
	}
	
	return 0;
}

/*
boj.kr/4097

INPUT:
6
-3
4
9
-2
-5
8
2
-1000
-19
0

OUTPUT:
14
-19
*/
