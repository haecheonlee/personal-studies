#include <iostream>

const int MAX=1000000007;
using namespace std;

int fib[51];
int cnt[51];

int main() {
	int n;
	cin>>n;
	
	fib[0]=0;cnt[0]=1;
	fib[1]=1;cnt[1]=1;
	
	for(int i=2; i<=n; i++) {
		fib[i]=fib[i-1]+fib[i-2];
		cnt[i]=cnt[i-1]+cnt[i-2]+1;
		cnt[i]%=MAX;
	}
	
	cout<<cnt[n];

	return 0;
}

/*
boj.kr/17175

INPUT:
3

OUTPUT:
5
*/
