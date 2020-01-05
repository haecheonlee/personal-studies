#include <iostream>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	int A[N+1] {0};
	int DP[N+1] {0};
	
	int m=1;
	for(int i=1; i<=N; i++) {
		cin>>A[i];
		
		DP[i]=1;
		for(int j=1; j<i; j++) {
			if(A[i]>A[j] && DP[i]<=DP[j]) {
				DP[i]=DP[j]+1;
				m=max(m, DP[i]);
			}
		}
	}
	
	cout<<m;

	return 0;
}

/*
boj.kr/11053

INPUT:
6
10 20 10 30 20 50

OUTPUT:
4
*/
