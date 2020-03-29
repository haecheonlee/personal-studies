#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> preprocessing(string p) {
	int m=p.size(), j=0;
	vector<int> pi(m);
	pi[0]=0;
	
	for(int i=1; i<m; i++) {
		while(j>0 && p[i]!=p[j]) j=pi[j-1];
		if(p[i]==p[j]) {
			pi[i]=j+1;
			j+=1;
		} else {
			pi[i]=0;
		}
	}
	
	return pi;
}

int main() {
	string s,a;
	cin>>s;
	reverse(s.begin(), s.end());
	
	int ans=0;
	for(char c : s) {
		a=c+a;
		vector<int> next=preprocessing(a);
		for(int i=0; i<next.size(); i++) {
			if(ans<next[i]) ans=next[i];
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}

/*
INPUT:
abcdabcabb

OUTPUT:
3
*/
