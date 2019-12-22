#include <iostream>

using namespace std;

int main() {
	int N, M, K;
	cin>>N>>M>>K;
	
	int list[N][M] {0};
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin>>list[i][j];
		}
	}
	
	int result[N] {0};
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++) {
			result[j] += list[j][i];
			if(result[j] >= K) {
				cout<<(j+1)<<" "<<(i+1);
				return 0;
			}
		}
	}
	
	return 0;
}

/*
boj.kr/18229

INPUT:
4 5 20
3 5 2 1 4
1 8 2 5 8
1 5 2 3 3
1 1 8 9 9

OUTPUT:
2 5
*/
