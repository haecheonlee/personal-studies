#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin>>T;

	while(T--) {
		int N;
		cin>>N;

		int a[N];
		int mx=0;
		for(int i=0; i<N; i++) { cin>>a[i]; mx=max(a[i], mx); }		
		
		int ans=-1;
		for(int i=0; i<N; i++) {
			if(a[i]==mx) {
				int prev=i-1, next=i+1;
				bool is_prev_possible=(prev>=0), is_next_possible=(next<N);
				if(prev>=0) if(a[prev]>=a[i]) is_prev_possible=false;
				if(next<N) if(a[next]>=a[i]) is_next_possible=false;
				if(is_prev_possible || is_next_possible) ans=i; 
			}
			
			if(ans!=-1) break;
		}

		if(ans==-1) cout<<-1<<'\n';
		else cout<<ans+1<<'\n';
	}

	return 0;
}
