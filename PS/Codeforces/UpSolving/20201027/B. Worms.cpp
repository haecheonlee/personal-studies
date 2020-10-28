#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin>>N;

	int a[N];
	vector<int> L(N);
	for(int i=0; i<N; i++) {
		cin>>a[i];
		L[i]=a[i];
		if(i>0) L[i]+=L[i-1];
	}
	
	int M;
	cin>>M;

	while(M--) {
		int x;
		cin>>x;

		int pos = lower_bound(L.begin(), L.end(), x) - L.begin();
		cout<<pos + 1<<'\n';
	}

	return 0;
}
