#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N,K;
		cin>>N>>K;
		
		int sum=0;
		for(int i=0; i<N; i++) {
			int x;
			cin>>x;
			
			sum+=x;
		}
		
		cout<<(sum==K ? "YES\n" : "NO\n");
	}
	
	return 0;
}
