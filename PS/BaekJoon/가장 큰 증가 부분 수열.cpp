#include <iostream>

using namespace std;

int A[1001], DP[1001], result[1001];

int main() {
	int N;
	cin>>N;
	
	int m=0;
	for(int i=1; i<=N; i++) {
		cin>>A[i];
		
		DP[i]=1;
		result[i]=A[i];
		for(int j=1; j<i; j++) {
			if(A[i]>A[j] && DP[i]<=DP[j] && result[i]<(result[j]+A[i])) {
				DP[i]=DP[j]+1;
				result[i]=result[j]+A[i];
			}
		}

		m=max(m, result[i]);
	}

	cout<<m;
	return 0;
}

/*
boj.kr/11055

INPUT:
10
1 100 2 50 60 3 5 6 7 8

OUTPUT:
113
*/
