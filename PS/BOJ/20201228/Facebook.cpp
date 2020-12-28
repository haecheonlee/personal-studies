/* reference: justiceHui  */

#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 2e3 + 1;
const int MAX_BIT = MAX_N / 60 + 1;

int N, Q, X;
ll d[MAX_N][MAX_BIT];

int main() {
	scanf("%d", &N);
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			scanf("%1d", &X);

			if(X) d[i][j / 60] |= (1LL << (j % 60));
		}
	}

	scanf("%d", &Q);

	while(Q--) {
		int A, B, ans = 0;
		scanf("%d %d", &A, &B);

		for(int k = 0; k < MAX_BIT; k++) 
			ans += __builtin_popcountll(d[A][k] & d[B][k]);
			
		printf("%d\n", ans);
	}

	return 0;
}
