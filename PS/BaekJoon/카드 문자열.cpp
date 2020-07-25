#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;

	while(T--) {
		int N;
		cin>>N;
		
		char A[N];
		for(int i=0; i<N; i++) cin>>A[i];
		
		string ans="";
		for(int i=0; i<N; i++) {
			if(ans=="") {
				ans+=A[i];
			}
			else {
				char front=ans[0];
				if(front>=A[i]) ans=A[i]+ans;
				else ans+=A[i]; 
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}
