#include <iostream>
 
using namespace std;
 
int main() {
	int T;
	cin>>T;
	
	while(T--) {
		string s;
		cin>>s;
 
		int K=s[0]-'0';
		int L=s.size();
		
		int ans=0;
		for(int i=1; i<=K; i++) {
			if(i<K) ans+=(1+2+3+4);
			else for(int i=1; i<=L; i++) ans+=i;
		}
		cout<<ans<<'\n';
	}
 
	return 0;
}
