#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		string s;
		cin>>s;
		
		int len=s.size();
		int zero=0, one=0;
		for(int i=0; i<len; i++) {
			if(s[i]=='0') zero++;
			else one++;
		}
		
		int cnt=min(zero,one);
		
		if(cnt%2) cout<<"DA\n";
		else cout<<"NET\n";
	}

	return 0;
}
