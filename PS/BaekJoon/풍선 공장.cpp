#include <iostream>
#include <vector>

using namespace std;

int N,K;
vector<int> a;

bool go(long long M) {
	long long sum=0;
	for(auto x : a) sum+=M/x;
	
	return sum<K;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N>>K;
	
	a.resize(N);
	for(int i=0; i<N; i++) cin>>a[i];
	
	long long L=1, R=1e13;
	long long ans=0;
	while(L<=R) {
		long long M=(L+R)/2;
		
		if(go(M)) {
			L=M+1;
		} else {
			R=M-1;
			ans=M;
		}
	}
	cout<<ans;
	
	return 0;
}
