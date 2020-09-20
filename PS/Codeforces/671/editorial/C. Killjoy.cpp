#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N,X;
		cin>>N>>X;
		
		int cnt=0, sum=0;
		for(int i=0; i<N; i++) {
			int a;
			cin>>a;
			
			cnt+=(a==X);
			sum+=a;
		}
		
		if(cnt==N) cout<<0<<'\n';
		else if(cnt>0) cout<<1<<'\n';
		else if(sum==N*X) cout<<1<<'\n';
		else cout<<2<<'\n';
	}
	
	return 0;
}
