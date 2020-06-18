#include <iostream>

using namespace std;

long long d[101];

int main() {
	int n;
	cin>>n;
	
	d[1]=1;
	d[2]=2;
	d[3]=3;
	
	for(int i=1; i<=n; i++) {
		d[i]=d[i-1]+1;
		for(int j=1; j<=i-3; j++) {
			long long cur=d[i-j-2]*(j+1);
			if(cur>d[i]) d[i]=cur;
		}
	}
	cout<<d[n];

	return 0;
}
