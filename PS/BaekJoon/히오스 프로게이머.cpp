#include <iostream>
#include <vector>

using namespace std;

long long N,K;
vector<int> a;

bool go(long long M) {
	long long sum=0;
	for(auto x : a) {
		if(x>=M) continue;
		sum+=(M-x);
	}
	
	return sum<=K;
}

int main() {
	cin>>N>>K;
	
	a.resize(N);
	for(int i=0; i<N; i++) cin>>a[i];

	int L=1, R=1e9;
	int ans=0;
	while(L<=R) {
		int M=(L+R)/2;
		
		if(go(M)) {
			L=M+1;
			ans=M;
		} else {
			R=M-1;
		}
	}
	cout<<ans;
	
	return 0;
}
