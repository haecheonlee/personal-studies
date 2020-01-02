#include <iostream>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	int DP[N+1][2] {0};
	int stairs[N+1] {0};
	
	for(int i=1; i<=N; i++) {
		cin>>stairs[i];
	}
	
	DP[1][0]=stairs[1];
	DP[1][1]=stairs[1];

	for(int i=2; i<=N; i++) {
		DP[i][0]=max(DP[i-2][1]+stairs[i], DP[i-2][0]+stairs[i]);
		DP[i][1]=DP[i-1][0]+stairs[i];
	}
	
	cout<<max(DP[N][0], DP[N][1]);
	
	return 0;
}

/*
boj.kr/2579

INPUT:
6
10
20
15
25
10
20

OUTPUT:
75
*/
