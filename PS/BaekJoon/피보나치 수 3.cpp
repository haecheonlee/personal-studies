#include <iostream>

using namespace std;

const int MOD=1500000; //15*10^k-1

long long d[MOD];

int main() {
	d[0]=0;
	d[1]=1;
	for(int i=2; i<MOD; i++) d[i]=(d[i-1]+d[i-2])%1000000;

	long long n;
	cin>>n;

	cout<<d[n%MOD];

	return 0;
}
