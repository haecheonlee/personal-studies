#include <iostream>

using namespace std;

long long DP[101];
int main() {
	DP[1]=1;DP[2]=1;DP[3]=1;
	for(int i=4; i<=100; i++) {
		DP[i]=DP[i-2]+DP[i-3];
	}
	
	int T;
	cin>>T;
	
	int N;
	for(int i=0; i<T; i++) {
		cin>>N;
		cout<<DP[N]<<'\n';
	}

	return 0;
}

/*
boj.kr/9461

INPUT:
2
6
12

OUTPUT:
3
16
*/
