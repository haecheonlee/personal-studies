#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin>>N;

	vector<int> A(N);
	for(int i=0; i<N; i++) cin>>A[i];
	sort(A.rbegin(), A.rend());

	int a=0, b=0;
	for(int i=0; i<N; i++) {
		if(i%2==0) a+=A[i];
		else b+=A[i];
	}
	cout<<a<<" "<<b;

	return 0;
}
