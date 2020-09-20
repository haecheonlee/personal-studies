#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		string s;
		cin>>N>>s;
		
		if(N==1) {
			int x=s[0]-'0';
			cout<<((x%2) ? 1 : 2)<<'\n';
		} else {
			int o1=0, e1=0, o2=0, e2=0;
			for(int i=0; i<s.size(); i++) {
				int x=s[i]-'0';
				
				if(i%2==0) {
					// raze
					if(x%2) o1++;
					else e1++;
				} else {
					// breach
					if(x%2) o2++;
					else e2++;
				}
			}
			
			if(s.size()%2) cout<<((o1) ? 1 : 2)<<'\n';
			else cout<<((e2) ? 2 : 1)<<'\n';
		}
	}

	return 0;
}
