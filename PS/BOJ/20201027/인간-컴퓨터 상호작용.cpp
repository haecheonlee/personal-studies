#include <iostream>

using namespace std;

const int MAX=2e5+1;

int a[26][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin>>s;

	int Q;
	cin>>Q;

	for(int i=0; i<s.size(); i++) {
		int idx=s[i]-'a';
		a[idx][i]++;
		 
		if(i!=0) {
			for(int j=0; j<26; j++) a[j][i]+=a[j][i-1];	
		}
	}

	while(Q--) {
		char x;
		int L,R;
		cin>>x>>L>>R;
		
		cout<<a[x-'a'][R] - a[x-'a'][L-1]<<'\n';
	}

	return 0;
}
