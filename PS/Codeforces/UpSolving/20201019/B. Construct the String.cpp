#include <iostream>
 
using namespace std;
 
int main() {
	int T;
	cin>>T;
 
	while(T--) {
		int N,A,B;
		cin>>N>>A>>B;
		
		string ans="";
		
		for(int i=0; i<N; i+=B) {
			for(int j=0; j<B && i+j<N; j++) ans+='a'+j;
		}
		
		cout<<ans<<'\n';
	}
 
	return 0;
}
