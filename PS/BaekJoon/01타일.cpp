#include <iostream>

using namespace std;

#define mod 15746

int DP[1000001]{0};
int main() {
	int N;
	cin>>N;
	
	DP[0]=1; DP[1]=1;
	for(int i=2; i<=N; i++) {
		DP[i]=(DP[i-1]%mod)+(DP[i-2]%mod);	
	}
	
	cout<<DP[N]%mod;
	return 0;
}

/*
INPUT:
4

OUTPUT:
5
*/
