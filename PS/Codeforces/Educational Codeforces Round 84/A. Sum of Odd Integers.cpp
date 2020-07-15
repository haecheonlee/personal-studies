#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		long long N,K;
		cin>>N>>K;
		
		if(K*K<=N && N%2==K%2) cout<<"YES\n";
		else cout<<"NO\n";
	}

	return 0;
}
