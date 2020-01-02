#include <iostream>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	int DP[N+1];
	int P[N+1];
	for(int i=1; i<=N; i++) {
		cin>>P[i];
		DP[i]=-1;
	}
	
	DP[0]=0;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=i; j++) {
			if(DP[i] == -1 || DP[i]>DP[i-j]+P[j])
				DP[i] = DP[i-j]+P[j];
		}
	}
	
	cout<<DP[N];
	
	return 0;
}

/*
boj.kr/16194

INPUT:
10
5 10 11 12 13 30 35 40 45 47

OUTPUT:
26
*/
