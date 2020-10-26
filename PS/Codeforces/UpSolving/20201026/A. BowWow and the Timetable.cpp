#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string s;
	cin>>s;

	reverse(s.begin(), s.end());

	int ans=0, one=0;
	int L=(int)s.size();
	for(int i=0; i<L; i++) {
		if(i%2==0) {
			if(i<L-1) ans++;
			else if(i==L-1 && one) ans++; 
		}
		if(s[i]=='1') one++;
	}
	cout<<ans;

	return 0;
}
