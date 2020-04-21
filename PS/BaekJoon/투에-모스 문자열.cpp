#include <iostream>

using namespace std;

int main() {
	long long k;
	cin>>k;
	k-=1;
	
	int cnt=0;
	while(k>0) {
		cnt+=k&1;
		k>>=1;
	}
	
	cout<<(cnt&1);
	
	return 0;
}

/*
INPUT:
10

OUTPUT:
0
*/
