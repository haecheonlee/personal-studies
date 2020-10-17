#include <iostream>
 
using namespace std;
 
int main() {
	int T;
	cin>>T;
	
	while(T--) {
		string s;
		cin>>s;
		
		int ans=s.size();
		
		int L=s.size();
		int B[L+1] {0};
		for(int i=L-1; i>=0; i--) {
			B[i]=B[i+1];
			if(s[i]=='B') B[i]++;
		}
		
		int used=0;
		for(int i=0; i<L; i++) {
			if(s[i]=='A') {
				if(B[i]-used>0) {
					ans-=2;
					B[0]--, used++;
				}
			} else {
				if(used>0) used--;
			}
		}
		
		int extra=((B[0]%2==0) ? B[0] : B[0]-1); 
		cout<<ans-extra<<'\n';
	}
	
	return 0;
}
