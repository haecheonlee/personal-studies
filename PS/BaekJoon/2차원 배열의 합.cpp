#include <iostream>

using namespace std;

int main() {
	int N,M;
	cin>>N>>M;
	
	int A[N+1][M+1];
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			cin>>A[i][j];
		}
	}
	
	int K,i,j,x,y;
	cin>>K;
	
	for(int a=0; a<K; a++) {
		cin>>i>>j>>x>>y;
		
		int total=0;
		for(int m=j; m<=y; m++) {
			for(int n=i; n<=x; n++) total+=A[n][m];
		}
		cout<<total<<'\n';
	}
	
	return 0;
}

/*
boj.kr/2167

INPUT:
2 3
1 2 4
8 16 32
3
1 1 2 3
1 2 1 2
1 3 2 3

OUTPUT:
63
2
36
*/
