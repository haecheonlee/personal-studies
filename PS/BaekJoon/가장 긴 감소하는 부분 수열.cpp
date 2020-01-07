#include <iostream>

using namespace std;

int DP[1001] {0};
int main() {
	int N;
	cin>>N;
	
	int A[N+1], m {0};
	for(int i=1; i<=N; i++) {
		cin>>A[i];
		
		DP[i]=1;
		for(int j=1; j<i; j++) {
			if(A[i]<A[j] && DP[i]<DP[j]+1) {
				DP[i]=DP[j]+1;
			}
		}

		m=max(m, DP[i]);
	}

	cout<<m;
	return 0;
}

/*
boj.kr/11722

INPUT:
6
10 30 10 20 20 10

OUTPUT:
3
*/
