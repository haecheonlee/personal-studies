#include <iostream>

using namespace std;

int DP[1001] {0};
int main() {
	int N;
	cin>>N;
	
	int P[N+1];
	for(int i=1; i<=N; i++) {
		cin>>P[i];
	}
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=i; j++) {
			DP[i] = max(DP[i], DP[i-j]+P[j]);
		}
	}
	
	cout<<DP[N];
	
	return 0;
}

/*
boj.kr/11052

INPUT:
10
1 1 2 3 5 8 13 21 34 55

OUTPUT:
55
*/
