#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N,K;
	cin>>N>>K;

	vector<int> v(N, 0);
	for(int i=0; i<N; i++) cin>>v[i];

	int m=-10000001, total=0;
	for(int i=0; i<=N-K; i++) {
		if(i<1) {
			for(int j=i; j<(K+i); j++) {
				total+=v[j];
			}
		} else {
			total+=v[i+K-1]-v[i-1];	
		}
		
		m=max(total, m);
	}
	
	cout<<m;
	
	return 0;
}

/*
boj.kr/2559

INPUT:
10 2
3 -2 -4 -9 0 3 7 13 8 -3

OUTPUT:
21
*/
