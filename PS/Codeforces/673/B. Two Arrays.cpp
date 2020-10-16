/* Editorial By (hugopm) */
 
#include <iostream>
 
using namespace std;
 
int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N,K;
		cin>>N>>K;
		
		int M=0;
		for(int i=0; i<N; i++) {
			int x;
			cin>>x;
			
			int R;
			if(K%2==0 && x==K/2) R=(M++)%2;
			else if(2*x<K) R=0;
			else R=1;
			
			cout<<R<<' ';
		}
		
		cout<<'\n';
	}
}
