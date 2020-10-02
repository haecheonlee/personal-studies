#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N,M,K,SUM=0;
	cin>>N>>M>>K;
	
	vector<int> a(N);
	for(int i=0; i<N; i++) {
		cin>>a[i];
		SUM+=a[i];
	}
	sort(a.rbegin(), a.rend());
	
	int X=M*K;
	if(X>SUM) {
		cout<<"STRESS";
	}
	else {
		int i, W=0;
		for(i=0; i<N; i++) {
			W+=a[i];
			if(W>=X) break;
		}
		cout<<i+1;
	}
	
	return 0;
}
