/* reference: https://mizzo-dev.tistory.com/entry/baekjoon2011 */

#include <iostream>

using namespace std;

const int MOD=1e6;

int d[5005];

int main() {
	string s;
	cin>>s;
	
	d[0]=d[1]=1;
	
	bool is_possible=(s[0]!='0');
	for(int i=2; i<=s.size(); i++) {
		int now=i-1;
		if(s[now-1]=='0' && s[now]=='0') is_possible=false;
		
		if(s[now]>'0') d[i]=d[i-1];
		
		int num=(10*(s[now-1]-'0'))+(s[now]-'0');
		if(num>=10 && num<=26) d[i]=(d[i]+d[i-2])%MOD;
	}

	if(is_possible) cout<<d[s.size()];
	else cout<<0;

	return 0;
}
