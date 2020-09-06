#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		int a[N];
		for(int i=0; i<N; i++) cin>>a[i];
		sort(a, a+N);
		
		if(N==1) {
			cout<<"YES\n";
		}
		else {
			bool isPossible=true;
			for(int i=0; i<N-1; i++) {
				if(abs(a[i]-a[i+1])>1) isPossible=false;
			}
			cout<<((isPossible) ? "YES\n" : "NO\n");
		}
	}
 
	return 0;
}
