#include <iostream>

using namespace std;

int N,K;
int a[100001];

bool check(int M) {
	
	int X=0;
	for(int i=0; i<K; i++) {
		if(a[i]-M<=X) X=a[i]+M;
		else return false;
	}
	
	if(X<N) return false;
	return true;
}

int main() {
	cin>>N>>K;
	
	for(int i=0; i<K; i++) cin>>a[i];

	int ans=0;
	int L=1, R=N;
	
	while(L<=R) {
		int M=(L+R)/2;
		
		if(check(M)) {
			R=M-1;
			ans=M;
		} else {
			L=M+1;
		}
	}
	cout<<ans;
	
	return 0;
}
