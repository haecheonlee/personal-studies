#include <iostream>

using namespace std;

#define mod 1000000009

long long DP[1000001]{0};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	DP[0]=1;DP[1]=1;DP[2]=2;
	
	for(int i=3; i<=1000000; i++) {
		DP[i]=(DP[i-1]%mod)+(DP[i-2]%mod)+(DP[i-3]%mod);
	}
	
	int T;
	cin>>T;
	
	int num;
	for(int i=0; i<T; i++) {
		cin>>num;
		cout<<(DP[num]%mod)<<'\n';
	}

	return 0;
}

/*
boj.kr/15988

INPUT:
3
4
7
10

OUTPUT:
7
44
274
*/
