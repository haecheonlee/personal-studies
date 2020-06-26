#include <iostream>

using namespace std;
const int MOD=1e9+7;

int d[1000001];

int main() {
	int n;
	cin>>n;
	
	d[0]=0;
	d[1]=1;
	for(int i=2; i<=n; i++) {
		d[i]=d[i-1]+d[i-2];
		d[i]%=MOD;
	}
	
	cout<<d[n];

	return 0;
}
