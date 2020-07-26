#include <iostream>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	int A[N+1];
	for(int i=1; i<=N; i++) cin>>A[i];

	int day=1e9, tmp=1e9;
	for(int i=1; i<=N-2; i++) {
		int current=max(A[i],A[i+2]);
		if(tmp>current) {
			day=i;
			tmp=current;
		}
	}
	cout<<day<<" "<<tmp;

	return 0;
}
