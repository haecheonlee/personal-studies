#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N,M;
		cin>>N>>M;
		
		bool check[1001] {false};
		for(int i=0; i<N; i++) {
			int x;
			cin>>x;
			
			check[x]=true;
		}
		
		int ans=-1;
		for(int i=0; i<M; i++) {
			int x;
			cin>>x;
			
			if(check[x]) ans=x;
		}
		
		if(ans==-1) {
			cout<<"NO\n";
		}
		else {
			cout<<"YES\n";
			cout<<1<<" "<<ans<<'\n';
		}
	}
	
	return 0;
}
