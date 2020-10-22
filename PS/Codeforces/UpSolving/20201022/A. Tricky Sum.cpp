#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		long long N;
		cin>>N;
		
		long long total = (N * (N + 1)) / 2;
		for(int i=0; (1<<i)<=N; i++) total = total - 1LL * 2 * (1<<i); 
		cout<<total<<'\n';
	}
	
	return 0;
}
