// reference: editorial

#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;

	while(T--) {
		int N,X;
		cin>>N>>X;
		
		int sum=0, l=-1, r;
		for(int i=0; i<N; i++) {
			int a;
			cin>>a;
			
			if(a%X) {
				if(l==-1) l=i;
				r=i;
			}
			sum+=a;
		}
		
		if(sum%X) cout<<N<<'\n';
		else if(l==-1) cout<<-1<<'\n';
		else cout<<N-min(l+1,N-r)<<'\n';
	}

	return 0;
}
