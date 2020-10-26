#include <iostream>

using namespace std;

int main() {
	string s;
	cin>>s;

	int L=s.size();
	s = 's' + s + 'e';
	
	int ans=0, prev=0;
	for(int i=1; i<=L; i++) {
		if(s[i]=='A' || s[i]=='E' || s[i]=='I' || 
		   s[i]=='O' || s[i]=='U' || s[i]=='Y') {
			ans=max(ans, i - prev);
			prev=i;
		}
	}
	
	if(prev==0) ans=L+1;
	else ans=max(ans, L - prev + 1);

	cout<<ans;

	return 0;
}
