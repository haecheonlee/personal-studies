#include <iostream>

using namespace std;

int main() {
	string s;
	cin>>s;

	int L=(int)s.size();
	
	int cnt=0;
	for(int i=0; i<L/2; i++) if(s[i]!=s[L - 1 - i]) cnt++;
	
	if(cnt==1 || (cnt==0 && L%2)) cout<<"YES";
	else cout<<"NO";

	return 0;
}
