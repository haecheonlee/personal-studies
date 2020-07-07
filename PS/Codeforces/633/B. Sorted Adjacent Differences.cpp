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
		sort(a,a+N);
		
		int M=N/2;
		int L=1, R=0;
		while(M-L>=0 || M+R<N) {
			if(M+R<N) cout<<a[M+R]<<" ";
			if(M-L>=0) cout<<a[M-L]<<" ";

			R++;
			L++;
		}
		cout<<'\n';
	}

	return 0;
}
