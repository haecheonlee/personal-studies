#include <iostream>

using namespace std;

long long a[117];

int main() {
	int n;
	cin>>n;
	
	a[1]=a[2]=a[3]=1;
	for(int i=4; i<=n; i++) a[i]=a[i-1]+a[i-3];
	cout<<a[n];

	return 0;
}
