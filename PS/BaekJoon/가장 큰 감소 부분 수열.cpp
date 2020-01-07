#include <iostream>

using namespace std;

int DP[1001] {0};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin>>N;
	
	int A[N+1], m {0};
	for(int i=1; i<=N; i++) {
		cin>>A[i];
		
		DP[i]=A[i];
		for(int j=1; j<i; j++) {
			if(A[i]<A[j] && DP[i]<DP[j]+A[i]) {
				DP[i]=DP[j]+A[i];
			}
		}

		m=max(m, DP[i]);
	}

	cout<<m;
	return 0;
}

/*
boj.kr/17216

INPUT:
10
1 100 2 50 60 8 7 3 6 5

OUTPUT:
186
*/
