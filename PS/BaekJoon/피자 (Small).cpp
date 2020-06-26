#include <iostream>

using namespace std;

int go(int n) {
	if(n==1) return 0;
	
	int ans=((n/2)*(n-n/2));
	if(n/2>1) ans+=go(n/2);
	if(n-n/2>1) ans+=go(n-n/2);
	
	return ans;
}

int main() {
	int n;
	cin>>n;
	
	cout<<go(n);
	
	return 0;
}
