#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	for(int i=1; i<=T; i++) {
		string s;
		cin>>s;
		
		string ans=s.substr(0,1);

		for(int i=1; i<s.size(); i++) {
			if(s[i]>=ans[0]) ans=s[i]+ans;
			else ans+=s[i];
		}

		printf("Case #%d: ", i);
		cout<<ans<<'\n';
	}

	return 0;
}
