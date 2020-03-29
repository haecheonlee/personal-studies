#include <iostream>
#include <vector>

using namespace std;

vector<int> preprocessing(string p) {
	int m=p.size();
	vector<int> fail(m);
	fail[0]=0;
	
	int j=0;
	for(int i=1; i<m; i++) {
		while(j>0 && p[i]!=p[j]) j=fail[j-1];
		if(p[i]==p[j]) fail[i]=++j;
		else fail[i]=0;
	}
	
	return fail;
}

vector<int> kmp(string s, string p) {
	auto fail=preprocessing(p);
	vector<int> ans;
	
	int n=s.size(), m=p.size(), j=0;
	for(int i=0; i<n; i++) {
		while(j>0 && s[i]!=p[j]) j=fail[j-1];
		if(s[i]==p[j]) {
			if(j==m-1) {
				ans.push_back(i-m+1);
				j=fail[j];
			} else {
				j++;
			}
		}
	}
	
	return ans;
}

int main() {
	string s,p;
	getline(cin,s);
	getline(cin,p);

	vector<int> ans=kmp(s,p);
	cout<<ans.size()<<"\n";
	for(auto &idx : ans) cout<<idx+1<<"\n";
	
	return 0;
}

/*
INPUT:
ABC ABCDAB ABCDABCDABDE
ABCDABD

OUTPUT:
1
16
*/
