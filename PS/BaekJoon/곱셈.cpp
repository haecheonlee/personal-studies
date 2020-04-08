#include <iostream>

using namespace std;

long long calc(long long a, long long b, long long c) {
	if(b==0) return 1;

	long long ans=1LL;
	if(b%2==0) {
		long long temp=calc(a,b/2,c);
		ans=temp*temp%c;
	} else {
		long long temp=calc(a,b-1,c);
		ans=a*temp%c;
	}
	return ans;
}

int main() {
	long long a,b,c;
	cin>>a>>b>>c;
	
	cout<<calc(a,b,c);
	
	return 0;
}

/*
INPUT:
10 11 12

OUTPUT:
4
*/
