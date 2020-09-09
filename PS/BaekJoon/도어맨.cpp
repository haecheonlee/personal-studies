#include <iostream>

using namespace std;

int main() {
	int X;
	string s;
	
	cin>>X>>s;
	
	int M=0, W=0;
	
	while(1) {
		// base case
		if(s.size()==0) break;

		if(M==W) {
			// doesn't matter which one to enter
			if(s[0]=='M') M++;
			else W++;
			
			s.erase(0,1);
		} else {
			if(s.size()==1) {
				// check last person
				int pm=M + (s[0]=='M');
				int pw=W + (s[0]=='W');
				
				if(abs(pm-pw)<=X) {
					M=pm;
					W=pw;
					
					s.erase(0,1);
				} else {
					break;
				}
			} else {
				if(M>W) {
					// let W enter first
					if(s[0]=='M' && s[1]=='M') {
						int diff=abs((M+1)-W);
						if(diff>X) break;	// not possible to let M enter more
						
						M++;
						s.erase(1,1);
					} else {
						W++;
						if(s[1]=='W') s.erase(1,1);	// try to let second person enter first
						else s.erase(0,1);
					}
				} else {
					// let M enter first
					if(s[0]=='W' && s[1]=='W') {
						int diff=abs((W+1)-M);
						if(diff>X) break;	// not possible to let W enter more
						
						W++;
						s.erase(1,1);
					} else {
						M++;
						if(s[1]=='M') s.erase(1,1);	// try to let second person enter first
						else s.erase(0,1);
					}
				}
			}
		}
	}
	cout<<M+W;
	
	return 0;
}
