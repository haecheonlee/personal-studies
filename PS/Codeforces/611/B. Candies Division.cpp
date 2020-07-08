#include <iostream>
 
using namespace std;
 
int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N,K;
		cin>>N>>K;
		
		int ans=(N-(N%K))+min(N%K,K/2);
		cout<<ans<<"\n";		
	}
 
	return 0;
}
