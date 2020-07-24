/* reference: https://contest.usaco.org/TESTDATA/FEB07.buyfree.htm */

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N,M;
	cin>>N>>M;
	
	int A[N], B[M];
	for(int i=0; i<N; i++) cin>>A[i];
	for(int i=0; i<M; i++) cin>>B[i];
	
	sort(A,A+N);
	sort(B,B+M);
	
	int ans=N;
	int idx=0;
	for(int i=0; i<M; i++) {
		while(idx<N && B[i]>=A[idx]) idx++;
		if(idx<N) {
			ans++;
			idx++;
		}
	}
	cout<<ans;
	
	return 0;
}
