#include <iostream>

using namespace std;

int solve() {
	int count[26] {0};
	
	string s;
	getline(cin,s);
	
	for(auto &c : s) {
		if(c>='a' && c<='z') count[c-'a']++;
		else if(c>='A' && c<='Z') count[(char)tolower(c)-'a']++;
	}

	int ans=1e9;
	for(int i=0; i<26; i++) ans=min(ans,count[i]);
	
	return ans;	
}

int main() {
	int T;
	cin>>T;

	cin.ignore();
	for(int i=1; i<=T; i++) {
		int ans=solve();
		
		printf("Case %d: ", i);
		if(ans==0) printf("Not a pangram");
		else if(ans==1) printf("Pangram!");
		else if(ans==2) printf("Double pangram!!");
		else if(ans==3) printf("Triple pangram!!!");
		printf("\n");
	}

	return 0;
}
