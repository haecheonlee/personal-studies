#include <iostream>

using namespace std;

long long d[40];

int main() {
	d[0]=1,d[1]=1;
	
	int n;
	cin>>n;
	
	for(int i=2; i<=n; i++) {
		for(int k=0; k<i; k++) {
			d[i]+=(d[k]*d[i-k-1]);
		}
	}
	
	cout<<d[n];
	
	return 0;
}

/*
INPUT:
25

OUTPUT:
4861946401452
*/
