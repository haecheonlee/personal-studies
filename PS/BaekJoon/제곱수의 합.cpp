#include <iostream>

using namespace std;

int DP[100001];
int main() {
	int N;
	cin>>N;
	
	for(int i=1; i<=N; i++) {
		DP[i]=i;
		for(int j=1; j*j<=i; j++) {
			if(DP[i]>DP[i-j*j]+1) {
				DP[i]=DP[i-j*j]+1;
			}
		}
	}
	
	cout<<DP[N];
	return 0;
}

/*
boj.kr/1699

INPUT:
7

OUTPUT:
4
*/
