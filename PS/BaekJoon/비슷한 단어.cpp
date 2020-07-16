#include <iostream>

using namespace std;

int s_alph[26] {0};

bool check(const string &s, const string &w) {
	int len_diff=abs((int)s.size()-(int)w.size());
	// check if same string
	if(len_diff<=1) {
		// check if they have same number of alphabets
		int w_alph[26] {0};
		for(int i=0; i<w.size(); i++) w_alph[w[i]-'A']++;
	
		int diff=0;
		for(int i=0; i<26; i++) diff+=abs(s_alph[i] - w_alph[i]);
		
        // 0: same, 1: one difference, 2: change alphabet
		return diff<=2;
	}
    
    return false;
}

int main() {
	int N;
	cin>>N;
	
	string s,w;
	cin>>s;

	for(int i=0; i<s.size(); i++) s_alph[s[i]-'A']++;

	int ans=0;
	for(int i=0; i<N-1; i++) {
		cin>>w;
		if(check(s,w)) ans++;
	}
	cout<<ans;
	
	return 0;
}
