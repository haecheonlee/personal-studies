#include <iostream>

using namespace std;

int main() {
	int n,s;
	cin>>n>>s;
	
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	
	int i=0,j=0,length=100001,sum=0;
	while(i<n || j<n) {
		if(sum<=s && i<n) {
			sum+=a[i++];
		} else {
			sum-=a[j++];
		}
		
		if(sum>=s) length=min(length,i-j);
	}
	
	if(length==100001) cout<<0;
	else cout<<length;

	return 0;
}

/*
INPUT:
10 15
5 1 3 5 10 7 4 9 2 8

OUTPUT:
2
*/
